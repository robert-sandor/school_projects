//
// Created by robert on 5/22/15.
//

#include "IngredientModel.h"

IngredientModel::IngredientModel ( QObject * parent ) : QAbstractTableModel ( parent ) {

}

int IngredientModel::rowCount ( const QModelIndex & ) const {
    return ( int ) _data.size ();
}

int IngredientModel::columnCount ( const QModelIndex & ) const {
    return 4;
}

QVariant IngredientModel::data ( const QModelIndex & index, int role ) const {
    if ( role == Qt::DisplayRole ) {
        Ingredient ing = _data.at (( unsigned ) index.row ());
        switch ( index.column ()) {
            case 0: {
                return QString ( "%1" ).arg ( ing.get_id ());
            }
            case 1: {
                return QString::fromUtf8 ( ing.get_name ().c_str ());
            }
            case 2: {
                return QString::fromUtf8 ( ing.get_provider ().c_str ());
            }
            case 3: {
                return QString ( "%1" ).arg ( ing.get_quantity ());
            }
            default: {
                return QVariant {};
            }
        }
    }
    return QVariant {};
}

QVariant IngredientModel::headerData ( int section, Qt::Orientation orientation, int role ) const {
    if ( role == Qt::DisplayRole ) {
        if ( orientation == Qt::Horizontal ) {
            switch ( section ) {
                case 0: {
                    return QString {"ID"};
                }
                case 1: {
                    return QString {"Name"};
                }
                case 2: {
                    return QString {"Provider"};
                }
                case 3: {
                    return QString {"Quantity"};
                }
                default: {
                    return QVariant {};
                }
            }
        } else if ( orientation == Qt::Vertical ) {
            return QString ( "%1" ).arg ( section + 1 );
        }
    }
    return QVariant {};
}
