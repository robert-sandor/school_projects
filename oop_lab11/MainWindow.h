//
// Created by robert on 5/19/15.
//

#ifndef OOP_LAB11_MAINWINDOW_H
#define OOP_LAB11_MAINWINDOW_H


#include <QtWidgets/qwidget.h>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qformlayout.h>
#include <QtWidgets/qtableview.h>

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
    // Left & right placeholders
    QWidget * _leftPlaceholder;
    QWidget * _rightPlaceholder;
    // Left & right layouts
    QVBoxLayout * _leftLayout;
    QFormLayout * _rightLayout;
    // TableView
    QTableView * _table;
};


#endif //OOP_LAB11_MAINWINDOW_H
