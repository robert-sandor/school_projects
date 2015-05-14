//
// Created by robert on 5/14/15.
//

#include "Ingredient.h"

bool Ingredient::operator==(const Ingredient &lhs) {
    return _id == lhs._id;
}

bool Ingredient::operator!=(const Ingredient &lhs) {
    return _id != lhs._id;
}

Ingredient &Ingredient::operator=(Ingredient other) {
    _id = other._id;
    _name = other._name;
    _provider = other._provider;
    _quantity = other._quantity;
    return *this;
}
