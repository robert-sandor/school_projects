//
// Created by robert on 5/21/15.
//

#include "IngredientMemoryRepository.h"

const Ingredient & IngredientMemoryRepository::add ( const Ingredient & element ) {
    if ( _elements.end () != std::find ( _elements.begin (), _elements.end (), element )) {
        throw std::runtime_error {"duplicate_element"};
    }

    validator.validate ( element );

    addToUndo ();
    _elements.push_back ( element );
    return *(std::find ( _elements.begin (), _elements.end (), element ));
}

void IngredientMemoryRepository::remove ( const Ingredient & element ) {
    std::vector <Ingredient>::iterator it = std::find ( _elements.begin (), _elements.end (), element );
    if ( it == _elements.end ()) {
        throw std::runtime_error {"element_not_found"};
    }

    addToUndo ();

    _elements.erase ( it );
}

void IngredientMemoryRepository::remove ( const size_t & position ) {
    if ( position >= _elements.size ()) {
        throw std::runtime_error {"index_out_of_range"};
    }

    addToUndo ();

    _elements.erase ( _elements.begin () + position );
}

void IngredientMemoryRepository::update ( const Ingredient & oldElement, const Ingredient & newElement ) {
    std::vector <Ingredient>::iterator it = std::find ( _elements.begin (), _elements.end (), oldElement );
    if ( it == _elements.end ()) {
        throw std::runtime_error {"element_not_found"};
    }

    validator.validate ( newElement );

    addToUndo ();

    *it = newElement;
}

void IngredientMemoryRepository::update ( const size_t & position, const Ingredient & newElement ) {
    if ( position >= _elements.size ()) {
        throw std::runtime_error {"index_out_of_range"};
    }

    validator.validate ( newElement );

    addToUndo ();

    *(_elements.begin () + position) = newElement;
}

const Ingredient & IngredientMemoryRepository::get ( const size_t & position ) const {
    if ( position >= _elements.size ()) {
        throw std::runtime_error {"index_out_of_range"};
    }

    return _elements.at ( position );
}

void IngredientMemoryRepository::undo () {
    if ( _undoList.size () == 0 ) {
        throw std::runtime_error {"no_more_undo"};
    }

    _elements = _undoList.back ();
    _undoList.pop_back ();
}

void IngredientMemoryRepository::addToUndo () {
    _undoList.push_back ( _elements );
}
