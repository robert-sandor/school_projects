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
    _table->setSelectionBehavior ( QAbstractItemView::SelectRows );
    _table->setSortingEnabled ( true );
    _ingModel = new IngredientModel {NULL};
    _ingModel->set_data ( _controller->getAllIngredients ());
    _ingProxyModel = new QSortFilterProxyModel;
    _ingProxyModel->setSourceModel ( _ingModel );
    _table->setModel ( _ingModel );
    _formActionsLayout = new QHBoxLayout;
    _addButton = new QPushButton ( tr ( "&Add" ));
    _updateButton = new QPushButton ( tr ( "&Update" ));
    _filterByQuantityLayout = new QHBoxLayout;
    _filterByNameLayout = new QHBoxLayout;
    _filterByQuantityLE = new QLineEdit;
    _filterByNameLE = new QLineEdit;
    _filterByNameButton = new QPushButton ( tr ( "Filter by Name" ));
    connect ( _filterByNameButton, SIGNAL ( clicked ()), this, SLOT( filter_by_name_clicked ()));
    _filterByQuantityButton = new QPushButton ( tr ( "Filter by Value" ));
    connect ( _filterByQuantityButton, SIGNAL( clicked ()), this, SLOT( filter_by_quantity_clicked ()));
    _tableActionsLayout = new QHBoxLayout;
    _deleteButton = new QPushButton ( tr ( "&Delete" ));
    connect ( _deleteButton, SIGNAL( clicked ()), this, SLOT( delete_clicked ()));
    _undoButton = new QPushButton ( tr ( "&Undo" ));
    connect ( _undoButton, SIGNAL( clicked ()), this, SLOT( undo_clicked ()));
    _showAllButton = new QPushButton ( tr ( "&Show All" ));
    connect ( _showAllButton, SIGNAL ( clicked ()), this, SLOT( show_all_clicked ()));

    // Id Line Edit and properties
    _idLineEdit = new QLineEdit;
    _nameLineEdit = new QLineEdit;
    _providerLineEdit = new QLineEdit;
    _quantityLineEdit = new QLineEdit;

    _leftBoxLayout->addWidget ( _table );
    _leftBoxLayout->addLayout ( _tableActionsLayout );
    _tableActionsLayout->addWidget ( _deleteButton );
    _tableActionsLayout->addWidget ( _undoButton );
    _tableActionsLayout->addWidget ( _showAllButton );

    // Left Form Layout
    _rightFormLayout->addRow ( tr ( "&Id:" ), _idLineEdit );
    _rightFormLayout->addRow ( tr ( "&Name:" ), _nameLineEdit );
    _rightFormLayout->addRow ( tr ( "&Provider:" ), _providerLineEdit );
    _rightFormLayout->addRow ( tr ( "&Quantity:" ), _quantityLineEdit );
    _rightFormLayout->addRow ( _formActionsLayout );
    _formActionsLayout->addWidget ( _addButton );
    connect ( _addButton, SIGNAL ( clicked ()), this, SLOT ( add_clicked ()));
    _formActionsLayout->addWidget ( _updateButton );
    connect ( _updateButton, SIGNAL( clicked ()), this, SLOT ( update_clicked ()));
    _rightFormLayout->addRow ( _filterByQuantityLayout );
    _filterByQuantityLayout->addWidget ( _filterByQuantityLE );
    _filterByQuantityLayout->addWidget ( _filterByQuantityButton );
    _rightFormLayout->addRow ( _filterByNameLayout );
    _filterByNameLayout->addWidget ( _filterByNameLE );
    _filterByNameLayout->addWidget ( _filterByNameButton );

    _mainLayout->addLayout ( _leftBoxLayout );
    _mainLayout->addLayout ( _rightFormLayout );

    setLayout ( _mainLayout );
    connect ( _table->selectionModel (), SIGNAL ( currentRowChanged ( QModelIndex, QModelIndex )), this,
              SLOT ( selection_changed ( QModelIndex, QModelIndex )));
    connect ( _table->horizontalHeader (), SIGNAL( sectionClicked ( int )), this,
              SLOT( section_clicked ( int )));
}

void MainWindow::show_all_clicked () {
    _ingModel->set_data ( _controller->getAllIngredients ());
}

void MainWindow::filter_by_name_clicked () {
    std::string s = _filterByNameLE->text ().toStdString ();
    _ingModel->set_data ( _controller->getFilteredByName ( s ));
}

void MainWindow::filter_by_quantity_clicked () {
    std::string s = _filterByQuantityLE->text ().toStdString ();
    unsigned int q = ( unsigned ) std::atoi ( s.c_str ());
    _ingModel->set_data ( _controller->getFilteredByQuantity ( q ));
}

void MainWindow::add_clicked () {
    // get id
    std::string ids = _idLineEdit->text ().toStdString ();
    unsigned int id;
    if ( std::atoi ( ids.c_str ()) < 0 ) {
        id = 0;
    } else {
        id = ( unsigned ) std::atoi ( ids.c_str ());
    }

    // get name and provider
    std::string name = _nameLineEdit->text ().toStdString ();
    std::string provider = _providerLineEdit->text ().toStdString ();

    // get quantity
    std::string quantitys = _quantityLineEdit->text ().toStdString ();
    unsigned int quantity;
    if ( std::atoi ( quantitys.c_str ()) < 0 ) {
        quantity = 0;
    } else {
        quantity = ( unsigned ) std::atoi ( quantitys.c_str ());
    }

    try {
        _controller->addIngredient ( id, name, provider, quantity );
    } catch ( std::runtime_error & e ) {
        QMessageBox errorMsgBox {};
        QString message {"Error while adding : "};
        message.append ( QString::fromUtf8 ( e.what ()));
        errorMsgBox.setText ( message );
        errorMsgBox.setIcon ( QMessageBox::Warning );
        errorMsgBox.exec ();
        return;
    }

    _ingModel->set_data ( _controller->getAllIngredients ());
}

void MainWindow::update_clicked () {
// get id
    std::string ids = _idLineEdit->text ().toStdString ();
    unsigned int id;
    if ( std::atoi ( ids.c_str ()) < 0 ) {
        id = 0;
    } else {
        id = ( unsigned ) std::atoi ( ids.c_str ());
    }

    // get name and provider
    std::string name = _nameLineEdit->text ().toStdString ();
    std::string provider = _providerLineEdit->text ().toStdString ();

    // get quantity
    std::string quantitys = _quantityLineEdit->text ().toStdString ();
    unsigned int quantity;
    if ( std::atoi ( quantitys.c_str ()) < 0 ) {
        quantity = 0;
    } else {
        quantity = ( unsigned ) std::atoi ( quantitys.c_str ());
    }

    try {
        _controller->updateIngredient ( id, name, provider, quantity );
    } catch ( std::runtime_error & e ) {
        QMessageBox errorMsgBox {};
        QString message {"Error while updating : "};
        message.append ( QString::fromUtf8 ( e.what ()));
        errorMsgBox.setText ( message );
        errorMsgBox.setIcon ( QMessageBox::Warning );
        errorMsgBox.exec ();
        return;
    }

    _ingModel->set_data ( _controller->getAllIngredients ());
}

void MainWindow::selection_changed ( QModelIndex selected, QModelIndex ) {
    _selectedIngredient = _ingModel->get (( unsigned ) selected.row ());

    _idLineEdit->setText ( QString ( "%1" ).arg ( _selectedIngredient.get_id ()));
    _nameLineEdit->setText ( QString::fromStdString ( _selectedIngredient.get_name ()));
    _providerLineEdit->setText ( QString::fromStdString ( _selectedIngredient.get_provider ()));
    _quantityLineEdit->setText ( QString ( "%1" ).arg ( _selectedIngredient.get_quantity ()));
}

void MainWindow::delete_clicked () {
    try {
        _controller->removeIngredient ( _selectedIngredient.get_id ());
    } catch ( std::runtime_error & e ) {
        QMessageBox errorMsgBox {};
        QString message {"Error while deleting : "};
        message.append ( QString::fromUtf8 ( e.what ()));
        errorMsgBox.setText ( message );
        errorMsgBox.setIcon ( QMessageBox::Warning );
        errorMsgBox.exec ();
        return;
    }

    _ingModel->set_data ( _controller->getAllIngredients ());
}

void MainWindow::undo_clicked () {
    try {
        _controller->undo ();
    } catch ( std::runtime_error & e ) {
        QMessageBox errorMsgBox {};
        QString message {"Error while undoing : "};
        message.append ( QString::fromUtf8 ( e.what ()));
        errorMsgBox.setText ( message );
        errorMsgBox.setIcon ( QMessageBox::Warning );
        errorMsgBox.exec ();
        return;
    }

    _ingModel->set_data ( _controller->getAllIngredients ());
}

void MainWindow::section_clicked ( int index ) {
    if ( tableSorted ) {
        _table->reset ();
    } else {
        _table->sortByColumn ( index, Qt::AscendingOrder );
    }
}
