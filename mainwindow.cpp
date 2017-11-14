#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dataservices.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new QStandardItemModel();
    listP = data.DocFile(xmlFileName);
    setModelForTableView();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::setModelForTableView(){
    model->setHorizontalHeaderItem(0, new QStandardItem("ID"));
    model->setHorizontalHeaderItem(1, new QStandardItem("Name"));
    model->setHorizontalHeaderItem(2, new QStandardItem("Age"));
    for(int i = 0; i < listP.count(); i++){
        person a = listP.at(i);
        int ID = a.ID;
        QStandardItem *iID = new QStandardItem(QString("") + QString::number(ID));
        QString name = a.name;
        QStandardItem *iName = new QStandardItem(QString("") + name);
        int age = a.age;
        QStandardItem *iAge = new QStandardItem(QString("") + QString::number(age));
        model->setItem(i, 0, iID);
        model->setItem(i, 1, iName);
        model->setItem(i, 2, iAge);
        ui->tableView->setModel(model);
    }
}

void MainWindow::on_addButton_clicked()
{
    person a;
    a.ID = ui->idLineEdit->text().toInt();
    a.name = ui->nameLineEdit->text();
    a.age = ui->ageLineEdit->text().toInt();
    listP.append(a);
    data.GhiFile(listP, xmlFileName);
    setModelForTableView();
}
