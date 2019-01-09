#-------------------------------------------------
#
# Project created by QtCreator 2019-01-09T22:18:46
#
#-------------------------------------------------

QT       -= core gui

TARGET = my-libs
TEMPLATE = lib
CONFIG += staticlib

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


INCLUDEPATH += /usr/local/include/opencv4
LIBS += -L/usr/local/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lopencv_imgproc

SOURCES += \
        src/leastsquares.cpp \
    src/matrix_operations.cpp

HEADERS += \
        include/leastsquares.h \
        include/matrix_operations.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
