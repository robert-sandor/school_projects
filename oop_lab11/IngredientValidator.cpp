//
// Created by robert on 5/21/15.
//

#include "IngredientValidator.h"
#include "stdexcept"

void IngredientValidator::validate ( const Ingredient & ing ) const {
    // check if name is an empty string
    if ( ing.get_name ().empty ()) {
        throw std::runtime_error {"ingredient_name_empty"};
    }

    // check if provider is an empty string
    if ( ing.get_provider ().empty ()) {
        throw std::runtime_error {"ingredient_provider_empty"};
    }
}
