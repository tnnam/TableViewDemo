#ifndef DATASOURCE_H
#define DATASOURCE_H

#include <QAbstractItemModel>
#include "person.h"
#include <QList>

class dataSource : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit dataSource(QList<person> list, QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    QList<person> listP;
};

#endif // DATASOURCE_H
