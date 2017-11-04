#ifndef OKNOGLOWNE_H
#define OKNOGLOWNE_H
#include "playlisty.h"
#include "globalne.h"
#include "graj.h"
#include <QWidget>
#include <QFrame>
#include <QPushButton>
#include <QDebug>
#include <QLineEdit>
#include <QListview>
#include <QStringListModel>
#include <QAbstractItemView>
#include <QLabel>
#include <QPixmap>
#include <QIcon>
#include <QMessageBox>
#include <QSlider>


//pracowac caly czas nad playlisty odtworz
//dodac opcje przewijania dalej za pomoca slidera

class Oknoglowne:public QWidget
{
    Q_OBJECT
public:
    Oknoglowne();
fstworzmenu();
iletablicf();
public slots:
    fdodajpiosenke();
    stworzwyszukiwarkes();
    przeszukajbazes(QString x);
    tabelakilks(QModelIndex in);
    tworzplayliste();


    //zarzadzanie playlistami
    zarzadzanieplaylistamis();


private:
    //tworzenie okna glownego
    QFrame*linia;
    QLineEdit*wyszukiwarka;
    QPushButton*dodajpiosenke;
    QListView*wyszukanepiosenki;
    QPushButton*stworzplayliste;


    //baza piosenek
    QStringListModel*model;
  QString qrywartosc;
  QString qry3wartosc;
    int fieldNo;
    int iletablic;
    QString*pojemniknapiosenki;
    QString*pojemniknasciezki;
    QString wybrany;
    QString sciezkadopiosenkipoklik;
    int licznik=0;
    //grajpiosenke.cpp
    QMediaPlayer*player;
    int ktoreodt=0;
    Graj*g;




    //stworz playliste
    Playlisty*p;
    QString*sciezkip;
    QString*nazwyp;

    int ktora=0;






};



#endif // OKNOGLOWNE_H
