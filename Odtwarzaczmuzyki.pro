#-------------------------------------------------
#
# Project created by QtCreator 2017-10-26T20:38:46
#
#-------------------------------------------------

QT       += core gui sql
QT   += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Odtwarzaczmuzyki
TEMPLATE = app


SOURCES += main.cpp \
    oknoglowne.cpp \
    oknododajp.cpp \
    bazapiosenek.cpp \
    grajpiosenke.cpp \
    playlisty.cpp \
    globalne.cpp \
    graj.cpp

HEADERS  += \
    oknoglowne.h \
    oknododajp.h \
    playlisty.h \
    globalne.h \
    graj.h

FORMS    += odtwarzacz.ui

RESOURCES += \
    potrzebneobrazki.qrc
