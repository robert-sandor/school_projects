//
// Created by robert on 5/21/15.
//

#ifndef OOP_LAB11_INGREDIENTVALIDATOR_H
#define OOP_LAB11_INGREDIENTVALIDATOR_H


#include "Ingredient.h"

class IngredientValidator {
public:
    IngredientValidator () { }

    virtual ~IngredientValidator () { }

    void validate ( const Ingredient & ing ) const;
};


#endif //OOP_LAB11_INGREDIENTVALIDATOR_H
