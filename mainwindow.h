#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QObject>
#include <QString>
#include <QtXml>
#include <QFile>
#include <QMessageBox>
#include <QXmlStreamAttribute>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QModelIndex>
#include <QStandardItem>
#include <QStandardItemModel>
#include "person.h"
#include "dataservices.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_addButton_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *model;
    DataServices data;
    QList<person> listP;
    QString xmlFileName = "/Users/nam/TableViewDemo/DemoXml3.xml";
    void setModelForTableView();
};

#endif // MAINWINDOW_H
