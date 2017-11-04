#ifndef ODTWARZACZ_H
#define ODTWARZACZ_H

#include <QMainWindow>

namespace Ui {
class Odtwarzacz;
}

class Odtwarzacz : public QMainWindow
{
    Q_OBJECT

public:
    explicit Odtwarzacz(QWidget *parent = 0);
    ~Odtwarzacz();

private:
    Ui::Odtwarzacz *ui;
};

#endif // ODTWARZACZ_H
