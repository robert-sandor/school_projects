//
// Created by robert on 5/22/15.
//

#ifndef OOP_LAB11_INGREDIENTCONTROLLER_H
#define OOP_LAB11_INGREDIENTCONTROLLER_H


#include "IngredientMemoryRepository.h"

class IngredientController {
public:
    IngredientController ( IngredientMemoryRepository * _repo ) : _repo ( _repo ) { }

    virtual ~IngredientController () { }

    void addIngredient ( const unsigned int & id,
                         const std::string & name,
                         const std::string & provider,
                         const unsigned int & quantity );

    void removeIngredient ( const unsigned int & id );

    void updateIngredient ( const unsigned int & id,
                            const std::string & name,
                            const std::string & provider,
                            const unsigned int & quantity );

    std::vector <Ingredient> getAllIngredients () const;

    Ingredient getIngredient ( const unsigned int & id ) const;

    std::vector <Ingredient> getFilteredByQuantity ( const unsigned int & quantity ) const;

    std::vector <Ingredient> getFilteredByName ( const std::string & name ) const;

    void undo () {
        _repo->undo ();
    }

private:
    IngredientMemoryRepository * _repo;
};


#endif //OOP_LAB11_INGREDIENTCONTROLLER_H
