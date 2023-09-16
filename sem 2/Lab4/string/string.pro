QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-mystring-Desktop_Qt_5_15_12_MinGW_64_bit-Debug/release/ -lmystring
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-mystring-Desktop_Qt_5_15_12_MinGW_64_bit-Debug/debug/ -lmystring

INCLUDEPATH += $$PWD/../mystring
DEPENDPATH += $$PWD/../mystring
