#include "oknoglowne.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   Oknoglowne*o=new Oknoglowne;
   o->show();




    return a.exec();
}
