#include "datasource.h"

dataSource::dataSource(QList<person> list, QObject *parent)
    : QAbstractItemModel(parent), listP(list)
{
}

QVariant dataSource::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
    if(role != Qt::DisplayRole)
        return QVariant();

    if(orientation == Qt::Horizontal){
        if(section == 0){
            return QString("ID").arg(section);
        }
        else if(section == 1){
            return QString("Name").arg(section);
        }
        else{
            return QString("Age").arg(section);
        }
    }
    else{
        return QString("%1").arg(section);
    }
}

QModelIndex dataSource::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex dataSource::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int dataSource::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
    return listP.count();
}

int dataSource::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
    return 3;
}

QVariant dataSource::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if(index.row() >= listP.size())
        return QVariant();

    // FIXME: Implement me!
    if(role == Qt::DisplayRole)
        return listP.at(index.row());
    return QVariant();
}
