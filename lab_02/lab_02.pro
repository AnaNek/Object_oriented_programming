TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp
HEADERS += list.h \
           node.h \
           iterator.h \
           errors.h \
           base_container.h \
           _list.hpp \
           _node.hpp \
           _iterator.hpp
