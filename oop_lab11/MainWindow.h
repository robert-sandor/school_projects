//
// Created by robert on 5/19/15.
//

#ifndef OOP_LAB11_MAINWINDOW_H
#define OOP_LAB11_MAINWINDOW_H


#include "QtWidgets"

class MainWindow : public QWidget {
Q_OBJECT

public:
    MainWindow ( QWidget * parent, const Qt::WindowFlags & f ) : QWidget ( parent, f ) {
        setupUI ();
        setWindowTitle ( "Ingredient Store" );
    }

    virtual ~MainWindow () { }

private:
    void setupUI ();

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
    QHBoxLayout * _filterByValueLayout;
    QLineEdit * _filterByValueLE;
    QPushButton * _filterByValueButton;
    QHBoxLayout * _filterByNameLayout;
    QLineEdit * _filterByNameLE;
    QPushButton * _filterByNameButton;

    // TableView
    QTableView * _table;
    QHBoxLayout * _tableActionsLayout;
    QPushButton * _deleteButton;
    QPushButton * _showAllButton;

};


#endif //OOP_LAB11_MAINWINDOW_H
