QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

HEADERS       += mainwindow.h \
    server.h \
    thread.h
SOURCES       += mainwindow.cpp \
                main.cpp \
                server.cpp \
                thread.cpp

FORMS += \
    mainwindow.ui


QMAKE_PROJECT_NAME = widgets_Grafica

# install
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



