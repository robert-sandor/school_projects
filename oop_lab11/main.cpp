#include "QtWidgets"
#include "MainWindow.h"
//#include <iostream>

using namespace std;

int main ( int argc, char ** argv ) {
    QApplication app ( argc, argv );

    MainWindow win ( NULL, 0 );

    win.show ();

    return app.exec ();
}