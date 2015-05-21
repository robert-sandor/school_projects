//
// Created by robert on 5/21/15.
//

#ifndef OOP_LAB11_INGREDIENTMEMORYREPOSITORY_H
#define OOP_LAB11_INGREDIENTMEMORYREPOSITORY_H

#include "vector"
#include "algorithm"
#include "Ingredient.h"
#include "stdexcept"
#include "IngredientValidator.h"

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
    const IngredientValidator validator;

    void addToUndo ();
};


#endif //OOP_LAB11_INGREDIENTMEMORYREPOSITORY_H
