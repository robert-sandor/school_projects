#include "QtWidgets"
#include "MainWindow.h"
#include "IngredientFileRepository.h"
//#include <iostream>

using namespace std;

int main ( int argc, char ** argv ) {
    QApplication app ( argc, argv );

    IngredientFileRepository repo {"data.txt"};
    repo.load_file ();
    IngredientController con {&repo};

    MainWindow win ( NULL, 0, &con );
//    win.set_controller ( &con );

    win.show ();

    return app.exec ();
}