//
// Created by robert on 6/1/15.
//

#ifndef PROJECTDSA_SORTEDLISTDV_H
#define PROJECTDSA_SORTEDLISTDV_H

#include "stdexcept"
#include "abstract_data_types.h"

template < typename TElem >
class SortedListDV : public ASortedList < TElem > {
public:
    class iterator : public AIterator < TElem > {
    public:
        iterator () { }

        iterator ( TElem *ptr ) {
            this->_current = ptr;
        }

        virtual ~iterator () { }

        virtual SortedListDV::iterator & operator= ( const AIterator < TElem > & other ) override;

        SortedListDV::iterator & operator= ( const SortedListDV::iterator & other );

        virtual bool operator== ( const AIterator < TElem > & other ) const override;

        virtual bool operator!= ( const AIterator < TElem > & other ) const override;

        virtual SortedListDV::iterator & operator++ () override;

        virtual SortedListDV::iterator & operator-- () override;

        virtual SortedListDV::iterator & operator+ ( const int & value ) override;

        virtual SortedListDV::iterator & operator- ( const int & value ) override;

        virtual TElem & operator* () const override;

        virtual void next () override;

        virtual void prev () override;

    protected:
//        TElem * _current;
    };

public:
    SortedListDV () {
        _elements = NULL;
        _capacity = 0;
        _count = 0;
    }

    virtual ~SortedListDV () { }

    TElem & get_at_index ( const unsigned int & index ) const;

    void add ( const TElem & element );


    virtual void remove ( const TElem & element ) override;

    void remove ( const iterator & iter );

    void remove_from_index ( const unsigned int & index );

    iterator find ( const TElem & element );

    unsigned int get_index ( const TElem & element );

    unsigned int get_count () const;

    unsigned int get_capacity () const;

    bool is_empty () const;

    iterator begin () const;

    iterator end () const;

private:
    void extend ();

    void shrink ();

    unsigned int _capacity;
    unsigned int _count;
    TElem *_elements;
};

/*
 * --------------------------------------------------------------------------------------------------------------------|
 * SortedListDV methods
 * --------------------------------------------------------------------------------------------------------------------|
 */

template < typename TElem >
TElem & SortedListDV < TElem >::get_at_index ( const unsigned int & index ) const {
    if ( index >= _count ) {
        throw std::runtime_error ( "Index out of range!" );
    }
    return _elements[ index ];
}

template < typename TElem >
void SortedListDV < TElem >::add ( const TElem & element ) {
    if ( _count >= _capacity ) {
        extend ();
    }

    unsigned int position = 0;
    while ( _elements[ position ] < element && position < _count ) {
        ++position;
    }

    for ( unsigned int i = _count; i > position; --i ) {
        _elements[ i ] = _elements[ i - 1 ];
    }
    _elements[ position ] = element;
    _count += 1;
}

template < typename TElem >
void SortedListDV < TElem >::remove_from_index ( const unsigned int & index ) {
    if ( index >= _count ) {
        throw std::runtime_error ( "Index out of range!" );
    }

    for ( unsigned int i = index; i < _count - 1; ++i ) {
        _elements[ i ] = _elements[ i + 1 ];
    }
    _count -= 1;
}

template < typename TElem >
unsigned int SortedListDV < TElem >::get_index ( const TElem & element ) {
    int found = -1;
    int max = _count;
    int min = 0;

    while ( min <= max ) {
        int mid = ( min + max ) / 2;

        if ( _elements[ mid ] == element ) {
            found = mid;
            break;
        }
        else if ( _elements[ mid ] > element ) {
            max = mid - 1;
        }
        else if ( _elements[ mid ] < element ) {
            min = mid + 1;
        }
    }

    if ( found == -1 ) {
        throw std::runtime_error ( "Element not found!" );
    }

    return ( unsigned ) found;
}

template < typename TElem >
unsigned int SortedListDV < TElem >::get_count () const {
    return _count;
}

template < typename TElem >
bool SortedListDV < TElem >::is_empty () const {
    return _count == 0;
}

template < typename TElem >
void SortedListDV < TElem >::remove ( const TElem & element ) {
    SortedListDV < TElem >::iterator it = this->find ( element );
    this->remove ( it );
}

template < typename TElem >
void SortedListDV < TElem >::remove ( const SortedListDV < TElem >::iterator & iter ) {
    remove_from_index (( unsigned ) ( iter.get_current () - _elements ));
}

template < typename TElem >
typename SortedListDV < TElem >::iterator SortedListDV < TElem >::find ( const TElem & element ) {
    unsigned int index = get_index ( element );
    return SortedListDV < TElem >::iterator ( _elements + index );
}

template < typename TElem >
void SortedListDV < TElem >::extend () {
    _capacity += 10;
    _elements = ( TElem * ) realloc ( _elements, _capacity * sizeof ( TElem ));
    if ( NULL == _elements ) {
        throw std::runtime_error ( "Extend failed!" );
    }
}

template < typename TElem >
void SortedListDV < TElem >::shrink () {
    _capacity -= 10;
    _elements = ( int * ) realloc ( _elements, _capacity * sizeof ( TElem ));
    if ( NULL == _elements ) {
        throw std::runtime_error ( "Shrink failed!" );
    }
}

template < typename TElem >
unsigned int SortedListDV < TElem >::get_capacity () const {
    return _capacity;
}

template < typename TElem >
typename SortedListDV < TElem >::iterator SortedListDV < TElem >::begin () const {
    return SortedListDV < TElem >::iterator ( _elements );
}

template < typename TElem >
typename SortedListDV < TElem >::iterator SortedListDV < TElem >::end () const {
    return SortedListDV < TElem >::iterator ( _elements + this->_count - 1 );
}


/*
 * --------------------------------------------------------------------------------------------------------------------|
 * Iterator methods
 * --------------------------------------------------------------------------------------------------------------------|
 */

template < typename TElem >
typename SortedListDV < TElem >::iterator & SortedListDV < TElem >::iterator::operator= (
        const AIterator < TElem > & other ) {
    this->_current = other.get_current ();
    return *this;
}


template < typename TElem >
typename SortedListDV < TElem >::iterator & SortedListDV < TElem >::iterator::operator= (
        const SortedListDV < TElem >::iterator & other ) {
    this->_current = other.get_current ();
    return *this;
}


template < typename TElem >
bool SortedListDV < TElem >::iterator::operator== ( const AIterator < TElem > & other ) const {
    return this->_current == other.get_current ();
}

template < typename TElem >
bool SortedListDV < TElem >::iterator::operator!= ( const AIterator < TElem > & other ) const {
    return !operator== ( other );
}

template < typename TElem >
typename SortedListDV < TElem >::iterator & SortedListDV < TElem >::iterator::operator++ () {
    ++this->_current;
    return *this;
}

template < typename TElem >
typename SortedListDV < TElem >::iterator & SortedListDV < TElem >::iterator::operator-- () {
    --this->_current;
    return *this;
}

template < typename TElem >
typename SortedListDV < TElem >::iterator & SortedListDV < TElem >::iterator::operator+ ( const int & value ) {
    this->_current += value;
    return *this;
}

template < typename TElem >
typename SortedListDV < TElem >::iterator & SortedListDV < TElem >::iterator::operator- ( const int & value ) {
    this->_current -= value;
    return *this;
}

template < typename TElem >
TElem & SortedListDV < TElem >::iterator::operator* () const {
    return *this->_current;
}

template < typename TElem >
void SortedListDV < TElem >::iterator::next () {
    ++this->_current;
}

template < typename TElem >
void SortedListDV < TElem >::iterator::prev () {
    --this->_current;
}


#endif //PROJECTDSA_SORTEDLISTDV_H
