#ifndef GRAJ_H
#define GRAJ_H

#include <QFrame>
#include <QMediaPlayer>
#include <QDebug>
#include <QListView>
#include <QPushButton>
#include <QLabel>
#include <QDialog>
#include <QWidget>

class Graj:public QDialog
{
    Q_OBJECT
public:
    Graj(QWidget*parent=0);
    Graj2(QString sciezka,QString wybrany);


    int czygrane=0;
    int ktoryutwor=0;
    int f=0;
    int zeropjedeno;
    QPixmap odtworz;
    QPixmap pauza;
    QPushButton*klikodtworzpauza;
    QString obecnasciezka;
    QSlider*slider;
    QMediaPlayer*player;
    QString wybrany;
    QFrame*ramka;
    QWidget*parencik;

public slots:
   zmienionapozycjas(qint64 position);
    zmienionyczass(qint64 position);
    edytujramkes();
    stworzramkes(QString wybrany);




};

#endif // GRAJ_H
