//
// Created by robert on 5/14/15.
//

#ifndef OOP_LAB11_INGREDIENT_H
#define OOP_LAB11_INGREDIENT_H

#include "string"

class Ingredient {
public:
    Ingredient(unsigned int _id, const std::string &_name, const std::string &_provider, unsigned int _quantity) : _id(
            _id), _name(_name), _provider(_provider), _quantity(_quantity) { }

    virtual ~Ingredient() { }

    unsigned int get_id() const {
        return _id;
    }

    const std::string &get_name() const {
        return _name;
    }

    const std::string &get_provider() const {
        return _provider;
    }

    unsigned int get_quantity() const {
        return _quantity;
    }

    void set_name(const std::string &_name) {
        Ingredient::_name = _name;
    }

    void set_provider(const std::string &_provider) {
        Ingredient::_provider = _provider;
    }

    void set_quantity(unsigned int _quantity) {
        Ingredient::_quantity = _quantity;
    }

    const std::string &toSTDString() const {
        return std::to_string(_id) + " : " + _name + " : " + _provider + " : " + std::to_string(_quantity);
    }

    inline bool operator==(const Ingredient &rhs, const Ingredient &lhs) const;

    inline bool operator!=(const Ingredient &rhs, const Ingredient &lhs) const;

    Ingredient &operator=(Ingredient other);

private:
    unsigned int _id;
    std::string _name;
    std::string _provider;
    unsigned int _quantity;
};


#endif //OOP_LAB11_INGREDIENT_H
