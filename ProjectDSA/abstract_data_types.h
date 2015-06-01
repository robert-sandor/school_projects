//
// Created by robert on 6/1/15.
//

#ifndef PROJECTDSA_ABSTRACT_DATA_TYPES_H
#define PROJECTDSA_ABSTRACT_DATA_TYPES_H

/*
 *
 */
template < typename TElem >
class AIterator {
public:
    AIterator ( ) : _current ( 0 ) { }

    virtual ~AIterator () { }

    virtual AIterator & operator= ( const AIterator & other ) = 0;

    virtual bool operator== ( const AIterator & other ) const = 0;

    virtual bool operator!= ( const AIterator & other ) const = 0;

    virtual AIterator & operator++ () = 0;

    virtual AIterator & operator-- () = 0;

    virtual AIterator & operator+ ( const int & value ) = 0;

    virtual AIterator & operator- ( const int & value ) = 0;

    virtual TElem & operator* () const = 0;

    virtual void next () = 0;

    virtual void prev () = 0;

    virtual TElem *get_current () const {
        return _current;
    }

protected:
    TElem *_current;
};

template < typename TElem >
class ASortedList {
public:
    virtual TElem & get_at_index ( const unsigned int & index ) const = 0;

    virtual void add ( const TElem & element ) = 0;

    virtual void remove_from_index ( const unsigned int & index ) = 0;

    virtual unsigned int get_index ( const TElem & element ) = 0;

    virtual unsigned int get_count () const = 0;

    virtual bool is_empty () const = 0;

protected:
    unsigned int _count;
};

#endif //PROJECTDSA_ABSTRACT_DATA_TYPES_H
