#include <iostream>
#include "SortedListDV.h"

int main () {
    SortedListDV < int > list;

    list.add ( 5 );
    list.add ( 3 );
    list.add ( 7 );
    list.add ( 10 );
    list.add ( 2 );

    list.remove_from_index ( list.get_count () - 1 );

    SortedListDV < int >::iterator it = list.begin ();

    list.remove (it);

    std::cout << *it << std::endl;

    SortedListDV < int >::iterator it2 = list.end ();

    std::cout << *it2 << " " << (( it == it2 ) ? "true" : "false" ) << std::endl;

    return 0;
}