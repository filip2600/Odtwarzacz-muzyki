#ifndef PLAYLISTY_H
#define PLAYLISTY_H

#include "globalne.h"
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QObject>
#include <QListView>
#include <qdebug.h>
#include <QStringListModel>
#include <QFont>
#include <QStringListModel>
#include <QLineEdit>
#include <QMessageBox>


class Playlisty:public QWidget
{
    Q_OBJECT
public:
    Playlisty();
    wyglad();
    przekazbaze(QString nazwy[],QString sciezki[],int ile);
       //QString*kliknietaplaylista;
    int ilerowmaobecna=0;

public slots:
    pokaztabeles();
    tworzplaylistes();
    nowastworzonas();
    tabelkakliks(QModelIndex in);
    listviewplaylistykliks(QModelIndex k);
    odtworzs(QString kliknietaplaylista);
    edytujs(QString klikenitaplaylista);
    usuns(QString kliknietaplaylista);




private:
    QLabel*obecne;
    QPushButton*stworz;
    QListView*tabela;
    QListView*listapiosenek;
    QStringListModel*f;
    QLabel*piosenki;
    QStringListModel*model;
    QStringListModel*playlisty;
    QString*nazwaplaylisty;
    QLineEdit*podajnazweplaylisty;
    QLabel*nazwap;
    QPushButton*potwierdznazwe;
    QString podananazwa;
    QPushButton*dodajpiosenki;
    QLabel*dodana;
    QString*kliknietapiosenka;
    QString*zbiornikpiosenki;
    QString*zbiorniksciezki;
    QString*zbiornikpdobazy;
    QString*zbiorniksdobazy;
    QStringList*playlistywczytane;
    int ilemaplaylista=0;
    int ileprzenies;
   QPushButton*edytuj;
   QPushButton*odtworz;
   QPushButton*usun;

   QMessageBox*box;

   //odtwarzanie



   //edycja



   //usuwanie




};


//podaje nazwe po ok pokazuje sie podkreslona z boku i wybieramy piosenki
//ktorych nazwy pokazuja sie w rogu.
#endif // PLAYLISTY_H
