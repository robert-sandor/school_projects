//
// Created by robert on 5/19/15.
//

#include "gtest/gtest.h"
#include "Ingredient.h"

class IngredientTest : public ::testing::Test {
protected:
    virtual void SetUp () {
        ing1 = new Ingredient ( 1, "a", "b", 2 );
        ing2 = new Ingredient;
    }

    virtual void TearDown () {
        delete ing1;
        delete ing2;
    }

    Ingredient * ing1;
    Ingredient * ing2;
};

TEST_F ( IngredientTest, TestConstructorsAndGetters ) {
    ASSERT_EQ ( 1, ing1->get_id ());
    ASSERT_EQ ( "a", ing1->get_name ());
    ASSERT_EQ ( "b", ing1->get_provider ());
    ASSERT_EQ ( 2, ing1->get_quantity ());

    ASSERT_EQ ( 0, ing2->get_id ());
    ASSERT_EQ ( "", ing2->get_name ());
    ASSERT_EQ ( "", ing2->get_provider ());
    ASSERT_EQ ( 0, ing2->get_quantity ());
}

TEST_F ( IngredientTest, TestSetters ) {
    ing2->set_name ( "a" );
    ASSERT_EQ ( "a", ing2->get_name ());

    ing2->set_provider ( "b" );
    ASSERT_EQ ( "b", ing2->get_provider ());

    ing2->set_quantity ( 100 );
    ASSERT_EQ ( 100, ing2->get_quantity ());
}

TEST_F ( IngredientTest, TestToSTDString ) {
    std::string s = ing1->toSTDString ();
    ASSERT_EQ ( "1:a:b:2", s );
}

TEST_F ( IngredientTest, TestOperators ) {
    // Inequality operator
    Ingredient a ( 1, "a", "b", 2 );
    Ingredient b ( 2, "c", "b", 2 );
    ASSERT_NE ( a, b );

    // Assignment and equality
    b = a;
    ASSERT_EQ ( a, b );

    // I/O
    std::string s ( "3:ab:ba:20" );
    std::istringstream iss ( s );
    iss >> b;
    ASSERT_EQ ( 3, b.get_id ());
    ASSERT_EQ ( "ab", b.get_name ());
    ASSERT_EQ ( "ba", b.get_provider ());
    ASSERT_EQ ( 20, b.get_quantity ());

    std::ostringstream oss;
    oss << a;
    ASSERT_EQ ( "1:a:b:2", oss.str ());
}