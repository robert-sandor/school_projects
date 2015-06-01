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
    SortedListRBT () {
        _root = NULL;
    }

    virtual ~SortedListRBT () { }

    virtual TElem & get_at_index ( const unsigned int & index ) const override;

    virtual void add ( const TElem & element ) override;

    virtual void remove_from_index ( const unsigned int & index ) override;

    virtual unsigned int get_index ( const TElem & element ) override;

    virtual unsigned int get_count () const override;

    virtual bool is_empty () const override;

    Node *get_root () const {
        return _root;
    }

private:
    void left_rotate ( Node *x );

    void right_rotate ( Node *x );

    void fix_up ( Node *x );

private:
    Node *_root;
    Node *_begin;
    Node *_end;

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
};

/*
 * --------------------------------------------------------------------------------------------------------------------|
 * SortedListRBT methods
 * --------------------------------------------------------------------------------------------------------------------|
 */

template < typename TElem >
TElem & SortedListRBT < TElem >::get_at_index ( const unsigned int & index ) const {
    return <#initializer#>;
}

template < typename TElem >
void SortedListRBT < TElem >::add ( const TElem & element ) {
    Node *root = this->_root;
    Node *pred = NULL;

    while ( root != NULL ) {
        pred = root;

        if ( root->data () > element ) {
            root = root->left ();
        }
        else if ( root->data () < element ) {
            root = root->right ();
        }
    }

    Node *n = new Node ( element, RED, pred, NULL, NULL );

    if ( pred == NULL ) {
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
void SortedListRBT < TElem >::left_rotate ( SortedListRBT < TElem >::Node *x ) {
    // y stores pointer of the right child of x
    Node *y = x->right ();

    // store y's left subtree's pointer as x's right child
    x->set_right ( y->left ());

    // update parent pointer of x's right child
    if ( x->right () != NULL ) {
        x->right ()->set_parent ( x );
    }

    // update y's parent pointer
    y->set_parent ( x->parent ());

    // if x's parent is NULL make y root
    if ( x->parent () == NULL ) {
        this->_root = y;
    }
        // store y at the place of x
    else if ( x == x->parent ()->left ()) {
        x->parent ()->set_left ( y );
    }
    else {
        x->parent ()->set_right ( y );
    }

    // make x the right child of y
    y->set_left ( x );

    // make y the parent of x
    x->set_parent ( y );
}

template < typename TElem >
void SortedListRBT < TElem >::right_rotate ( SortedListRBT < TElem >::Node *y ) {
    // x stores pointer to the left child of y
    Node *x = y->left ();

    // store x's right subtree's pointer as y's left child
    y->set_left ( x->right ());

    // update parent pointer of x's right child
    if ( x->right () != NULL ) {
        x->right ()->set_parent ( y );
    }

    // update x's parent pointer
    x->parent ()->set_parent ( y );

    // if x's parent is NULL make it root
    if ( x->parent () == NULL ) {
        this->_root = x;
    }
        // store x at the place of y
    else if ( y->parent () == y->parent ()->left ()) {
        y->parent ()->set_left ( x );
    }
    else {
        y->parent ()->set_right ( x );
    }

    // make y the right child of x
    x->set_right ( y );

    // make x the parent of y
    y->set_parent ( x );
}

template < typename TElem >
void SortedListRBT < TElem >::fix_up ( SortedListRBT < TElem >::Node *z ) {
    // iterate until z is not the root and z's parent color is red
    while ( z != this->_root && z->parent ()->color () == RED ) {
        Node *y;

        // Find uncle and store it in y
        if ( z->parent () == z->parent ()->parent ()->left ()) {
            y = z->parent ()->parent ()->right ();
        }
        else {
            y = z->parent ()->parent ()->left ();
        }

        // If uncle is red, do
        // 1 - change color of parent and uncle to BLACK
        // 2 - Change color of grandparent to RED
        // 3 - Move z to grandparent
        if ( y->color () == RED ) {
            y->set_color ( BLACK );
            z->parent ()->set_color ( BLACK );
            z->parent ()->parent ()->set_color ( RED );
            z = z->parent ()->parent ();
        }
            // Uncle is BLACK, there are four cases
        else {
            // left-left case : do
            // 1 - swap color of parent and grandparent
            // 2 - right rotate grandparent
            if ( z->parent () == z->parent ()->parent ()->left () && z == z->parent ()->left ()) {
                Color c = z->parent ()->color ();
                z->parent ()->set_color ( z->parent ()->parent ()->color ());
                z->parent ()->parent ()->set_color ( c );
                right_rotate ( z->parent ()->parent ());
            }

            // left-right case : do
            // 1 - swap color of current node and grandparent
            // 2 - left rotate grandparent
            // 3 - right rotate grandparent
            if ( z->parent () == z->parent ()->parent ()->left () && z == z->parent ()->right ()) {
                Color c = z->color ();
                z->set_color ( z->parent ()->parent ()->color ());
                z->parent ()->parent ()->set_color ( c );
                left_rotate ( z->parent ());
                right_rotate ( z->parent ()->parent ());
            }

            // right-right case : do
            // 1 - swap color of parent and grandparent
            // 2 - left rotate grandparent
            if ( z->parent () == z->parent ()->parent ()->right () && z == z->parent ()->right ()) {
                Color c = z->parent ()->color ();
                z->parent ()->set_color ( z->parent ()->parent ()->color ());
                z->parent ()->parent ()->set_color ( c );
                left_rotate ( z->parent ()->parent ());
            }

            // right-left case : do
            // 1 - swap color of current node and grandparent
            // 2 - right rotate parent
            // 3 - left rotate grandparent
            if ( z->parent () == z->parent ()->parent ()->right () && z == z->parent ()->left ()) {
                Color c = z->color ();
                z->set_color ( z->parent ()->parent ()->color ());
                z->parent ()->parent ()->set_color ( c );
                right_rotate ( z->parent ());
                left_rotate ( z->parent ()->parent ());
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
SortedListRBT < TElem >::iterator & SortedListRBT < TElem >::iterator::operator= ( const AIterator < TElem > & other ) {
    return <#initializer#>;
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
SortedListRBT < TElem >::iterator & SortedListRBT < TElem >::iterator::operator++ () {
    return <#initializer#>;
}

template < typename TElem >
SortedListRBT < TElem >::iterator & SortedListRBT < TElem >::iterator::operator-- () {
    return <#initializer#>;
}

template < typename TElem >
SortedListRBT < TElem >::iterator & SortedListRBT < TElem >::iterator::operator+ ( const int & value ) {
    return <#initializer#>;
}

template < typename TElem >
SortedListRBT < TElem >::iterator & SortedListRBT < TElem >::iterator::operator- ( const int & value ) {
    return <#initializer#>;
}

template < typename TElem >
TElem & SortedListRBT < TElem >::iterator::operator* () const {
    return <#initializer#>;
}

template < typename TElem >
void SortedListRBT < TElem >::iterator::next () {

}

template < typename TElem >
void SortedListRBT < TElem >::iterator::prev () {

}

template < typename TElem >
SortedListRBT < TElem >::iterator & SortedListRBT < TElem >::iterator::operator= (
        const SortedListRBT::iterator & other ) {
    this->_current = other.get_current ();
    return *this;
}

#endif //PROJECTDSA_SORTEDLISTRBT_H

