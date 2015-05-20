//
// Created by robert on 5/21/15.
//

#ifndef OOP_LAB11_INGREDIENTMEMORYREPOSITORY_H
#define OOP_LAB11_INGREDIENTMEMORYREPOSITORY_H

#include "vector"
#include "algorithm"
#include "Ingredient.h"
#include "exception"

class IngredientMemoryRepositoryException : public std::exception {

public:
    IngredientMemoryRepositoryException ( const std::string & _message ) : _message ( _message ) { }

    virtual ~IngredientMemoryRepositoryException () { }

private:
    std::string _message;
};

class IngredientMemoryRepository {

public:
    IngredientMemoryRepository () { }

    virtual ~IngredientMemoryRepository () { }

    const std::vector <Ingredient> & get_elements () const {
        return _elements;
    }

    const Ingredient & add ( const Ingredient & element );

    void remove ( const Ingredient & element );

    void remove ( const size_t & position );

    void update ( const Ingredient & oldElement, const Ingredient & newElement );

    void update ( const size_t & position, const Ingredient & newElement );

    const Ingredient & get ( const size_t & position ) const;

    void undo ();

private:
    std::vector <Ingredient> _elements;
    std::vector <std::vector <Ingredient>> _undoList;

    void addToUndo ();
};


#endif //OOP_LAB11_INGREDIENTMEMORYREPOSITORY_H
