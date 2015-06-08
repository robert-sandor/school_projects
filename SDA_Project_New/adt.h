//
// Created by robert on 6/3/15.
//

#ifndef SDA_PROJECT_NEW_ADT_H
#define SDA_PROJECT_NEW_ADT_H

/*
 *  ADT for a Sorted List
 *  We assume the elements stored are comparable
 *  e.g. they implement the < operator
 *
 *  The operations on the list are :
 *   -- is_empty - check if the list is empty
 *   -- get_count - get the number of elements
 *   -- insert - add an element to the list
 *   -- remove - remove an element from the list
 *   -- contains - check whether the list contains an element
 */
template<typename TComparable>
class AbstractSortedList {
public:

    /*
     *  Check if the sorted list is empty
     *  Preconditions : List initialized
     *  Postcondition : Function value = (list is empty)
     */
    virtual bool is_empty() const = 0;

    /*
     *  Get the number of elements in the list
     *  Preconditions : List initialized
     *  Postcondition : Function value = number of elements in list
     */
    virtual unsigned int get_count() const = 0;

    /*
     *  Insert an element into the list
     *  Preconditions : List initialized
     *                  List is sorted
     *  Postconditions : element is in list
     *                   List is still sorted
     */
    virtual void insert(const TComparable &element) = 0;

    /*
     *  Delete an element from the list
     *  Preconditions : List initialized
     *                  Element exists in the list
     *  Postconditions : The first matching element is removed from the list
     *                   List is still sorted
     */
    virtual void remove(const TComparable &element) = 0;

    /*
     *  Retrieves whether an element is in the list
     *  Preconditions : List initialized
     *  Postconditions : Function value is true if the element
     *                   is in the list, false otherwise
     */
    virtual bool contains(const TComparable &element) = 0;

protected:

    // Keeps track of the number of the elements in the list
    // Useful for a fast retrieval of the number
    unsigned int _element_count;
};

/*
 *  ADT for a simple iterator
 *  TElem represents any kind of element
 *
 *  The operations on the iterator are :
 *   -- next - move iterator to the next element
 *   -- element - get the current element
 *   -- equal - check whether two iterators are equal
 */
template<typename TElem>
class AbstractIterator {
public:

    /*
     *  Move iterator to the next element
     *  Preconditions : iterator initialized
     *  Postcondition : iterator points to the next element
     */
    virtual void next() = 0;

    /*
     *  Get the current element
     *  Preconditions : iterator intialized
     *  Postcondition : function value = current element
     */
    virtual TElem element() const = 0;

    /*
     *  Comparison function
     *  Preconditions : iterator initialized
     *                  other iterator is valid
     *  Postcondition : function value = iterators are equal
     */
    virtual bool equal(const AbstractIterator &other) const = 0;

    TElem *get_current() const {
        return _current;
    }

protected:
    TElem *_current;
};

#endif //SDA_PROJECT_NEW_ADT_H
