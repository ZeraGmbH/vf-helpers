#-------------------------------------------------
#
# Project created by QtCreator 2015-05-04T11:23:24
#
#-------------------------------------------------

QT       -= gui

TARGET = vein-helpers
TEMPLATE = lib

DEFINES += VEINHELPERS_LIBRARY

HEADERS += veinhelpers_global.h \
    vh_handlemanager.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
