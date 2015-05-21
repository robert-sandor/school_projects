//
// Created by robert on 5/21/15.
//

#include "IngredientFileRepository.h"

void IngredientFileRepository::load_file () {
    std::ifstream in{_fileName, std::ios::in};

    while ( in.good () && !in.eof ()) {
        std::string line, token;
        std::getline ( in, line );
        std::istringstream iss ( line );

        std::getline ( iss, token, ':' );
        unsigned int id{( unsigned ) std::atoi ( token.c_str ())};
        if ( in.eof ()) {
            break;
        }

        std::getline ( iss, token, ':' );
        std::string name{token};

        std::getline ( iss, token, ':' );
        std::string provider{token};

        std::getline ( iss, token, ':' );
        unsigned int quantity{( unsigned ) std::atoi ( token.c_str ())};

        add ( {id, name, provider, quantity} );
    };

    in.close ();
}

void IngredientFileRepository::save_file () {
    std::ofstream out{_fileName, std::ios::trunc | std::ios::out};

    for ( auto ing : get_elements ()) {
        out << ing << std::endl;
    }

    out.close ();
}
