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

    Ingredient & get ( unsigned int index ) {
        return _data.at ( index );
    }

    void set_data ( const std::vector <Ingredient> & _data ) {
        IngredientModel::_data = _data;
        emit dataChanged ( index ( 0, 0 ), index (( int ) _data.size (), 3 ));
        emit layoutChanged ();
    }

private:
    IngredientController * _controller;
    std::vector <Ingredient> _data;
};


#endif //OOP_LAB11_INGREDIENTMODEL_H
