//
// Created by robert on 5/27/15.
//

#ifndef GRAPH_ALGORHYTMICS_GRAPH_H
#define GRAPH_ALGORHYTMICS_GRAPH_H

#include "vector"
#include "map"


class Graph {
public:
    Graph ( unsigned int number_of_vertices );

    virtual ~Graph () { }

    void add_edge ( const unsigned int & from, const unsigned int & to, const unsigned int & cost );

    void remove_edge ( const unsigned int & from, const unsigned int & to );

    void modify_cost ( const unsigned int & from, const unsigned int & to, const unsigned int & cost );

    const std::map < unsigned int, unsigned int > & get_outbounds ( const unsigned int & from ) const;

    const std::map < unsigned int, unsigned int > & get_inbounds ( const unsigned int & to ) const;

    unsigned int get_size () const {
        return _size;
    }

private:

    class Vertex {
    public:
        std::map < unsigned int, unsigned int > _inbound;
        std::map < unsigned int, unsigned int > _outbound;
    };

private:
    std::vector < Vertex > _vertices;
    unsigned int _size;
};


#endif //GRAPH_ALGORHYTMICS_GRAPH_H
