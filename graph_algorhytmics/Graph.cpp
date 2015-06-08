//
// Created by robert on 5/27/15.
//

#include <iostream>
#include "Graph.h"

Graph::Graph ( unsigned int number_of_vertices ) {
    _vertices.resize ( number_of_vertices );
    _size = 0;
}

void Graph::add_edge ( const unsigned int & from, const unsigned int & to, const unsigned int & cost ) {
    _vertices[ from ]._outbound.insert ( std::pair < unsigned int, unsigned int > ( to, cost ));
    _vertices[ to ]._inbound.insert ( std::pair < unsigned int, unsigned int > ( from, cost ));
    _size++;
}

void Graph::remove_edge ( const unsigned int & from, const unsigned int & to ) {
    _vertices[ from ]._outbound.erase ( to );
    _vertices[ to ]._inbound.erase ( from );
    _size--;
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

Graph::Graph ( const Graph & other ) {
    _size = other._size;
    _vertices = other._vertices;
}

/*
 *  Based on tajan's scc algorithm
 *  http://en.wikipedia.org/wiki/Tarjan%27s_strongly_connected_components_algorithm
 *
 *  Checks whether the graph has an SCC that has more than 1 component
 *  As SCC of two or more vertices are cyclic, we can deduce whether the graph
 *  is a DAG or not
 */
bool Graph::tarjan_dag_check () {
    int *disc = new int[vertex_count ()];
    int *low = new int[vertex_count ()];
    bool *stackMember = new bool[vertex_count ()];
    std::stack < int > *st = new std::stack < int > ();

    for ( uint i = 0; i < vertex_count (); ++i ) {
        disc[ i ] = -1;
        low[ i ] = -1;
        stackMember[ i ] = false;
    }

    bool result = true;
    for ( uint i = 0; i < vertex_count (); ++i ) {
        if ( disc[ i ] == -1 ) {
            result = result && tarjan_dag_check_util ( i, disc, low, st, stackMember );
        }
        if ( !result ) {
            break;
        }
    }

    return result;
}

/*
 *  Helper recursive function for tarjan_check_dag
 */
bool Graph::tarjan_dag_check_util ( uint u, int disc[], int low[], std::stack < int > *st, bool stackMember[] ) {
    static int time = 0;

    disc[ u ] = low[ u ] = ++time;
    st->push ( u );
    stackMember[ u ] = true;
    bool result = true;

    for ( std::pair < uint, uint > edge : get_outbounds ( u )) {
        uint v = edge.first;

        if ( disc[ v ] == -1 ) {
            result = result && tarjan_dag_check_util ( v, disc, low, st, stackMember );

            low[ u ] = std::min ( low[ u ], low[ v ] );
        }

        else if ( stackMember[ v ] ) {
            low[ u ] = std::min ( low[ u ], disc[ v ] );
        }
    }

    uint w = 0;
    int c = 0;
    if ( low[ u ] == disc[ u ] ) {
        while ( st->top () != u ) {
            w = ( uint ) st->top ();
            c++;
            stackMember[ w ] = false;
            st->pop ();
        }

        w = ( uint ) st->top ();
        c++;
        stackMember[ w ] = false;
        st->pop ();

    }

    if ( c > 1 ) result = false;

    return result;
}

std::vector < uint > Graph::topological_sort () {
    Graph g ( *this );
    std::vector < uint > sorted;

    std::vector < uint > no_incoming;
    for ( uint i = 0; i < g._vertices.size (); i++ ) {
        if ( g._vertices[ i ]._inbound.size () == 0 ) {
            no_incoming.push_back ( i );
        }
    }

    while ( !no_incoming.empty ()) {
        uint v = no_incoming.front ();
        no_incoming.erase ( no_incoming.begin ());

        sorted.push_back ( v );

        for ( std::pair < uint, uint > edge : g.get_outbounds ( v )) {
            g.remove_edge ( v, edge.first );
            if ( g.get_inbounds ( edge.first ).size () == 0 ) {
                no_incoming.push_back ( edge.first );
            }
        }

    }
    if ( g.edge_count () != 0 ) {
        throw std::runtime_error ( "Graph is not DAG" );
    }

    return sorted;
}
