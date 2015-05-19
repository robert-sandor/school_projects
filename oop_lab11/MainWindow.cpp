//
// Created by robert on 5/19/15.
//

#include "MainWindow.h"

/**
 *  TODO rearrange this code to be more easily readable
 */

void MainWindow::setupUI () {
    _mainLayout = new QHBoxLayout;
    _rightFormLayout = new QFormLayout;
    _leftBoxLayout = new QVBoxLayout;
    _table = new QTableView;
    _formActionsLayout = new QHBoxLayout;
    _addButton = new QPushButton ( tr ( "&Add" ));
    _updateButton = new QPushButton ( tr ( "&Update" ));
    _filterByValueLayout = new QHBoxLayout;
    _filterByNameLayout = new QHBoxLayout;
    _filterByValueLE = new QLineEdit;
    _filterByNameLE = new QLineEdit;
    _filterByNameButton = new QPushButton ( tr ( "Filter by Name" ));
    _filterByValueButton = new QPushButton ( tr ( "Filter by Value" ));
    _tableActionsLayout = new QHBoxLayout;
    _deleteButton = new QPushButton ( tr ( "&Delete" ));
    _showAllButton = new QPushButton ( tr ( "&Show All" ));


    // Id Line Edit and properties
    _idLineEdit = new QLineEdit;
    _nameLineEdit = new QLineEdit;
    _providerLineEdit = new QLineEdit;
    _quantityLineEdit = new QLineEdit;

    _leftBoxLayout->addWidget ( _table );
    _leftBoxLayout->addLayout ( _tableActionsLayout );
    _tableActionsLayout->addWidget ( _deleteButton );
    _tableActionsLayout->addWidget ( _showAllButton );

    // Left Form Layout
    _rightFormLayout->addRow ( tr ( "&Id:" ), _idLineEdit );
    _rightFormLayout->addRow ( tr ( "&Name:" ), _nameLineEdit );
    _rightFormLayout->addRow ( tr ( "&Provider:" ), _providerLineEdit );
    _rightFormLayout->addRow ( tr ( "&Quantity:" ), _quantityLineEdit );
    _rightFormLayout->addRow ( _formActionsLayout );
    _formActionsLayout->addWidget ( _addButton );
    _formActionsLayout->addWidget ( _updateButton );
    _rightFormLayout->addRow ( _filterByValueLayout );
    _filterByValueLayout->addWidget ( _filterByValueLE );
    _filterByValueLayout->addWidget ( _filterByValueButton );
    _rightFormLayout->addRow ( _filterByNameLayout );
    _filterByNameLayout->addWidget ( _filterByNameLE );
    _filterByNameLayout->addWidget ( _filterByNameButton );

    _mainLayout->addLayout ( _leftBoxLayout );
    _mainLayout->addLayout ( _rightFormLayout );

    setLayout ( _mainLayout );
}
