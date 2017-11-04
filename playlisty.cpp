#include "playlisty.h"
#include "oknododajp.h"
#include "globalne.h"

Playlisty::Playlisty()
{
    this->setMinimumSize(450,350);
    wyglad();




 //teraz wyswietlic i ladnie pokazac.



}

Playlisty::wyglad()
{
    // tu gdzie powinno odrazu wyszukiwac liste playlist obecnych
    //Obecne playlisty



    QFont pogrubienie("Arial",15,QFont::Bold);

    obecne=new QLabel(this);
    obecne->setText("Wybierz playliste");


    stworz=new QPushButton(this);
    stworz->setText("Stworz nowa");
    stworz->move(170,0);

    piosenki=new QLabel(this);
    piosenki->setText("Piosenki ");
    piosenki->move(295,0);
    piosenki->setFont(pogrubienie);

    connect(this->stworz,SIGNAL(clicked(bool)),this,SLOT(pokaztabeles()));


    listapiosenek=new QListView(this);
    listapiosenek->setMaximumSize(150,150);
    listapiosenek->move(5,20);
    playlisty=new QStringListModel();
    playlistywczytane=new QStringList();
   *playlistywczytane=Globalne::mojabaza1.tables();
    playlisty->setStringList(*playlistywczytane);
    listapiosenek->setModel(playlisty);
listapiosenek->setEditTriggers(QAbstractItemView::NoEditTriggers);

connect(this->listapiosenek,SIGNAL(clicked(QModelIndex)),this,SLOT(listviewplaylistykliks(QModelIndex)));









}



Playlisty::przekazbaze(QString nazwy[],QString sciezki[],int ile )
{
   ileprzenies=ile;
    zbiornikpiosenki=new QString[ile];
    zbiorniksciezki=new QString[ile];

    zbiornikpdobazy=new QString[ile];
    zbiorniksdobazy=new QString[ile];
    tabela=new QListView(this);
    tabela->setMaximumSize(200,200);
    tabela->move(240,30);
    model=new QStringListModel(this);
    tabela->setEditTriggers(QAbstractItemView::NoEditTriggers);



    for(int i=0;i<ile;i++)
    {
        model->insertRow(model->rowCount());

        QModelIndex index=model->index(model->rowCount()-1);
        model->setData(index,nazwy[i]);
        zbiorniksciezki[i]=sciezki[i];
        zbiornikpiosenki[i]=nazwy[i];

    }



    connect(this->tabela,SIGNAL(clicked(QModelIndex)),this,SLOT(tabelkakliks(QModelIndex)));
tabela->setModel(model);
tabela->hide();








// stworz podaje nazwe playlisty
}

Playlisty::pokaztabeles()
{
    podajnazweplaylisty=new QLineEdit(this);
    podajnazweplaylisty->move(240,250);
    podajnazweplaylisty->show();
    nazwap=new QLabel(this);
    nazwap->setText("Podaj nazwe playlisty: ");
    nazwap->move(230,230);
    nazwap->show();
    potwierdznazwe=new QPushButton(this);
    potwierdznazwe->setText("OK");
    potwierdznazwe->move(245,270);
   potwierdznazwe->show();


    connect(this->potwierdznazwe,SIGNAL(clicked(bool)),this,SLOT(tworzplaylistes()));




}

Playlisty::tworzplaylistes()
{
    podananazwa=podajnazweplaylisty->text();
    potwierdznazwe->hide();
    nazwap->hide();
    podajnazweplaylisty->hide();
    dodajpiosenki=new QPushButton(this);
    dodajpiosenki->move(160,50);
    dodajpiosenki->setText("Dodaj \n wybrane");
    dodajpiosenki->show();

    connect(this->dodajpiosenki,SIGNAL(clicked(bool)),this,SLOT(nowastworzonas()));
tabela->show();

}

Playlisty::nowastworzonas()
{





    QSqlQuery qry;
 qry.exec(QString("create table %0 ""(Nazwa TEXT,""Sciezka TEXT)").arg(podananazwa));


 QSqlQuery qry2;
for(int i=0;i<ilemaplaylista;i++)
{
 qry2.prepare(QString("INSERT INTO '%0' (nazwa,sciezka)""VALUES(:nazwa,:sciezka)").arg(podananazwa));
 qry2.bindValue(0,zbiornikpdobazy[i]);
 qry2.bindValue(1,zbiorniksdobazy[i]);
  qry2.exec();
}

playlisty->insertRow(playlisty->rowCount());
   QModelIndex index=playlisty->index(playlisty->rowCount()-1);
   playlisty->setData(index,podananazwa);
   listapiosenek->setModel(playlisty);



   //w przypadku kliku na jakas playliste wybiera ja z bazy
   //nastepnie pojawia sie okno edytuj/odtworz
   //po klik odtworz zacznie grac piosenka po piosence

 tabela->hide();
 dodajpiosenki->hide();
 ilemaplaylista=0;





}


Playlisty::tabelkakliks(QModelIndex in)
{
    kliknietapiosenka=new QString();
    *kliknietapiosenka=in.data(Qt::DisplayRole).toString();
    for(int i=0;i<ileprzenies;i++)
    {
        if(kliknietapiosenka!=zbiornikpdobazy)
        {
        if(kliknietapiosenka==zbiornikpiosenki[i])
        {
         zbiornikpdobazy[ilemaplaylista]=zbiornikpiosenki[i];
         zbiorniksdobazy[ilemaplaylista]=zbiorniksciezki[i];
          ilemaplaylista++;

        }
        }
    }




}

Playlisty::listviewplaylistykliks(QModelIndex k)
{


    Globalne::kliknietaplaylista=k.data(Qt::DisplayRole).toString();



QMessageBox msgBox;

odtworz=new QPushButton();
edytuj=new QPushButton();
usun=new QPushButton();
msgBox.setText(trUtf8("Co zrobic z playlista?"));
odtworz = msgBox.addButton(trUtf8("Odtworz"), QMessageBox::YesRole);
edytuj= msgBox.addButton(trUtf8("Edytuj"), QMessageBox::NoRole);
usun=msgBox.addButton(trUtf8("Usun"),QMessageBox::ApplyRole);
msgBox.setIcon(QMessageBox::Question);
msgBox.exec();

if(msgBox.clickedButton()==odtworz)
{
    odtworzs(Globalne::kliknietaplaylista);
}
if(msgBox.clickedButton()==edytuj)
{
    edytujs(Globalne::kliknietaplaylista);
}
if(msgBox.clickedButton()==usun)
{
    usuns(Globalne::kliknietaplaylista);

}


}

Playlisty::odtworzs(QString kliknietaplaylista)
{
   close();
   qDebug()<<kliknietaplaylista;
   QSqlQuery qry;
   qry.exec(QString("SELECT rowid from '%0'").arg(kliknietaplaylista));
   if(qry.last())
   {
   ilerowmaobecna=qry.value(0).toInt();
   }

   //pomyslec nad stworzeniem oddzielnej klasy na wzor grajpiosenke.cpp
   //ktora bedzie dzialac wszedzie

   qDebug()<<ilerowmaobecna;




}
Playlisty::edytujs(QString kliknietaplaylista)
{


}
Playlisty::usuns(QString kliknietaplaylista)
{
    QSqlQuery qry;
    qry.exec(QString("drop TABLE %0").arg(kliknietaplaylista));
    listapiosenek->setUpdatesEnabled(false);
    QModelIndexList indexes=listapiosenek->selectionModel()->selectedIndexes();
    qSort(indexes.begin(),indexes.end());

    qDebug()<<indexes;

    for(int i=indexes.count()-1;i>-1;i--)
    {
        playlisty->removeRow(indexes.at(i).row());
    }
    listapiosenek->setUpdatesEnabled(true);
}




