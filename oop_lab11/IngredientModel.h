//
// Created by robert on 5/22/15.
//

#ifndef OOP_LAB11_INGREDIENTMODEL_H
#define OOP_LAB11_INGREDIENTMODEL_H

#include "QAbstractTableModel"
#include "IngredientController.h"

class IngredientModel : public QAbstractTableModel {
Q_OBJECT
public:
    IngredientModel ( QObject * parent );

    int rowCount ( const QModelIndex & parent = QModelIndex ()) const;

    int columnCount ( const QModelIndex & parent = QModelIndex ()) const;

    QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;

    QVariant headerData ( int section, Qt::Orientation orientation, int role ) const;

    void set_data_source ( IngredientController * controller );

private:
    IngredientController * _controller;
};


#endif //OOP_LAB11_INGREDIENTMODEL_H
