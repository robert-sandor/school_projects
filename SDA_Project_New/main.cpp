#include <iostream>
#include <vector>
#include "algorithm"
#include "fstream"
#include "sstream"
#include "ctime"
#include "sorted_list_dv.h"
#include "sorted_list_rbt.h"
#include "Balloon.h"

using namespace std;

/*
 *  Comment out to use the DynamicVector implementation
 *  Let it defined to use the Red-Black Tree implementation
 */
//#define USE_RBT

template<typename T>
#ifdef USE_RBT
using SortedList = SortedListRBT<T>;
#else
using SortedList = SortedListDV<T>;
#endif

/*
 *  Defined - Shows execution time
 *  Undefined - Doesn't show the execution time
 */
#define SHOW_EXEC_TIME

int main() {


#ifdef SHOW_EXEC_TIME
    clock_t ts = clock();
#endif

    SortedList<Balloon> slist;


    std::ifstream fin("balloons.txt", std::ios::in);

    if (!fin.good()) {
        throw runtime_error("File failed to open!");
    }

    // Read the file
    while (fin.good() && !fin.eof()) {
        std::string line;
        std::getline(fin, line);

        std::istringstream iss{line};
        int x, y;
        iss >> x;
        if (iss.eof()) {
            break;
        }
        iss >> y;
        unsigned r;
        iss >> r;

        slist.insert(Balloon {x, y, r});
    }

//    for (SortedList<Balloon>::iterator it(slist.begin()); !it.equal(slist.end()); it.next()) {
//        Balloon b = it.element();
//        std::cout << b.get_x() + (int) b.get_radius() << std::endl;
//    }

    std::cout << "Lines at positions (x = ) : ";

    // counts the lines
    unsigned int line_count = 0;
    // remember if a balloon is popped or not
    int *popped = (int *) calloc(slist.get_count(), sizeof(int));
    unsigned int pos = 0;
    // iterate over all the balloons
    for (SortedList<Balloon>::iterator it(slist.begin()); !it.equal(slist.end()); it.next()) {
        // if the balloon is not popped, draw the line
        if (!popped[pos]) {
            Balloon a = it.element();
            int line = a.get_x() + a.get_radius();

            std::cout << line << ", ";

            line_count++;
            // pop the current balloon
            popped[pos] = 1;

            // pop all balloons the line intersects
            unsigned int j = pos;
            for (SortedList<Balloon>::iterator it2(it); !it2.equal(slist.end()); it2.next()) {
                if (!popped[j]) {
                    Balloon b = it2.element();

                    if (b.get_x() - (int) b.get_radius() <= line &&
                        b.get_x() + (int) b.get_radius() >= line) {
                        popped[j] = 1;
                    }
                }
                j++;
            }
        }
        pos++;
    }

    cout << std::endl << "Line count : " << line_count << std::endl;

#ifdef SHOW_EXEC_TIME
    std::cout << "Time taken : " << (double) (clock() - ts) / CLOCKS_PER_SEC << std::endl;
#endif

    free(popped);

    return 0;
}
