//
// Created by robert on 6/4/15.
//

#ifndef SDA_PROJECT_NEW_SORTED_LIST_DV_H
#define SDA_PROJECT_NEW_SORTED_LIST_DV_H

#define CAPACITY_STEP 10

#include <stdexcept>
#include "adt.h"
#include "cstdlib" // realloc, free

template<typename TComparable>
class SortedListDV : public AbstractSortedList<TComparable> {
public:
    class iterator : public AbstractIterator<TComparable> {
    public:

        iterator(TComparable *element_ptr = nullptr) {
            this->_current = element_ptr;
        }

        iterator(const iterator &other) {
            this->_current = other._current;
        }

        virtual ~iterator() { }

        virtual void next();

        virtual TComparable element() const;

        virtual bool equal(const AbstractIterator<TComparable> &other) const;
    };

public:

    SortedListDV() {
        this->_capacity = 0;
        this->_element_count = 0;
        this->_elements = nullptr;
    }

    virtual ~SortedListDV() {
        if (this->_elements != nullptr) {
            free(this->_elements);
        }
    }

    virtual bool is_empty() const;

    virtual unsigned int get_count() const;

    virtual void insert(const TComparable &element);

    virtual void remove(const TComparable &element);

    virtual bool contains(const TComparable &element);

    iterator begin() const;

    iterator end() const;

private:
    unsigned int _capacity;
    TComparable *_elements;

    void extend();

    void shrink();

    int binary_search(const TComparable &element, int imin, int imax) const;
};

template<typename TComparable>
bool SortedListDV<TComparable>::is_empty() const {
    return this->_element_count == 0;
}

template<typename TComparable>
unsigned int SortedListDV<TComparable>::get_count() const {
    return this->_element_count;
}

template<typename TComparable>
void SortedListDV<TComparable>::insert(const TComparable &element) {
    if (_capacity <= this->_element_count) {
        extend();
    }

    unsigned int pos = 0;
    while (_elements[pos] < element && pos < this->_element_count) {
        pos++;
    }


    for (unsigned int i = this->_element_count; i > pos; --i) {
        _elements[i] = _elements[i - 1];
    }

    _elements[pos] = element;
    this->_element_count += 1;
}

template<typename TComparable>
void SortedListDV<TComparable>::remove(const TComparable &element) {
    if (_capacity > this->_element_count + CAPACITY_STEP) {
        shrink();
    }

    if (!contains(element)) {
        throw std::runtime_error("Element not found!");
    }

    unsigned int pos = (unsigned) binary_search(element, 0, this->_element_count - 1);
    for (unsigned int i = pos; i < this->_element_count - 1; i++) {
        _elements[i] = _elements[i + 1];
    }
    this->_element_count -= 1;
}

template<typename TComparable>
bool SortedListDV<TComparable>::contains(const TComparable &element) {
    return binary_search(element, 0, this->_element_count - 1) != -1;
}

template<typename TComparable>
void SortedListDV<TComparable>::iterator::next() {
    this->_current++;
}

template<typename TComparable>
TComparable SortedListDV<TComparable>::iterator::element() const {
    return *this->_current;
}

template<typename TComparable>
bool SortedListDV<TComparable>::iterator::equal(const AbstractIterator<TComparable> &other) const {
    if (this->_current > other.get_current()) {
        return true;
    }
    return this->_current == other.get_current();
}

template<typename TComparable>
void SortedListDV<TComparable>::extend() {
    _capacity += CAPACITY_STEP;

    _elements = (TComparable *) realloc(_elements, _capacity * sizeof(TComparable));
    if (_elements == nullptr) {
        throw std::runtime_error("Realloc failed!");
    }
}

template<typename TComparable>
void SortedListDV<TComparable>::shrink() {
    _capacity -= CAPACITY_STEP;

    _elements = (TComparable *) realloc(_elements, _capacity * sizeof(TComparable));
    if (_elements == nullptr) {
        throw std::runtime_error("Realloc failed!");
    }
}

template<typename TComparable>
int SortedListDV<TComparable>::binary_search(const TComparable &element, int imin, int imax) const {
    if (imax < imin) {
        return -1;
    }

    int imid = (imin + imax) / 2;

    if (_elements[imid] == element) {
        return imid;
    }

    if (_elements[imid] < element) {
        return binary_search(element, imid + 1, imax);
    }
    else {
        return binary_search(element, imin, imid - 1);
    }
}

template<typename TComparable>
typename SortedListDV<TComparable>::iterator SortedListDV<TComparable>::begin() const {
    return SortedListDV::iterator(_elements);
}

template<typename TComparable>
typename SortedListDV<TComparable>::iterator SortedListDV<TComparable>::end() const {
    return SortedListDV::iterator(_elements + this->_element_count);
}

#endif //SDA_PROJECT_NEW_SORTED_LIST_DV_H
