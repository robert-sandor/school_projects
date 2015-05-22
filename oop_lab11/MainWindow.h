//
// Created by robert on 5/19/15.
//

#ifndef OOP_LAB11_MAINWINDOW_H
#define OOP_LAB11_MAINWINDOW_H

#include "iostream"
#include "QtWidgets"
#include "IngredientController.h"
#include "IngredientModel.h"

class MainWindow : public QWidget {
Q_OBJECT

public:
    MainWindow ( QWidget * parent, const Qt::WindowFlags & f, IngredientController * con ) : QWidget ( parent, f ),
                                                                                             _controller ( con ) {
        setGeometry ( 0, 0, 880, 300 );
        setupUI ();
        setWindowTitle ( "Ingredient Store" );
    }

    virtual ~MainWindow () { }

//    void set_controller ( IngredientController * controller ) {
//        _controller = controller;
//    }

private slots:

    void add_clicked ();

    void update_clicked ();

    void show_all_clicked ();

    void delete_clicked ();

    void undo_clicked ();

    void selection_changed ( QModelIndex selected, QModelIndex deselected );

    void section_clicked ( int index );

    void filter_by_name_clicked ();

    void filter_by_quantity_clicked ();

private:
    void setupUI ();

    bool tableSorted;

    Ingredient _selectedIngredient;

    IngredientController * _controller;
    IngredientModel * _ingModel;
    QSortFilterProxyModel * _ingProxyModel;

    // Main Layout
    QHBoxLayout * _mainLayout;
    // Left & right layouts
    QVBoxLayout * _leftBoxLayout;
    QFormLayout * _rightFormLayout;

    // right layout - the form
    QLineEdit * _idLineEdit;
    QLineEdit * _nameLineEdit;
    QLineEdit * _providerLineEdit;
    QLineEdit * _quantityLineEdit;
    QHBoxLayout * _formActionsLayout;
    QPushButton * _addButton;
    QPushButton * _updateButton;
    QHBoxLayout * _filterByQuantityLayout;
    QLineEdit * _filterByQuantityLE;
    QPushButton * _filterByQuantityButton;
    QHBoxLayout * _filterByNameLayout;
    QLineEdit * _filterByNameLE;
    QPushButton * _filterByNameButton;

    // TableView
    QTableView * _table;
    QHBoxLayout * _tableActionsLayout;
    QPushButton * _deleteButton;
    QPushButton * _undoButton;
    QPushButton * _showAllButton;

};


#endif //OOP_LAB11_MAINWINDOW_H
