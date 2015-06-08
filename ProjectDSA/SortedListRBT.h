//
// Created by robert on 6/1/15.
//

#ifndef PROJECTDSA_SORTEDLISTRBT_H
#define PROJECTDSA_SORTEDLISTRBT_H

#include "abstract_data_types.h"

template < typename TComparable >
class SortedListRBT : ASortedList < TComparable > {
public:
    class iterator : AIterator < TComparable > {
    public:
        iterator (SortedListRBT < TComparable >::Node * root) : _root (root) {}

        virtual ~iterator ( );

        virtual AIterator & operator= ( const AIterator & other );

        virtual bool operator== ( const AIterator & other ) const;

        virtual bool operator!= ( const AIterator & other ) const;

        virtual AIterator & operator++ ();

        virtual AIterator & operator+ ( const int & value );

        virtual TComparable & operator* () const;

        virtual void next ();

        virtual TComparable *get_current () const {
            return this->_current;
        }

    private:
        SortedListRBT < TComparable >::Node *_root;
        SortedListRBT < TComparable >::Node *_cn;
        SortedListDV < Node * > _visited;
    };

private:
    enum Color {
        BLACK = 0, RED = 1
    };

    class Node {
    public:
        Node ( TComparable data ) : data ( data ) {
            red = RED;
            link[ 0 ] = link[ 1 ] = nullptr;
        }

        virtual ~Node () { }

        Color red;
        TComparable data;
        Node *link[2];
    };

public:

    SortedListRBT () {
        _root = nullptr;
    }

    virtual ~SortedListRBT () { }

    virtual void add ( const TComparable & element ) override;

    virtual void remove ( const TComparable & element ) override;

    virtual unsigned int get_count () const override;

    virtual bool is_empty () const override;

    Node *get_root () const {
        return _root;
    }

private:
    Node *_root;

    int is_red ( Node *root ) {
        return root != NULL && root->red == 1;
    }

    Node *insert_r ( Node *root, const TComparable & data );

    Node *remove_r ( Node *root, TComparable data, int *done );

    Node *remove_balance ( Node *root, int dir, int *done );

    int rb_assert ( Node *root );

    Node *single_rotation ( Node *root, int dir ) {
        Node *save = root->link[ !dir ];

        root->link[ !dir ] = save->link[ dir ];
        save->link[ dir ] = root;

        root->red = RED;
        save->red = BLACK;

        return save;
    }

    Node *double_rotation ( Node *root, int dir ) {
        root->link[ !dir ] = single_rotation ( root->link[ !dir ], !dir );

        return single_rotation ( root, dir );
    }
};

template < typename TComparable >
void SortedListRBT < TComparable >::add ( const TComparable & element ) {
    this->_root = insert_r ( this->_root, element );
    this->_root->red = BLACK;

    rb_assert ( this->_root );
}

template < typename TComparable >
void SortedListRBT < TComparable >::remove ( const TComparable & element ) {
    int done = 0;

    this->_root = remove_r ( this->_root, element, &done );

    if ( this->_root != nullptr ) {
        this->_root->red = BLACK;
    }
}

template < typename TComparable >
typename SortedListRBT < TComparable >::Node *SortedListRBT < TComparable >::insert_r (
        SortedListRBT < TComparable >::Node *root, const TComparable & data ) {

    if ( root == nullptr ) {
        root = new SortedListRBT < TComparable >::Node ( data );
    }
    else {
        int dir = root->data < data;

        root->link[ dir ] = insert_r ( root->link[ dir ], data );

        if ( is_red ( root->link[ dir ] )) {
            if ( is_red ( root->link[ !dir ] )) {
                root->red = RED;
                root->link[ 0 ]->red = BLACK;
                root->link[ 1 ]->red = BLACK;
            }
            else {
                if ( is_red ( root->link[ dir ]->link[ dir ] )) {
                    root = single_rotation ( root, !dir );
                }
                else if ( is_red ( root->link[ dir ]->link[ !dir ] )) {
                    root = double_rotation ( root, !dir );
                }
            }
        }
    }

    return root;
}

template < typename TComparable >
typename SortedListRBT < TComparable >::Node *SortedListRBT < TComparable >::remove_r (
        SortedListRBT < TComparable >::Node *root, TComparable data, int *done ) {

    if ( root == nullptr ) {
        *done = 1;
    }
    else {
        int dir;

        if ( root->data == data ) {
            if ( root->link[ 0 ] == nullptr || root->link[ 1 ] == nullptr ) {
                Node *save = root->link[ root->link[ 0 ] == nullptr ];

                if ( is_red ( root )) {
                    *done = 1;
                }
                else if ( is_red ( save )) {
                    save->red = BLACK;
                    *done = 1;
                }

                delete root;
                return save;
            }
            else {
                Node *heir = root->link[ 0 ];

                while ( heir->link[ 1 ] != nullptr ) {
                    heir = heir->link[ 1 ];
                }

                root->data = heir->data;
                data = heir->data;
            }

        }

        dir = root->data < data;
        root->link[ dir ] = remove_r ( root->link[ dir ], data, done );

        if ( !*done ) {
            root = remove_balance ( root, dir, done );
        }
    }

    return root;
}

template < typename TComparable >
typename SortedListRBT < TComparable >::Node *SortedListRBT < TComparable >::remove_balance (
        SortedListRBT < TComparable >::Node *root, int dir, int *done ) {

    Node *p = root;
    Node *s = root->link[ !dir ];

    if ( s != nullptr && !is_red ( s )) {
        if ( !is_red ( s->link[ 0 ] ) && !is_red ( s->link[ 1 ] )) {
            if ( is_red ( p )) {
                *done = 1;
            }

            p->red = BLACK;
            s->red = RED;
        }
        else {
            Color save = root->red;

            if ( is_red ( s->link[ !dir ] )) {
                p = single_rotation ( p, dir );
            }
            else {
                p = double_rotation ( p, dir );
            }

            p->red = save;
            p->link[ 0 ]->red = BLACK;
            p->link[ 1 ]->red = BLACK;
            *done = 1;
        }
    }
    else if ( s->link[ dir ] != nullptr ) {
        Node *r = s->link[ dir ];

        if ( !is_red ( r->link[ 0 ] ) && !is_red ( r->link[ 1 ] )) {
            p = single_rotation ( p, dir );
            p->link[ dir ]->link[ !dir ]->red = RED;
        }
        else {
            if ( is_red ( r->link[ dir ] )) {
                s->link[ dir ] = single_rotation ( r, !dir );
            }

            p = double_rotation ( p, dir );
            s->link[ dir ]->red = BLACK;
            p->link[ dir ]->red = RED;
        }

        p->red = BLACK;
        p->link[ dir ]->red = BLACK;
        *done = 1;
    }

    return p;
}

template < typename TComparable >
int SortedListRBT < TComparable >::rb_assert ( SortedListRBT < TComparable >::Node *root ) {
    int lh, rh;

    if ( root == NULL ) {
        return 1;
    }
    else {
        Node *ln = root->link[ 0 ];
        Node *rn = root->link[ 1 ];

        if ( is_red ( root )) {
            if ( is_red ( ln ) || is_red ( rn )) {
                throw std::runtime_error ( "Red violation!" );
            }
        }

        lh = rb_assert ( ln );
        rh = rb_assert ( rn );

        if (( ln != nullptr && ln->data > root->data ) || ( rn != nullptr && rn->data < root->data )) {
            throw std::runtime_error ( "Binary search tree violation!" );
        }

        if ( lh != 0 && rh != 0 && lh != rh ) {
            throw std::runtime_error ( "Black violation!" );
        }

        if ( lh != 0 && rh != 0 ) {
            return is_red ( root ) ? lh : lh + 1;
        }
        else {
            return 0;
        }
    }
}


template < typename TComparable >
unsigned int SortedListRBT < TComparable >::get_count () const {
    return this->_count;
}

template < typename TComparable >
bool SortedListRBT < TComparable >::is_empty () const {
    return this->_root == nullptr;
}

template < typename TComparable >
SortedListRBT::iterator < TComparable >::~iterator () {

}

template < typename TComparable >
AIterator & SortedListRBT < TComparable >::iterator::operator= ( const AIterator & other ) {
    this->_current = other.get_current ();
    return *this;
}

template < typename TComparable >
bool SortedListRBT < TComparable >::iterator::operator== ( const AIterator & other ) const {
    return this->_current == other.get_current ();
}

template < typename TComparable >
bool SortedListRBT < TComparable >::iterator::operator!= ( const AIterator & other ) const {
    return !operator== ( other );
}

template < typename TComparable >
AIterator & SortedListRBT < TComparable >::iterator::operator++ () {
    this->next ();
    return *this;
}

template < typename TComparable >
AIterator & SortedListRBT < TComparable >::iterator::operator+ ( const int & value ) {
    for ( int i = 0; i < value; ++i )
        this->next ();
    return *this;
}

template < typename TComparable >
TComparable & SortedListRBT < TComparable >::iterator::operator* () const {
    return *this->_current;
}

template < typename TComparable >
void SortedListRBT < TComparable >::iterator::next () {

}

#endif //PROJECTDSA_SORTEDLISTRBT_H
