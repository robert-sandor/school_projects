//
// Created by robert on 5/16/15.
//

#ifndef OOP_LAB11_MAINWINDOW_H
#define OOP_LAB11_MAINWINDOW_H

#include "QtWidgets"

class MainWindow : public QMainWindow {
public:
    MainWindow ( QWidget * parent = NULL, const Qt::WindowFlags & flags = 0 ) : QMainWindow ( parent, flags ) { }

    virtual ~MainWindow () { }

private:
    void setUpUI ();

    // UI components
    QHBoxLayout * _mainHBox;
    QVBoxLayout * _leftVBox;
    QTableView * _tableView;

};


#endif //OOP_LAB11_MAINWINDOW_H
