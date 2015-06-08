#include <iostream>
#include <fstream>
#include "algorithm"
#include "vector"
#include "map"
#include "ctime"
#include "Graph.h"
#include "stack"
#include "climits"

typedef unsigned int uint;

void highest_cost_path ( const Graph & g, const uint & from, const uint & to, const std::vector < uint > & tsorted ) {
    std::vector < uint > dist ( tsorted.size ());
    std::vector < uint > pred ( tsorted.size ());

    for ( uint i = 0; i < tsorted.size (); i++ ) {
        dist[ i ] = 0;
        pred[ i ] = UINT_MAX;
    }

    for ( uint u : tsorted ) {
        for ( std::pair < uint, uint > edge : g.get_outbounds ( u )) {
            uint v = edge.first;

            if ( dist[ v ] < dist[ u ] + edge.second ) {
                dist[ v ] = dist[ u ] + edge.second;
                pred[ v ] = u;
            }
        }
    }

    std::vector < uint > path;
    uint u = to;
    while ( pred[ u ] != UINT_MAX) {
        path.push_back ( u );
        u = pred[ u ];
    }
    path.push_back ( u );

    if ( path.size () > 1 ) {
        std::reverse ( path.begin (), path.end ());
        for ( uint v : path ) {
            std::cout << v << " -> ";
        }
    } else {
        std::cout << "There is not path between " << from << " and " << to << "!\n";
    }
}

void gen_graph ( uint v, uint e ) {
    Graph g { v };
    std::ofstream fout ( "graph.txt", std::ios::out | std::ios::trunc );

    fout << v << " " << e << std::endl;

    uint gen = 0;
    while ( gen < e ) {
        uint x = rand () % v;
        uint y = rand () % v;
        uint cost = (( unsigned ) rand ()) % 100;

        if ( g.get_outbounds ( x ).find ( y ) == g.get_outbounds ( x ).end ()) {
            g.add_edge ( x, y, cost );
            fout << x << " " << y << " " << cost << std::endl;
            gen++;
        }
    }
}

int main () {

    gen_graph ( 25, 100 );


    time_t stime = clock ();

    std::ifstream fin ( "graph.txt", std::ios::in );
    if ( !fin.good ()) {
        std::cerr << "File not found!" << std::endl;
        exit ( -1 );
    }

    uint number_of_vertices;
    uint number_of_edges;
    fin >> number_of_vertices;
    fin >> number_of_edges;

    Graph g { number_of_vertices };

    for ( uint i = 0; i < number_of_edges; i++ ) {
        uint to, from, cost;
        fin >> from >> to >> cost;
        g.add_edge ( from, to, cost );
    }

    if ( g.tarjan_dag_check ()) {
        std::cout << "The graph is a DAG!\n";
        std::vector < uint > tsorted = g.topological_sort ();
        highest_cost_path ( g, 0, 24, tsorted );
    }
    else {
        std::cout << "The graph is not a DAG!\n";
    }
    std::cout << std::endl;

    std::cout << "Execution time : " << ( double ) ( clock () - stime ) / CLOCKS_PER_SEC << std::endl;

    return 0;
}