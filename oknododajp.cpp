#include "oknododajp.h"



Oknododajp::Oknododajp()
{
    this->setMinimumSize(700,400);
    this->setMaximumSize(700,400);

    sciezka=new QLineEdit(this);
    sciezka->setMinimumSize(255,20);
    //bedzie otwierac bazke tutaj


pokazpiosenki();



}


Oknododajp::pokazpiosenki()
{   QString patch="/";
    tv=new QTreeView(this);\
    dirmodel=new QFileSystemModel(this);
    tv->setModel(dirmodel);
    dirmodel->setFilter(QDir::NoDotAndDotDot|QDir::AllDirs);
    tv->hideColumn(1);
    tv->hideColumn(2);
    tv->hideColumn(3);
     dirmodel->setRootPath(patch);
    tv->show();


    filemodel=new QFileSystemModel(this);
     tv2=new QListView(this);
      tv2->move(350,0);
   filemodel->setFilter(QDir::NoDotAndDotDot|QDir::Files);
      tv2->setModel(filemodel);
     connect(this->tv,SIGNAL(clicked(QModelIndex)),this,SLOT(tvklik(QModelIndex)));
    connect(this->tv2,SIGNAL(clicked(QModelIndex)),this,SLOT(tv2klik(QModelIndex)));


}


Oknododajp::tvklik(QModelIndex index)
{
    QString patch2=dirmodel->fileInfo(index).absoluteFilePath();

    tv2->setRootIndex(filemodel->setRootPath(patch2));



}


Oknododajp::tv2klik(QModelIndex index)
{
    patchmuza=filemodel->fileInfo(index).absoluteFilePath();

    dodajp=new QPushButton(this);
    dodajp->setText("Dodaj");
    dodajp->move(400,200);
   dodajp->show();
   zmiennazwe=new QPushButton(this);
   zmiennazwe->setText("inna nazwa");
   zmiennazwe->move(475,200);
   zmiennazwe->show();




   connect(this->dodajp,SIGNAL(clicked(bool)),this,SLOT(dodajpiosenke()));
   connect(this->zmiennazwe,SIGNAL(clicked(bool)),this,SLOT(zmiennazwes()));


}

Oknododajp::zmiennazwes()
{

    zmiananazwy=new QLineEdit(this);
    zmiananazwy->move(450,250);
    zmienzatwierdz=new QPushButton(this);
    zmienzatwierdz->move(450,270);
    zmienzatwierdz->setText("OK");
    zmiananazwy->show();
    zmienzatwierdz->show();

    connect(this->zmienzatwierdz,SIGNAL(clicked(bool)),this,SLOT(zatwierdzs()));

}

Oknododajp::autonazwa()
{
    nazwapiosenki="";
    int dlugosc=patchmuza.length();
    int zmienna=0;

    for(int i=0;i<dlugosc;i++)
    {
        if(zmienna>1)
        {
            nazwapiosenki=nazwapiosenki+patchmuza[i];
        }
        if(patchmuza[i]=='/')
        {
            zmienna++;
        }


    }


}

Oknododajp::zatwierdzs()
{
     czyzmienia++;
    nazwapiosenki=zmiananazwy->text();
    zmiananazwy->close();
    zmienzatwierdz->close();



}
