#ifndef OKNODODAJP_H
#define OKNODODAJP_H
#include "globalne.h"
#include <QWidget>
#include <QDir>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QDebug>
#include <QFileSystemModel>
#include <QListView>
#include <QTreeView>
#include <QHeaderView>
#include <QtSql>
#include <QSqlQuery>


class Oknododajp:public QWidget
{
    Q_OBJECT
public:
    Oknododajp();
    QLineEdit*sciezka;
    QTreeView*tv;
    QListView*tv2;
    QFileSystemModel*dirmodel;
    QFileSystemModel*filemodel;

public slots:
    pokazpiosenki();
    otworzbaze();
    dodajpiosenke();
    tvklik(QModelIndex index);
    tv2klik(QModelIndex index);
    zmiennazwes();
    zatwierdzs();
    autonazwa();

private:
    QString patchmuza;
    QString nazwapiosenki;
    QPushButton*dodajp;
    QPushButton*zmiennazwe;
    QSqlDatabase mojabaza;
    QLineEdit*zmiananazwy;
    QPushButton*zmienzatwierdz;

    int czyzmienia=0;


};

#endif // OKNODODAJP_H
