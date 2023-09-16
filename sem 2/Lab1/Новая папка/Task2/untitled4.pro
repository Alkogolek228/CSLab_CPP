QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add_to_file.cpp \
    clear_file.cpp \
    main.cpp \
    mainwindow.cpp \
    search.cpp \
    task1.cpp \
    task2.cpp \
    task3.cpp \
    taskinfo.cpp

HEADERS += \
    add_to_file.h \
    clear_file.h \
    mainwindow.h \
    search.h \
    task1.h \
    task2.h \
    task3.h \
    taskinfo.h

FORMS += \
    add_to_file.ui \
    clear_file.ui \
    mainwindow.ui \
    search.ui \
    task1.ui \
    task2.ui \
    task3.ui \
    taskinfo.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    work.txt
