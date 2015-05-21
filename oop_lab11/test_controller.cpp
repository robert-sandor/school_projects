//
// Created by robert on 5/22/15.
//

#include "gtest/gtest.h"
#include "IngredientController.h"

class IngredientControllerTest : public ::testing::Test {
protected:
    void SetUp () {
        _repo = new IngredientMemoryRepository;
        _repo->add ( {1, "a", "b", 10} );
        _repo->add ( {2, "c", "d", 20} );

        _con = new IngredientController {_repo};
    }

    void TearDown () {
        delete _con;
        delete _repo;
    }

    IngredientMemoryRepository * _repo;
    IngredientController * _con;
};

TEST_F ( IngredientControllerTest, TestAdd ) {
    _con->addIngredient ( 3, "e", "f", 30 );
    ASSERT_EQ ( _repo->get_elements ().size (), 3 );
    ASSERT_ANY_THROW ( _con->addIngredient ( 1, "", "", 0 ));
}

TEST_F ( IngredientControllerTest, TestRemove ) {
    _con->removeIngredient ( 1 );
    ASSERT_EQ ( _repo->get_elements ().size (), 1 );

    Ingredient i {2, "c", "d", 20};
    ASSERT_EQ ( _repo->get ( 0 ), i );

    ASSERT_ANY_THROW ( _con->removeIngredient ( 5 ));
}

TEST_F ( IngredientControllerTest, TestUpdate ) {
    _con->updateIngredient ( 2, "e", "f", 100 );
    ASSERT_EQ ( _repo->get ( 1 ).get_name (), "e" );
    ASSERT_EQ ( _repo->get ( 1 ).get_provider (), "f" );
    ASSERT_EQ ( _repo->get ( 1 ).get_quantity (), 100 );

    ASSERT_ANY_THROW ( _con->updateIngredient ( 100, "a", "n", 10 ));
}

TEST_F ( IngredientControllerTest, TestGet ) {
    ASSERT_EQ ( _con->getIngredient ( 1 ), _repo->get ( 0 ));
}

TEST_F ( IngredientControllerTest, TestFilters ) {
    ASSERT_EQ ( _con->getFilteredByQuantity ( 15 ).size (), 1 );
    ASSERT_EQ ( _con->getFilteredByQuantity ( 5 ).size (), 2 );
    ASSERT_EQ ( _con->getFilteredByQuantity ( 150 ).size (), 0 );
    ASSERT_EQ ( _con->getFilteredByName ( "a" ).size (), 1 );
    ASSERT_EQ ( _con->getFilteredByName ( "x" ).size (), 0 );
}