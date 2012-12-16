TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += ../test/SerialTest.cpp

INCLUDEPATH += ../include
LIBS+=-lbySerialPort -lrt -lPocoFoundation
OBJECTS_DIR += ./obj
linux-arm-g++ {
    message(g++ = linux-arm-g++ compile)
    LIBS += -L./lib/arm/
}

linux-g++ {
    message(g++ = linux-g++)
    LIBS += -L./lib/x86/
}
