//
// Created by robert on 5/21/15.
//

#include "gtest/gtest.h"
#include "IngredientMemoryRepository.h"

class IMRTest : public ::testing::Test {
protected:
    void SetUp () {
        _repo = new IngredientMemoryRepository;
        _repo->add ( Ingredient ( 10, "a", "b", 20 ));
        _repo->add ( Ingredient ( 11, "c", "d", 30 ));
    }

    void TearDown () {
        delete _repo;
    }

    IngredientMemoryRepository * _repo;
};

TEST_F ( IMRTest, testAdd ) {
    _repo->add ( Ingredient ( 1, "A", "B", 2 ));
    ASSERT_EQ ( _repo->get_elements ().size (), 3 );
}

TEST_F ( IMRTest, testRemove ) {
    _repo->remove ( 1 );
    ASSERT_EQ ( _repo->get_elements ().size (), 1 );

    ASSERT_ANY_THROW ( _repo->remove ( 1 ));

    _repo->remove ( Ingredient ( 10, "a", "b", 20 ));
    ASSERT_EQ ( _repo->get_elements ().size (), 0 );

    ASSERT_ANY_THROW ( _repo->remove ( Ingredient ( 2, "as", "sa", 50 )));
}

TEST_F ( IMRTest, testGet ) {
    ASSERT_EQ ( _repo->get ( 0 ), Ingredient ( 10, "a", "b", 20 ));
    ASSERT_ANY_THROW ( _repo->get ( 100 ));
}

TEST_F ( IMRTest, testUpdate ) {
    _repo->update ( Ingredient ( 10, "a", "b", 20 ), Ingredient ( 20, "A", "B", 40 ));
    ASSERT_EQ ( _repo->get ( 0 ), Ingredient ( 20, "A", "B", 40 ));

    ASSERT_ANY_THROW ( _repo->update ( Ingredient ( 100, "", "", 0 ), Ingredient ()));

    _repo->update ( 0, Ingredient ( 10, "a", "b", 20 ));
    ASSERT_EQ ( _repo->get ( 0 ), Ingredient ( 10, "a", "b", 20 ));

    ASSERT_ANY_THROW ( _repo->update ( 100, Ingredient ()));
}

TEST_F ( IMRTest, testUndo ) {
    _repo->undo ();
    ASSERT_EQ ( _repo->get_elements ().size (), 1 );
    ASSERT_EQ ( _repo->get ( 0 ), Ingredient ( 10, "a", "b", 20 ));

    _repo->undo ();
    ASSERT_ANY_THROW ( _repo->undo ());
}