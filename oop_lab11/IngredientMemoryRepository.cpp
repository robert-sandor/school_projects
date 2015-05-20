//
// Created by robert on 5/21/15.
//

#include "IngredientMemoryRepository.h"

const Ingredient & IngredientMemoryRepository::add ( const Ingredient & element ) {
    addToUndo ();
    _elements.push_back ( element );
    return *(std::find ( _elements.begin (), _elements.end (), element ));
}

void IngredientMemoryRepository::remove ( const Ingredient & element ) {
    std::vector <Ingredient>::iterator it = std::find ( _elements.begin (), _elements.end (), element );
    if ( it == _elements.end ()) {
        throw IngredientMemoryRepositoryException ( "element_not_found" );
    }

    addToUndo ();

    _elements.erase ( it );
}

void IngredientMemoryRepository::remove ( const size_t & position ) {
    if ( position >= _elements.size ()) {
        throw IngredientMemoryRepositoryException ( "index_out_of_range" );
    }

    addToUndo ();

    _elements.erase ( _elements.begin () + position );
}

void IngredientMemoryRepository::update ( const Ingredient & oldElement, const Ingredient & newElement ) {
    std::vector <Ingredient>::iterator it = std::find ( _elements.begin (), _elements.end (), oldElement );
    if ( it == _elements.end ()) {
        throw IngredientMemoryRepositoryException ( "element_not_found" );
    }

    addToUndo ();

    *it = newElement;
}

void IngredientMemoryRepository::update ( const size_t & position, const Ingredient & newElement ) {
    if ( position >= _elements.size ()) {
        throw IngredientMemoryRepositoryException ( "index_out_of_range" );
    }

    addToUndo ();

    *(_elements.begin () + position) = newElement;
}

const Ingredient & IngredientMemoryRepository::get ( const size_t & position ) const {
    if ( position >= _elements.size ()) {
        throw IngredientMemoryRepositoryException ( "index_out_of_range" );
    }

    return _elements.at ( position );
}

void IngredientMemoryRepository::undo () {
    if ( _undoList.size () == 0 ) {
        throw IngredientMemoryRepositoryException ( "no_more_undo" );
    }

    _elements = _undoList.back ();
    _undoList.pop_back ();
}

void IngredientMemoryRepository::addToUndo () {
    _undoList.push_back ( _elements );
}
