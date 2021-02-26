#-------------------------------------------------
#
# Project created by QtCreator 2020-11-24T16:35:26
#
#-------------------------------------------------

CONFIG  +=  thread
INCLUDEPATH += kmGraph

INCLUDEPATH += /usr/include/libxml2
INCLUDEPATH += /usr/include/freetype2
INCLUDEPATH += /usr/include/qwt
INCLUDEPATH += /usr/include/
INCLUDEPATH += /usr/include/qt4/QtCore
INCLUDEPATH += recplay
INCLUDEPATH += rtracker
INCLUDEPATH += Tracking
INCLUDEPATH += rutil
INCLUDEPATH += guiRadar
INCLUDEPATH += kmGraph
INCLUDEPATH += tlv
INCLUDEPATH += simulate
INCLUDEPATH += data_distributor
INCLUDEPATH += kgc
INCLUDEPATH += mavlink
INCLUDEPATH += ais

#unix:LIBS =  -L/usr/local/lib -L/usr/X11/lib -lfreetype

QMAKE_RPATHDIR += kmGraph/libs
QMAKE_CC = gcc
QMAKE_CXX = g++

#QT += uitools
QT  += core gui
QT  += opengl core gui network sql
QT  += printsupport


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ARS-Testing
TEMPLATE = app

CONFIG += c++11


# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp\
        mainwindow.cpp \
    noteandsign.cpp \
    testelectriccable.cpp \
    testrfcable.cpp \
    testmodule.cpp \
    testmechanical.cpp \
    bussiness/bussinessmanager.cpp \
    tool/TableModel.cpp \
    utils/logutils.cpp \
    utils/srcReport.cpp
HEADERS += \
        mainwindow.h \
    noteandsign.h \
    testelectriccable.h \
    testrfcable.h \
    testmodule.h \
    testmechanical.h \
    tool/TableModel.h \
    tool/tools_export.h \
    userconfig.h \
    bussiness/bussinessmanager.h \
    utils/logutils.h \
    utils/srcReport.h
FORMS += \
        mainwindow.ui \
    noteandsign.ui \
    testelectriccable.ui \
    testrfcable.ui \
    testmodule.ui \
    testmechanical.ui

RESOURCES += \
    resources.qrc


QMAKE_LFLAGS = "-Wl,-rpath '-Wl,\$\$ORIGIN'"
QMAKE_LFLAGS += "-Wl,-rpath '-Wl,\$\$ORIGIN/guiRadar/libs'"
QMAKE_LFLAGS += "-Wl,-rpath '-Wl,\$\$ORIGIN/kmGraph/libs'"
QMAKE_LFLAGS += "-Wl,-rpath '-Wl,\$\$ORIGIN/libs'"

QMAKE_CFLAGS_DEBUG -=-O2
QMAKE_CFLAGS_RELEASE -=-O2
QMAKE_CXXFLAGS_DEBUG -=-O2
QMAKE_CXXFLAGS_RELEASE -=-O2

#LIBS    += -lstdc++ \
#                -lboost_thread \
#                -lboost_system \
#                -lboost_date_time \
#                #-lboost_program_options \
#                -lboost_filesystem \
#                #-lssh \
#                -L/usr/lib/i386-linux-gnu -lfreetype -lz \
#                #-lqwt \
#                -licuuc \
#                #-L. -lrxxlib \
#                -L/home/xlth/workspace/test/u111/kmGraph/libs -lkmGraph \
#                -lGLU -lGLEW -lglut -lGL \
#                #-lglut -lGL \
#                -lftgl \
#                -lglog \
#                #-L$$PWD/libs -ltlv \

SUBDIRS += recplay Tracking cmap data_distributor

OBJECTS_DIR = BUILD
MOC_DIR = MOC


DISTFILES +=

INCLUDEPATH += $$PWD/tool
DEPENDPATH += $$PWD/tool

unix:!macx: LIBS += -L$$PWD/qpdflib/ -lqpdf

INCLUDEPATH += $$PWD/qpdflib
DEPENDPATH += $$PWD/qpdflib

unix:!macx: LIBS += -L$$PWD/qtCsv/lib/ -lqtcsv

INCLUDEPATH += $$PWD/qtCsv/include
DEPENDPATH += $$PWD/qtCsv/include

unix:!macx: LIBS += -L$$PWD/libKdReport/lib/ -lkdreports

INCLUDEPATH += $$PWD/libKdReport/include
DEPENDPATH += $$PWD/libKdReport/include
