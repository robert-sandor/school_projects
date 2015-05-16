//
// Created by robert on 5/16/15.
//

#include "MainWindow.h"

void MainWindow::setUpUI () {
    // Create the horizontal box and set it as the central widget
    _mainHBox = new QHBoxLayout ( this );
    setLayout ( _mainHBox );

    // Create the left VBox and add it to the main HBox
    _leftVBox = new QVBoxLayout ( this );
    _mainHBox->addLayout ( _leftVBox );

    // Create the TableView and add it to the left VBox
    _tableView = new QTableView ( this );
    _leftVBox->addWidget ( _tableView );
}
