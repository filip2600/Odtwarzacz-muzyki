#include "oknododajp.h"
Oknododajp::otworzbaze()
{

    mojabaza=QSqlDatabase::addDatabase("QSQLITE");
    mojabaza.setDatabaseName("C:/Users/filip/Desktop/bazydanych/piosenkipobrane.sqlite");
    if(mojabaza.open())
    {

    }

//qry.exec(QString("create table %0 ""(nazwa TEXT").arg(podananazwa));
    //wykona swoje i zamknie bazke
    Globalne::mojabaza1=mojabaza;
}


Oknododajp::dodajpiosenke()
{
    if(czyzmienia==0)
    {
        autonazwa();
    }
    else
    {
        czyzmienia--;
    }

    QSqlQuery qry;
    qry.prepare("INSERT INTO piosenki (Nazwa,Sciezka) "
                "VALUES (:Nazwa,:Sciezka)");
    qry.bindValue(":Nazwa",nazwapiosenki);
    qry.bindValue(":Sciezka",patchmuza);
    qry.exec();

    Globalne::Ostrzezenie=0;

    //tu musi sprawdzac ile row.



//nazwapiosenki="";

}






