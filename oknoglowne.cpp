#include "oknoglowne.h"
#include "oknododajp.h"
#include "playlisty.h"
#include <QLabel>



Oknoglowne::Oknoglowne()
{

 this->setMinimumSize(800,1000);
    this->setMaximumSize(800,1000);

    //ustawienie tła okna
   QPixmap x(":/Tło/Tło/tło.jpg");
x=x.scaled(this->size(),Qt::IgnoreAspectRatio);
QPalette p;
p.setBrush(QPalette::Background,x);
this->setPalette(p);
Oknododajp*f=new Oknododajp();
//linia do ustawien
linia=new QFrame(this);
linia->setFrameShape(QFrame::VLine);
linia->setLineWidth(12);
linia->setFixedSize(linia->lineWidth(),this->height());
linia->setObjectName("liniaa");
linia->setStyleSheet("#liniaa{border:12px solid brown;}");
linia->move(600,0);
f->otworzbaze();
iletablicf();
stworzwyszukiwarkes();
fstworzmenu();



connect(this->dodajpiosenke,SIGNAL(clicked(bool)),this,SLOT(fdodajpiosenke()));
connect(this->wyszukiwarka,SIGNAL(textChanged(QString)),this,SLOT(przeszukajbazes(QString)));



}

Oknoglowne::stworzwyszukiwarkes()
{
   wyszukiwarka=new QLineEdit(this);
   wyszukiwarka->move(250,50);
   wyszukiwarka->setStyleSheet("QLineEdit{background-color:grey;}");
   model=new QStringListModel();

   wyszukanepiosenki=new QListView(this);
   wyszukanepiosenki->move(0,70);
   wyszukanepiosenki->setEditTriggers(QAbstractItemView::NoEditTriggers);
   wyszukanepiosenki->setStyleSheet("QListView{background-color:grey}");


wyszukanepiosenki->setModel(model);
connect(this->wyszukanepiosenki,SIGNAL(clicked(QModelIndex)),this,SLOT(tabelakilks(QModelIndex)));




}

Oknoglowne::fstworzmenu()
{


    QFont czdomenu("Arial",13,QFont::Bold);
    dodajpiosenke=new QPushButton(this);
    dodajpiosenke->setFont(czdomenu);
    dodajpiosenke->move(620,0);
    dodajpiosenke->setText("Dodaj Piosenke");
    dodajpiosenke->setStyleSheet("QPushButton{background-color:grey,color:blue}");

    stworzplayliste=new QPushButton(this);
    stworzplayliste->setFont(czdomenu);
    stworzplayliste->move(620,32);
    stworzplayliste->setText("Zarzadzanie \nplaylistami");
    stworzplayliste->setStyleSheet("QPushButton{background-color:grey,color:blue}");
    connect(this->stworzplayliste,SIGNAL(clicked(bool)),this,SLOT(zarzadzanieplaylistamis()));


return 0;
}



Oknoglowne::fdodajpiosenke()
{
  Oknododajp *p=new Oknododajp();
  p->show();
  return 0;

}

Oknoglowne::przeszukajbazes(QString x)
{
    //od 2 prawidlowych literek zacznie wyszukiawac
    QString z;

  QSqlQuery qry(QString("SELECT nazwa FROM piosenki WHERE nazwa like'%%0%' ").arg(x));
   if(qry.exec())
   {
       fieldNo=qry.record().indexOf("nazwa");
       while(qry.next())
       {
           qrywartosc=qry.value(fieldNo).toString();

       }

   }

   QSqlQuery qry3(QString("SELECT Sciezka FROM piosenki WHERE Sciezka like'%%0%' ").arg(x));
    if(qry3.exec())
    {
        fieldNo=qry3.record().indexOf("Sciezka");
        while(qry3.next())
        {
            qry3wartosc=qry3.value(fieldNo).toString();

        }


    }



   //dodaj do listview raz i nie powtarzaj usun gdy zniknie
   // przy calkowitym usunieciu tektsu wyzeruj tabelke ?
   int c=0;
   for(int i=0;i<iletablic;i++)
   {//dodaje do pojemnika 0 a powinno do kolejnego
       if(pojemniknapiosenki[i]!=qrywartosc)
       {
           c++;
       }

       if(c==iletablic)
       {
   pojemniknapiosenki[licznik]=qrywartosc;
   pojemniknasciezki[licznik]=qry3wartosc;
   model->insertRow(model->rowCount());
   QModelIndex index=model->index(model->rowCount()-1);
   model->setData(index,qrywartosc);
   licznik++;

       }
   }

// dodaje przed liczbe na podstawie ktorej znajduje w kontenerach
   //







}

Oknoglowne::iletablicf()
{

    // zrobic jakis warunek by bledu nie wywalilo
    QSqlQuery qry2("SELECT rowid from piosenki");
    bool ok;
    if(qry2.last())
    {
        iletablic=qry2.value(0).toInt(&ok);


    }
    if(!ok)
    {
   Globalne::Ostrzezenie=1;

    }
    else
    {
        // pomyslec nad externem

       Globalne::Ostrzezenie=0;

   pojemniknapiosenki=new QString[iletablic+1];
    pojemniknasciezki=new QString[iletablic+1];
    sciezkip=new QString[iletablic+1];
   nazwyp=new QString[iletablic+1];
    }





}

Oknoglowne::tabelakilks(QModelIndex in)
{
    wybrany=in.data(Qt::DisplayRole).toString();

    for(int i=0;i<iletablic;i++)
    { if(wybrany==pojemniknapiosenki[i])
        {
            sciezkadopiosenkipoklik=pojemniknasciezki[i];

        }

    }
    grajpiosenkes(sciezkadopiosenkipoklik);

}

Oknoglowne::zarzadzanieplaylistamis()
{
    iletablicf();
    if(Globalne::Ostrzezenie==1)
    {
        QMessageBox::information(this,"OSTRZEZENIE","BY KORZYSTAC Z ZARZADZANIA PLAYLISTAMI MUSISZ NAJPIERW DODAC PIOSENKI");
        return 0;
    }
    if(ktora>0)
    {
        p->close();
        ktora--;
    }
if(ktora==0)
{
   p=new Playlisty();


    int c=0;
    QSqlQuery qry4("SELECT Nazwa,Sciezka from piosenki ");
    while(qry4.next())
    {
        nazwyp[c]=qry4.value(0).toString();
        sciezkip[c]=qry4.value(1).toString();

        c++;
    }
       p->przekazbaze(nazwyp,sciezkip,iletablic);

       if(p->ilerowmaobecna>0)
       {
           qDebug()<<"ok";
       }


}

p->show();
ktora++;





}


Oknoglowne::tworzplayliste()
{

}

// po klik zarzadzanie playlistami
//okno 1.Obecne playlisty, 2. Stworz playliste
//nazwac przed i dodac gdzies
//po klik stworz to pojawia sie przycisk dodaj do playlisty kolo wyszukiwarki
//





