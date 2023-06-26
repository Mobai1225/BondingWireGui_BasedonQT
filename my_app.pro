QT       += core gui
QT       += core gui network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += -I D:\anaconda\envs\open3d\include
LIBS += -LD:\anaconda\envs\open3d\libs

SOURCES += \
    about_us.cpp \
    detect_pcb.cpp \
    detect_single.cpp \
    main.cpp \
    mainwindow.cpp \
    tcp_client.cpp

HEADERS += \
    about_us.h \
    detect_pcb.h \
    detect_single.h \
    mainwindow.h \
    tcp_client.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
