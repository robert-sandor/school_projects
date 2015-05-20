//
// Created by robert on 5/14/15.
//

#ifndef OOP_LAB11_INGREDIENT_H
#define OOP_LAB11_INGREDIENT_H

#include "string"
#include "istream"
#include "ostream"
#include "sstream"

class Ingredient {
public:
    Ingredient ()
        : _id ( 0 ), _name ( "" ), _provider ( "" ), _quantity ( 0 ) { }

    Ingredient ( unsigned int _id, const std::string & _name, const std::string & _provider, unsigned int _quantity )
        : _id ( _id ), _name ( _name ), _provider ( _provider ), _quantity ( _quantity ) { }

    virtual ~Ingredient () { }

    unsigned int get_id () const {
        return _id;
    }

    const std::string & get_name () const {
        return _name;
    }

    const std::string & get_provider () const {
        return _provider;
    }

    unsigned int get_quantity () const {
        return _quantity;
    }

    void set_name ( const std::string & _name ) {
        Ingredient::_name = _name;
    }

    void set_provider ( const std::string & _provider ) {
        Ingredient::_provider = _provider;
    }

    void set_quantity ( unsigned int _quantity ) {
        Ingredient::_quantity = _quantity;
    }

    const std::string toSTDString () const {
        return std::to_string ( _id ) + ":" + _name + ":" + _provider + ":" + std::to_string ( _quantity );
    }

    friend bool operator== ( const Ingredient & rhs, const Ingredient & lhs ) {
        return rhs._id == lhs._id;
    }

    friend bool operator!= ( const Ingredient & rhs, const Ingredient & lhs ) {
        return rhs._id != lhs._id;
    }

    Ingredient & operator= ( const Ingredient & other ) {
        _id = other._id;
        _name = other._name;
        _provider = other._provider;
        _quantity = other._quantity;

        return *this;
    }

    friend std::ostream & operator<< ( std::ostream & os, const Ingredient & ing ) {
        return os << ing.toSTDString ();
    }

    friend std::istream & operator>> ( std::istream & is, Ingredient & ing ) {
        std::string line{}, token{};

        std::getline ( is, line );
        std::istringstream iss ( line );

        std::getline ( iss, token, ':' );
        unsigned int i;
        std::istringstream ( token ) >> i;
        ing._id = i;

        std::getline ( iss, token, ':' );
        ing.set_name ( token );

        std::getline ( iss, token, ':' );
        ing.set_provider ( token );

        std::getline ( iss, token, ':' );
        std::istringstream ( token ) >> i;
        ing.set_quantity ( i );

        return is;
    }

private:
    unsigned int _id;
    std::string _name;
    std::string _provider;
    unsigned int _quantity;
};


#endif //OOP_LAB11_INGREDIENT_H
