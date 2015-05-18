//
// Created by robert on 5/19/15.
//

#include "MainWindow.h"

void MainWindow::setupUI () {
    _mainLayout = new QHBoxLayout;
    _rightLayout = new QFormLayout;
    _leftLayout = new QVBoxLayout;
    _leftPlaceholder = new QWidget;
    _rightPlaceholder = new QWidget;
    _table = new QTableView;

    _leftLayout->addWidget ( _table );

    _rightPlaceholder->setLayout ( _rightLayout );
    _leftPlaceholder->setLayout ( _leftLayout );

    _mainLayout->addWidget ( _leftPlaceholder );
    _mainLayout->addWidget ( _rightPlaceholder );

    setLayout ( _mainLayout );
}
