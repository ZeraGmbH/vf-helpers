#-------------------------------------------------
#
# Project created by QtCreator 2015-05-04T11:23:24
#
#-------------------------------------------------

QT       -= gui

TARGET = vein-helpers
TEMPLATE = lib

DEFINES += VEINHELPERS_LIBRARY

HEADERS += vh_handlemanager.h \
  vh_logging.h \
  veinhelpers_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

public_headers.files = $$HEADERS

exists( ../../vein-framework.pri ) {
  include(../../vein-framework.pri)
}

SOURCES += \
    vh_handlemanager.cpp
