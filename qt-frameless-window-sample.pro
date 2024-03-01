QT       += core gui widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(submodules/qt-frameless-window/qt-frameless-window.pri)
include(submodules/qt-easy-logger/qt-easy-logger.pri)

SOURCES += \
    main.cpp \
    samplewindow.cpp \
    samplewindow2.cpp

HEADERS += \
    samplewindow.h \
    samplewindow2.h

RESOURCES += \
    qt-frameless-window-sample.qrc
