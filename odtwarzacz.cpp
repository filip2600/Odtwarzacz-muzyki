#include "odtwarzacz.h"
#include "ui_odtwarzacz.h"

Odtwarzacz::Odtwarzacz(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Odtwarzacz)
{
    ui->setupUi(this);
}

Odtwarzacz::~Odtwarzacz()
{
    delete ui;
}
