//
// Created by robert on 5/21/15.
//

#include "gtest/gtest.h"
#include "IngredientFileRepository.h"
#include "fstream"

class IngFRTest : public ::testing::Test {
protected:
    void SetUp () {
        std::ofstream out{"test_data.txt", std::ios::trunc | std::ios::out};

        out << "1:a:b:2\n2:c:d:3\n3:e:f:10\n";
        out.close ();

        _repo = new IngredientFileRepository{"test_data.txt"};
    }

    void TearDown () {
        delete _repo;
    }

    IngredientFileRepository * _repo;
};

TEST_F ( IngFRTest, TestLoadFile ) {
    _repo->load_file ();
    ASSERT_EQ ( _repo->get_elements ().size (), 3 );

    ASSERT_EQ ( _repo->get ( 0 ), Ingredient ( 1, "a", "b", 2 ));
    ASSERT_EQ ( _repo->get ( 1 ), Ingredient ( 2, "c", "d", 3 ));
    ASSERT_EQ ( _repo->get ( 2 ), Ingredient ( 3, "e", "f", 10 ));
    ASSERT_ANY_THROW ( _repo->get ( 4 ));
}

TEST_F ( IngFRTest, TestSaveFile ) {
    _repo->add ( {10, "ab", "cd", 100} );
    _repo->add ( {11, "ef", "gh", 200} );
    _repo->save_file ();

    std::ifstream fin{"test_data.txt"};
    std::string s;

    std::getline ( fin, s );
    ASSERT_EQ ( s, "10:ab:cd:100" );

    std::getline ( fin, s );
    ASSERT_EQ ( s, "11:ef:gh:200" );

    fin.close ();
}