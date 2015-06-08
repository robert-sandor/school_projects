//
// Created by robert on 6/4/15.
//

#include <stdexcept>
#include "adt.h"
#include "sorted_list_dv.h"

#ifndef SDA_PROJECT_NEW_SORTED_LIST_RBT_H
#define SDA_PROJECT_NEW_SORTED_LIST_RBT_H

template<typename TComparable>
class SortedListRBT : public AbstractSortedList<TComparable> {
private:
    class Node {
    public:

        Node(TComparable data) : data(data) {
            red = 1;
            link[0] = link[1] = parent = nullptr;
        }

        virtual ~Node() { }

        int red; // 1 - if red, 0 - if black
        TComparable data;
        Node *link[2]; // 0 - left child, 1 - right child
        Node *parent;
    };

    Node *_root;

    int is_red(Node *root) {
        return (root != nullptr) && root->red == 1;
    }

    Node *insert_r(Node *root, const TComparable &data);

    Node *remove_r(Node *root, TComparable data, int *done);

    Node *remove_balance(Node *root, int dir, int *done);

    int rb_assert(Node *root);

    Node *single_rotation(Node *root, int dir) {
        // single rotation in the direction dir
        Node *save = root->link[!dir];

        root->link[!dir] = save->link[dir];
        if (save->link[dir] != nullptr) {
            save->link[dir]->parent = root;
        }

        save->link[dir] = root;
        save->parent = root->parent;
        root->parent = save;

        root->red = 1;
        save->red = 0;

        return save;
    }

    Node *double_rotation(Node *root, int dir) {
        // two single rotations
        // first in the direction dir
        root->link[!dir] = single_rotation(root->link[!dir], !dir);

        // the other in the opposite direction
        return single_rotation(root, dir);
    }

public:
    class iterator : public AbstractIterator<TComparable> {
    public:
        iterator() {
            this->_current = nullptr;
        }

        iterator(const SortedListRBT<TComparable>::iterator &other) {
            _cn = other._cn;
            if (_cn != nullptr)
                this->_current = &_cn->data;
        }

        virtual ~iterator() { }

        virtual void next();

        virtual TComparable element() const;

        virtual bool equal(const AbstractIterator<TComparable> &other) const;

    private:

        iterator(Node *cn) : _cn(cn) {
            if (_cn == nullptr)
                this->_current = nullptr;
            else
                this->_current = &_cn->data;
        }

        Node *_cn;
        SortedListDV<Node *> _visited;

        friend class SortedListRBT<TComparable>;
    };

public:

    SortedListRBT() {
        _root = nullptr;
        this->_element_count = 0;
    }

    virtual ~SortedListRBT() { }

    virtual bool is_empty() const;

    virtual unsigned int get_count() const;

    virtual void insert(const TComparable &element);

    virtual void remove(const TComparable &element);

    virtual bool contains(const TComparable &element);

    iterator begin() const;

    iterator end() const;


};

template<typename TComparable>
bool SortedListRBT<TComparable>::is_empty() const {
    return this->_element_count == 0;
}

template<typename TComparable>
unsigned int SortedListRBT<TComparable>::get_count() const {
    return this->_element_count;
}

template<typename TComparable>
void SortedListRBT<TComparable>::insert(const TComparable &element) {
    // insert element recursively
    _root = insert_r(_root, element);

    // set root's color to black
    // and parent to null
    _root->red = 0;
    _root->parent = nullptr;

    this->_element_count += 1;
//    rb_assert(_root);
}

template<typename TComparable>
void SortedListRBT<TComparable>::remove(const TComparable &element) {
    // throw error if there is no element to remove
    if (!contains(element)) {
        throw std::runtime_error("Element not found!");
    }

    // a signal that we are done rebalancing
    // add recursively and rebalance on the run
    int done = 0;
    _root = remove_r(_root, element, &done);

    // if we still have a root
    // set color to black and parent to null
    if (_root != nullptr) {
        _root->red = 0;
        _root->parent = NULL;
    }

    // decrease the element count
    this->_element_count -= 1;

//    rb_assert(_root);
}

template<typename TComparable>
bool SortedListRBT<TComparable>::contains(const TComparable &element) {
    Node *root = _root;

    // just a simple binary search...
    while (root != nullptr) {
        if (root->data == element) {
            return true;
        }

        if (root->data > element) {
            root = root->link[0];
        }
        else {
            root = root->link[1];
        }
    }

    return false;
}

template<typename TComparable>
typename SortedListRBT<TComparable>::Node *SortedListRBT<TComparable>::insert_r(
        SortedListRBT<TComparable>::Node *root, const TComparable &data) {

    if (root == nullptr) {
        // if the root is null, we just add the node
        root = new SortedListRBT<TComparable>::Node(data);
    }
    else {
        // otherwise, we choose the direction to which we move on
        int dir = root->data < data;

        // insert recursively
        root->link[dir] = insert_r(root->link[dir], data);
        // make sure child's parent gets updated
        root->link[dir]->parent = root;

        // if the newly added node is red
        if (is_red(root->link[dir])) {
            // if the other child os also red
            if (is_red(root->link[!dir])) {
                // case 1 : color change
                root->red = 1;
                root->link[0]->red = 0;
                root->link[1]->red = 0;
            }
            else {
                // case 2 : single rotation
                // we have a red node on the same direction
                if (is_red(root->link[dir]->link[dir])) {
                    root = single_rotation(root, !dir);
                }
                else if (is_red(root->link[dir]->link[!dir])) {
                    // case 3 : double rotation
                    // we have a red node on the other direction
                    root = double_rotation(root, !dir);
                }
            }
        }
    }

    return root;
}

template<typename TComparable>
typename SortedListRBT<TComparable>::Node *SortedListRBT<TComparable>::remove_r(
        SortedListRBT<TComparable>::Node *root, TComparable data, int *done) {

    // if the root is null we are finished
    if (root == nullptr) {
        *done = 1;
    }
    else {
        int dir;

        if (root->data == data) {
            // if one of the children is null
            if (root->link[0] == nullptr || root->link[1] == nullptr) {
                // save the other child
                Node *save = root->link[root->link[0] == nullptr];

                // update its parent
                if (save != nullptr) {
                    save->parent = root->parent;
                }

                // if the root is red, we are done
                if (is_red(root)) {
                    *done = 1;
                }
                else if (is_red(save)) {
                    // if not, then the saved node must be black
                    save->red = 0;
                    *done = 1;
                }

                delete root;
                return save;
            }
            else {
                // if we have both non null children
                // we take the rightmost node in the left subtree
                Node *heir = root->link[0];
                while (heir->link[1] != nullptr) {
                    heir = heir->link[1];
                }

                // we exchange data and move on
                root->data = heir->data;
                data = heir->data;
            }

        }

        // we choose the direction we have to go next
        dir = root->data < data;
        root->link[dir] = remove_r(root->link[dir], data, done);

        // if we are still not done, we have to rebalance the tree
        if (!*done) {
            root = remove_balance(root, dir, done);
        }
    }

    return root;
}

template<typename TComparable>
typename SortedListRBT<TComparable>::Node *SortedListRBT<TComparable>::remove_balance(
        SortedListRBT<TComparable>::Node *root, int dir, int *done) {

    Node *p = root;
    Node *s = root->link[!dir];

    // if s is not a leaf but it is black
    if (s != nullptr && !is_red(s)) {
        // if both its children are black
        if (!is_red(s->link[0]) && !is_red(s->link[1])) {
            // if also s' parent p is red, we are done
            if (is_red(p)) {
                *done = 1;
            }

            // we set p to be black and s to be red
            p->red = 0;
            s->red = 1;
        }
        else {
            // save the color of the root
            int save = root->red;

            // decide on a single or double rotation
            if (is_red(s->link[!dir])) {
                p = single_rotation(p, dir);
            }
            else {
                p = double_rotation(p, dir);
            }

            // assign the saved color
            p->red = save;
            // and set p's children to be black
            p->link[0]->red = 0;
            p->link[1]->red = 0;
            // we are done
            *done = 1;
        }
    }
        // if s is red and has a child that is not null
    else if (s->link[dir] != nullptr) {
        // save that child
        Node *r = s->link[dir];

        // if both of r's children are black
        if (!is_red(r->link[0]) && !is_red(r->link[1])) {
            // perform a single rotation
            p = single_rotation(p, dir);
            p->link[dir]->link[!dir]->red = 1;
        }
        else {
            if (is_red(r->link[dir])) {
                s->link[dir] = single_rotation(r, !dir);
            }

            p = double_rotation(p, dir);
            s->link[dir]->red = 0;
            p->link[dir]->red = 1;
        }

        p->red = 0;
        p->link[dir]->red = 0;
        *done = 1;
    }

    return p;
}

template<typename TComparable>
int SortedListRBT<TComparable>::rb_assert(SortedListRBT<TComparable>::Node *root) {
    int lh, rh;

    if (root == nullptr) {
        return 1;
    }
    else {
        Node *ln = root->link[0];
        Node *rn = root->link[1];

        if (is_red(root)) {
            if (is_red(ln) || is_red(rn)) {
                throw std::runtime_error("Red violation!");
            }
        }

        lh = rb_assert(ln);
        rh = rb_assert(rn);

        if ((ln != nullptr && ln->parent != root) || (rn != nullptr && rn->parent != root)) {
            throw std::runtime_error("Parent violation!");
        }

        if ((ln != nullptr && ln->data > root->data) || (rn != nullptr && rn->data < root->data)) {
            throw std::runtime_error("Binary search tree violation!");
        }

        if (lh != 0 && rh != 0 && lh != rh) {
            throw std::runtime_error("Black violation!");
        }

        if (lh != 0 && rh != 0) {
            return is_red(root) ? lh : lh + 1;
        }
        else {
            return 0;
        }
    }
}

template<typename TComparable>
void SortedListRBT<TComparable>::iterator::next() {
    _visited.insert(_cn);

    if (_cn->link[1] != nullptr) {
        _cn = _cn->link[1];

        while (_cn->link[0] != nullptr) {
            _cn = _cn->link[0];
        }

        this->_current = &_cn->data;
//        _visited.insert(_cn);
        return;
    }

    while (_visited.contains(_cn)) {
        _cn = _cn->parent;
    }

    if (_cn == nullptr) {
        this->_current = nullptr;
        return;
    }

    this->_current = &_cn->data;
//    _visited.insert(_cn);
}

template<typename TComparable>
TComparable SortedListRBT<TComparable>::iterator::element() const {
    return *this->_current;
}

template<typename TComparable>
bool SortedListRBT<TComparable>::iterator::equal(const AbstractIterator<TComparable> &other) const {
    return this->_current == other.get_current();
}

template<typename TComparable>
typename SortedListRBT<TComparable>::iterator SortedListRBT<TComparable>::begin() const {
    Node *n = _root;

    while (n != nullptr && n->link[0] != nullptr) {
        n = n->link[0];
    }

    return SortedListRBT<TComparable>::iterator(n);
}

template<typename TComparable>
typename SortedListRBT<TComparable>::iterator SortedListRBT<TComparable>::end() const {
    return SortedListRBT<TComparable>::iterator(nullptr);
}

#endif //SDA_PROJECT_NEW_SORTED_LIST_RBT_H
