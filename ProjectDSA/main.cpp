#include <iostream>
#include "SortedListDV.h"
#include "SortedListRBT.h"

int main () {
    SortedListRBT < int > list;

    list.add(15);
    list.add(8);
    list.add(10);
    list.add(12);
    list.add(18);
    list.add(25);
    list.add(20);

    return 0;
}