//
// Created by robert on 5/27/15.
//

#include "Graph.h"

Graph::Graph ( unsigned int number_of_vertices ) {
    _vertices.resize ( number_of_vertices );
}

void Graph::add_edge ( const unsigned int & from, const unsigned int & to, const unsigned int & cost ) {
    _vertices[ from ]._outbound.insert ( std::pair < unsigned int, unsigned int > ( to, cost ));
    _vertices[ to ]._inbound.insert ( std::pair < unsigned int, unsigned int > ( from, cost ));
}

void Graph::remove_edge ( const unsigned int & from, const unsigned int & to ) {
    _vertices[ from ]._outbound.erase ( to );
    _vertices[ to ]._inbound.erase ( from );
}

void Graph::modify_cost ( const unsigned int & from, const unsigned int & to, const unsigned int & cost ) {
    _vertices[ from ]._outbound[ to ] = cost;
    _vertices[ to ]._inbound[ from ] = cost;
}

const std::map < unsigned int, unsigned int > & Graph::get_outbounds ( const unsigned int & from ) const {
    return _vertices[ from ]._outbound;
}

const std::map < unsigned int, unsigned int > & Graph::get_inbounds ( const unsigned int & to ) const {
    return _vertices[ to ]._inbound;
}
