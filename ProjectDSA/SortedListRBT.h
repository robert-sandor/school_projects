//
// Created by robert on 6/1/15.
//

#ifndef PROJECTDSA_SORTEDLISTRBT_H
#define PROJECTDSA_SORTEDLISTRBT_H

#include "cstdlib"
#include "abstract_data_types.h"

template < typename TElem >
class SortedListRBT : ASortedList < TElem > {
public:
    enum Color {
        RED, BLACK
    };

    class iterator : public AIterator < TElem > {
    public:
        iterator () { }

        iterator ( TElem *ptr ) {
            this->_current = ptr;
        }

        virtual ~iterator () { }

        virtual SortedListRBT::iterator & operator= ( const AIterator < TElem > & other ) override;

        SortedListRBT::iterator & operator= ( const SortedListRBT::iterator & other );

        virtual bool operator== ( const AIterator < TElem > & other ) const override;

        virtual bool operator!= ( const AIterator < TElem > & other ) const override;

        virtual SortedListRBT::iterator & operator++ () override;

        virtual SortedListRBT::iterator & operator-- () override;

        virtual SortedListRBT::iterator & operator+ ( const int & value ) override;

        virtual SortedListRBT::iterator & operator- ( const int & value ) override;

        virtual TElem & operator* () const override;

        virtual void next () override;

        virtual void prev () override;
    };

private:
    class Node {
    public:
        Node ( TElem _data, const Color & _color, Node *_parent, Node *_left, Node *_right ) : _data ( _data ),
                                                                                               _color ( _color ),
                                                                                               _parent ( _parent ),
                                                                                               _left ( _left ),
                                                                                               _right ( _right ) { }

        Node () { }

        TElem data () const {
            return _data;
        }

        void set_data ( TElem _data ) {
            Node::_data = _data;
        }

        Node *left () const {
            return _left;
        }

        void set_left ( Node *_left ) {
            Node::_left = _left;
        }

        Node *right () const {
            return _right;
        }

        void set_right ( Node *_right ) {
            Node::_right = _right;
        }

        const Color & color () const {
            return _color;
        }

        void set_color ( const Color & _color ) {
            Node::_color = _color;
        }

        Node *parent () const {
            return _parent;
        }

        void set_parent ( Node *_parent ) {
            Node::_parent = _parent;
        }

    private:
        TElem _data;
        Color _color;
        Node *_parent;
        Node *_left;
        Node *_right;
    };

public:
    SortedListRBT () {
        _root = nullptr;
    }

    virtual ~SortedListRBT () { }

//    virtual TElem & get_at_index ( const unsigned int & index ) const override;

    virtual void add ( const TElem & element ) override;

    virtual void remove_from_index ( const unsigned int & index ) override;

    virtual unsigned int get_index ( const TElem & element ) override;

    virtual unsigned int get_count () const override;

    virtual bool is_empty () const override;

    Node *get_root () const {
        return _root;
    }

private:
    void left_rotate ( Node *pt );

    void right_rotate ( Node *pt );

    void fix_up ( Node *x );

private:
    Node *_root;
    Node *_begin;
    Node *_end;


};

/*
 * --------------------------------------------------------------------------------------------------------------------|
 * SortedListRBT methods
 * --------------------------------------------------------------------------------------------------------------------|
 */

//template < typename TElem >
//TElem & SortedListRBT < TElem >::get_at_index ( const unsigned int & index ) const {
//    return this->_root->data ();
//}

template < typename TElem >
void SortedListRBT < TElem >::add ( const TElem & element ) {
    Node *root = this->_root;
    Node *pred = nullptr;

    while ( root != nullptr ) {
        pred = root;

        if ( root->data () > element ) {
            root = root->left ();
        }
        else if ( root->data () < element ) {
            root = root->right ();
        }
    }

    Node *n = new Node ( element, RED, pred, nullptr, nullptr );

    if ( pred == nullptr ) {
        this->_root = n;
        this->_root->set_color ( BLACK );
    }
    else {
        if ( element < pred->data ()) {
            pred->set_left ( n );
        }
        else {
            pred->set_right ( n );
        }

        fix_up ( n );
    }
}

template < typename TElem >
void SortedListRBT < TElem >::remove_from_index ( const unsigned int & index ) {

}

template < typename TElem >
unsigned int SortedListRBT < TElem >::get_index ( const TElem & element ) {
    return 0;
}

template < typename TElem >
unsigned int SortedListRBT < TElem >::get_count () const {
    return 0;
}

template < typename TElem >
bool SortedListRBT < TElem >::is_empty () const {
    return false;
}

template < typename TElem >
void SortedListRBT < TElem >::left_rotate ( SortedListRBT < TElem >::Node *pt ) {
    // y stores pointer of the right child of x
    Node *pt_right = pt->right ();

    // store y's left subtree's pointer as x's right child
    pt->set_right ( pt_right->left ());

    // update parent pointer of x's right child
    if ( pt->right () != nullptr ) {
        pt->right ()->set_parent ( pt );
    }

    // update y's parent pointer
    pt_right->set_parent ( pt->parent ());

    // if x's parent is nullptr make y root
    if ( pt->parent () == nullptr ) {
        this->_root = pt_right;
    }
        // store y at the place of x
    else if ( pt == pt->parent ()->left ()) {
        pt->parent ()->set_left ( pt_right );
    }
    else {
        pt->parent ()->set_right ( pt_right );
    }

    // make x the right child of y
    pt_right->set_left ( pt );

    // make y the parent of x
    pt->set_parent ( pt_right );
}

template < typename TElem >
void SortedListRBT < TElem >::right_rotate ( SortedListRBT < TElem >::Node *pt ) {
    // x stores pointer to the left child of y
    Node *pt_left = pt->left ();

    // store x's right subtree's pointer as y's left child
    pt->set_left ( pt_left->right ());

    // update parent pointer of x's right child
    if ( pt->left () != nullptr ) {
        pt->left ()->set_parent ( pt );
    }

    // update x's parent pointer
    pt_left->set_parent ( pt->parent ());

    // if x's parent is nullptrptr make it root
    if ( pt->parent () == nullptr ) {
        this->_root = pt_left;
    }
        // store x at the place of y
    else if ( pt == pt->parent ()->left ()) {
        pt->parent ()->set_left ( pt_left );
    }
    else {
        pt->parent ()->set_right ( pt_left );
    }

    // make y the right child of x
    pt_left->set_right ( pt );

    // make x the parent of y
    pt->set_parent ( pt_left );
}

template < typename TElem >
void SortedListRBT < TElem >::fix_up ( SortedListRBT < TElem >::Node *pt ) {
    Node *parent_pt = nullptr;
    Node *grand_parent_pt = nullptr;

    while (( pt != this->_root ) && ( pt->color () != BLACK ) && ( pt->parent ()->color () == RED )) {
        parent_pt = pt->parent ();
        grand_parent_pt = pt->parent ()->parent ();

        // case A

        if ( parent_pt == grand_parent_pt->left ()) {
            Node *uncle_pt = grand_parent_pt->right ();

            // case 1

            if ( uncle_pt != nullptr && uncle_pt->color () == RED ) {
                grand_parent_pt->set_color ( RED );
                parent_pt->set_color ( BLACK );
                uncle_pt->set_color ( BLACK );
                pt = grand_parent_pt;
            }

            else {
                // case 2
                if ( pt == parent_pt->right ()) {
                    left_rotate ( parent_pt );
                    pt = parent_pt;
                    parent_pt = pt->parent ();
                }

                // case 3
                right_rotate ( grand_parent_pt );
                Color c = grand_parent_pt->color ();
                grand_parent_pt->set_color ( parent_pt->color ());
                parent_pt->set_color ( c );
                pt = parent_pt;
            }
        }

            // case B

        else {
            Node *uncle_pt = grand_parent_pt->left ();

            // case 1

            if (( uncle_pt != nullptr ) && ( uncle_pt->color () == RED )) {
                grand_parent_pt->set_color ( RED );
                parent_pt->set_color ( BLACK );
                uncle_pt->set_color ( BLACK );
                pt = grand_parent_pt;
            }

                // case 2

            else {
                if ( pt == parent_pt->left ()) {
                    right_rotate ( parent_pt );
                    pt = parent_pt;
                    parent_pt = pt->parent ();
                }

                // case 3
                left_rotate ( grand_parent_pt );
                Color c = grand_parent_pt->color ();
                grand_parent_pt->set_color ( parent_pt->color ());
                parent_pt->set_color ( c );
                pt = parent_pt;
            }
        }
    }

    this->_root->set_color ( BLACK );
}

/*
 * --------------------------------------------------------------------------------------------------------------------|
 * Iterator methods
 * --------------------------------------------------------------------------------------------------------------------|
 */

template < typename TElem >
typename SortedListRBT < TElem >::iterator & SortedListRBT < TElem >::iterator::operator= (
        const AIterator < TElem > & other ) {
    return *this;
}

template < typename TElem >
bool SortedListRBT < TElem >::iterator::operator== ( const AIterator < TElem > & other ) const {
    return false;
}

template < typename TElem >
bool SortedListRBT < TElem >::iterator::operator!= ( const AIterator < TElem > & other ) const {
    return false;
}

template < typename TElem >
typename SortedListRBT < TElem >::iterator & SortedListRBT < TElem >::iterator::operator++ () {
    return *this;
}

template < typename TElem >
typename SortedListRBT < TElem >::iterator & SortedListRBT < TElem >::iterator::operator-- () {
    return *this;
}

template < typename TElem >
typename SortedListRBT < TElem >::iterator & SortedListRBT < TElem >::iterator::operator+ ( const int & value ) {
    return *this;
}

template < typename TElem >
typename SortedListRBT < TElem >::iterator & SortedListRBT < TElem >::iterator::operator- ( const int & value ) {
    return *this;
}

template < typename TElem >
TElem & SortedListRBT < TElem >::iterator::operator* () const {
    return *this->_current;
}

template < typename TElem >
void SortedListRBT < TElem >::iterator::next () {

}

template < typename TElem >
void SortedListRBT < TElem >::iterator::prev () {

}

template < typename TElem >
typename SortedListRBT < TElem >::iterator & SortedListRBT < TElem >::iterator::operator= (
        const SortedListRBT::iterator & other ) {
    this->_current = other.get_current ();
    return *this;
}

#endif //PROJECTDSA_SORTEDLISTRBT_H

