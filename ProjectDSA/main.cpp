#include <iostream>
#include "SortedListDV.h"
#include "SortedListRBT.h"
#include "Balloon.h"

int main () {
    SortedListRBT < Balloon > tree;

    tree.add ( Balloon ( 2, 2, 1 ));
    tree.add ( Balloon ( 4, 0, 5 ));
    tree.add ( Balloon ( 6, 2, 2 ));
    tree.add ( Balloon ( 8, 4, 1 ));
    tree.add ( Balloon ( 10, 2, 2 ));

    return 0;
}