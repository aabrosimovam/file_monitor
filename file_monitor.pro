TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    state_file.cpp \
    checkstatus.cpp

HEADERS += \
    state_file.h \
    checkstatus.h
