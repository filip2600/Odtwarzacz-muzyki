#include "oknoglowne.h"


//Oknoglowne::grajpiosenkes(QString sciezka)
//{

// if(f==0)
// {
//     obecnasciezka=sciezka;
// }

//    if(sciezka!=obecnasciezka)
//    {
//        player->stop();
//        ktoryutwor=0;
//        czygrane=0;
//    }
//    if(ktoryutwor==0)
//    {
//        obecnasciezka=sciezka;
//    }
//    if(czygrane>0)
//    {
//        player->stop();
//    }
//   player=new QMediaPlayer(this);
//   player->setMedia(QUrl::fromLocalFile(sciezka));
//   player->play();
//   if(czygrane==0)
//   {
//       stworzramkes(wybrany);
//   }
//   if(czygrane>0)
//   {
//       edytujramkes();
//   }
//   connect(player,&QMediaPlayer::positionChanged,this,&Oknoglowne::zmienionapozycjas);
//   connect(player,&QMediaPlayer::durationChanged,this,&Oknoglowne::zmienionyczass);


//czygrane++;
//ktoryutwor++;
//f++;


//}

//Oknoglowne::stworzramkes(QString wybrany)
//{
//    ramka=new QFrame(this);
//    klikodtworzpauza=new QPushButton(ramka);
//    klikodtworzpauza->move(110,90);
//    ramka->move(150,350);
//    ramka->setMinimumSize(300,300);
//    QLabel*nazwapiosenki=new QLabel(ramka);
//    nazwapiosenki->setStyleSheet("QLabel{color:white}");
//    nazwapiosenki->setText(wybrany);
//    ramka->setStyleSheet("QFrame{background-color:black}");
//    odtworz=QPixmap(":/Tło/Tło/odtworz.jpg").scaled(70,70);
//    pauza=QPixmap(":/Tło/Tło/pauza.jpg").scaled(70,70);
//    klikodtworzpauza->setIcon(pauza);
//    klikodtworzpauza->setIconSize(pauza.rect().size());
//    zeropjedeno=0;
//  slider=new QSlider(Qt::Horizontal,ramka);
//  slider->setMinimumWidth(285);
//  slider->move(5,350);



//     connect(this->klikodtworzpauza,SIGNAL(clicked(bool)),this,SLOT(edytujramkes()));
//   ramka->show();




//}

//Oknoglowne::edytujramkes()
//{

//    if(zeropjedeno==0)
//    {
//        klikodtworzpauza->setIcon(odtworz);
//        zeropjedeno++;
//        klikodtworzpauza->show();
//        player->pause();




//    }
//    else if(zeropjedeno>0)
//    {
//        klikodtworzpauza->setIcon(pauza);
//        zeropjedeno--;
//         klikodtworzpauza->show();
//         player->play();

//    }


//}

//Oknoglowne::zmienionapozycjas(qint64 position)
//{
//slider->setValue(position);

//}

//Oknoglowne::zmienionyczass(qint64 position)
//{
//slider->setMaximum(position);

//}




