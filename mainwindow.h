#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QString>
#include <QtXml>
#include <QFile>
#include <QXmlStreamAttribute>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    struct person
    {
        int ID, age;
        string name;
    };
    QList<person> listP;
    QString xmlFileName = "C:/Users/hp/Desktop/DemoXml3.xml";
    void DocFile(QList<person> list, QString);
    void GhiFile(QList<person> list, QString);
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
