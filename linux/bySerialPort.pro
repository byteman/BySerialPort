#-------------------------------------------------
#
# Project created by QtCreator 2012-12-16T15:39:07
#
#-------------------------------------------------

QT       -= core gui

TARGET = bySerialPort
TEMPLATE = lib

DEFINES += BYSERIALPORT_LIBRARY

SOURCES += \
    ../src/serial.cpp \
    ../src/impl/unix.cpp

HEADERS +=
INCLUDEPATH += ../include
OBJECTS_DIR += ./obj
linux-arm-g++ {
    message(g++ = linux-arm-g++ compile)
    DESTDIR += ./lib/arm

}

linux-g++ {
    message(g++ = linux-g++ compile)
    DESTDIR += ./lib/x86
}
