//
// Created by robert on 5/22/15.
//

#include "IngredientController.h"

void IngredientController::addIngredient ( const unsigned int & id, const std::string & name,
                                           const std::string & provider, const unsigned int & quantity ) {
    _repo->add ( {id, name, provider, quantity} );
}

void IngredientController::removeIngredient ( const unsigned int & id ) {
    _repo->remove ( {id, "", "", 0} );
}

void IngredientController::updateIngredient ( const unsigned int & id, const std::string & name,
                                              const std::string & provider, const unsigned int & quantity ) {
    Ingredient o {id, "", "", 0};
    Ingredient n {id, name, provider, quantity};
    _repo->update ( o, n );
}

std::vector <Ingredient> IngredientController::getAllIngredients () const {
    return _repo->get_elements ();
}

Ingredient IngredientController::getIngredient ( const unsigned int & id ) const {
    Ingredient i {id, "", "", 0};
    std::vector <Ingredient>::const_iterator it = std::find ( _repo->get_elements ().begin (),
                                                              _repo->get_elements ().end (),
                                                              i );

    if ( it == _repo->get_elements ().end ()) {
        throw std::runtime_error {"element_id_not_found"};
    }

    return _repo->get ( it - _repo->get_elements ().begin ());
}

std::vector <Ingredient> IngredientController::getFilteredByQuantity ( const unsigned int & quantity ) const {
    std::vector <Ingredient> all = _repo->get_elements ();
    std::vector <Ingredient> filtered;

    for ( Ingredient i : all ) {
        if ( i.get_quantity () >= quantity ) {
            filtered.push_back ( i );
        }
    }

    return filtered;
}

std::vector <Ingredient> IngredientController::getFilteredByName ( const std::string & name ) const {
    std::vector <Ingredient> all = _repo->get_elements ();
    std::vector <Ingredient> filtered;

    for ( Ingredient i : all ) {
        if ( i.get_name () == name ) {
            filtered.push_back ( i );
        }
    }

    return filtered;
}
