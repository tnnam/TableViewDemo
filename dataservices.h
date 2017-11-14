#ifndef DATASERVICES_H
#define DATASERVICES_H

#include "person.h"
#include <QList>
#include <QObject>
#include <QString>
#include <QtXml>
#include <QFile>
#include <QMessageBox>
#include <QXmlStreamAttribute>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>

class DataServices
{
public:
    DataServices();
    QList<person> DocFile(QString);
    void GhiFile(QList<person> list, QString);
};

#endif // DATASERVICES_H
