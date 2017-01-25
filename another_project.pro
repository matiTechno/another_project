TEMPLATE = app
CONFIG += c++14 strict_c++
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -pedantic

LIBS += -lglfw -lGL -ldl

SOURCES += main.cpp \
    glad.c \
    app.cpp

HEADERS += \
    glad.h \
    app.hpp
