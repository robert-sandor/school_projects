//
// Created by robert on 5/21/15.
//

#ifndef OOP_LAB11_INGREDIENTFILEREPOSITORY_H
#define OOP_LAB11_INGREDIENTFILEREPOSITORY_H

#include "IngredientMemoryRepository.h"
#include "string"

class IngredientFileRepository : public IngredientMemoryRepository {
public:
    IngredientFileRepository ( const std::string & _fileName ) : _fileName ( _fileName ) { }

    virtual ~IngredientFileRepository () { }

    void load_file ();

    void save_file ();

private:
    std::string _fileName;
};


#endif //OOP_LAB11_INGREDIENTFILEREPOSITORY_H
