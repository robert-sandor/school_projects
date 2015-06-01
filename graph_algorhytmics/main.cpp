#include <iostream>
#include "vector"
#include "map"
#include "Graph.h"

unsigned int backwards_dijkstra ( Graph graph, unsigned int to, unsigned int from ) {
    std::vector < unsigned int > dist ( graph.get_size (), UINTMAX_MAX);
    dist[ from ] = 0;

    std::vector < int > prev ( graph.get_size (), -1 );
    std::vector < unsigned int > visited;
    std::vector < unsigned int > queue;

    queue.push_back ( from );
    while ( !queue.empty ()) {

        // find the vertex in the queue which has the min dist
        std::vector < unsigned int >::iterator it;
        {
            unsigned int min = UINTMAX_MAX;
            for ( it = queue.begin (); it != queue.end (); ++it ) {
                if ( dist[ *it ] < min ) {
                    min = dist[ *it ];
                }
            }
        }

        queue.erase ( it );
        visited.push_back ( *it );
    }

}

int main () {
    Graph g { 4 };

    g.add_edge ( 0, 1, 10 );
    g.add_edge ( 0, 2, 20 );
    g.add_edge ( 0, 3, 33 );
    g.add_edge ( 2, 3, 30 );

    std::cout << "Outbound neighbors of 0 are : \n";
    std::map < unsigned int, unsigned int >::const_iterator it;
    for ( it = g.get_outbounds ( 0 ).begin (); it != g.get_outbounds ( 0 ).end (); ++it ) {
        std::cout << it->first << " " << it->second << std::endl;
    }

    std::cout << "Inbound neighbors of 3 are : \n";
    for ( it = g.get_inbounds ( 3 ).begin (); it != g.get_inbounds ( 3 ).end (); ++it ) {
        std::cout << it->first << " " << it->second << std::endl;
    }

    g.remove_edge ( 1, 2 );
    g.modify_cost ( 0, 3, 100 );

    std::cout << "Outbound neighbors of 0 are : \n";
    for ( it = g.get_outbounds ( 0 ).begin (); it != g.get_outbounds ( 0 ).end (); ++it ) {
        std::cout << it->first << " " << it->second << std::endl;
    }

    return 0;
}