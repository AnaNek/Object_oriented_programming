#-------------------------------------------------
#
# Project created by QtCreator 2019-06-05T19:44:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lab_04
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
        drawer/drawer.cpp \
        objects/edge.cpp \
        objects/model.cpp \
        objects/point3d.cpp \
        objects/point2d.cpp \
        objects/composite.cpp \
        objects/position.cpp \
        loadModel/modelBuilder.cpp \
        loadModel/fileLoader.cpp \
        managers/fasad.cpp \
        managers/drawManager.cpp \
        managers/fileManager.cpp \
        managers/transformManager.cpp \
        commands/command.cpp \
        transform/transform.cpp

HEADERS += \
        mainwindow.h \
        iterators/iterators.h \
        drawer/baseDrawer.h \
        drawer/drawer.h \
        objects/edge.h \
        objects/model.h \
        objects/point3d.h \
        objects/point2d.h \
        objects/object.h \
        objects/camera.h \
        objects/position.h \
        objects/composite.h \
        loadModel/modelBuilder.h \
        loadModel/fileLoader.h \
        loadModel/baseBuilder.h \
        loadModel/baseLoader.h \
        managers/baseManager.h \
        managers/cameraManager.h \
        managers/controller.h \
        managers/fasad.h \
        managers/drawManager.h \
        managers/fileManager.h \
        managers/transformManager.h \
        managers/scene.h \
        commands/command.h \
        transform/transform.h \
        exceptions/baseexception.h \
        exceptions/builderexception.h \
        exceptions/loadexception.h \
        exceptions/objectexception.h \
        exceptions/transformerexception.h \
        exceptions/drawexception.h


FORMS += \
        mainwindow.ui
