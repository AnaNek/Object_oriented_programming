#-------------------------------------------------
#
# Project created by QtCreator 2019-03-24T17:44:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lab_01
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
        drawwidget.cpp \
        repository.cpp \
        mathlib.cpp \
        model.cpp \
        processaction.cpp \
        processerrors.cpp \
        file.cpp \
        open_model.cpp \
        save_model.cpp \
        operations_model.cpp \
        transform_points.cpp

HEADERS += \
        mainwindow.h \
        drawwidget.h \
        repository.h \
        mathlib.h \
        model.h \
        processaction.h \
        errors.h \
        processerrors.h \
        file.h \
        open_model.h \
        save_model.h \
        operations_model.h \
        transform_points.h

FORMS += \
        mainwindow.ui
