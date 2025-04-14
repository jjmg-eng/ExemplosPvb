TEMPLATE = app
CONFIG  += warn_on release console
CONFIG  += qt
QT	+= sql

SOURCES += dataproc.cpp \
           qtdatabase.cpp

HEADERS += qtdatabase.h \
           shmemory.h

LIBS         += -lrllib
#LIBS         += /usr/lib/librllib.so

INCLUDEPATH  += /opt/pvb/pvserver \
                /opt/pvb/rllib/lib

DEFINES      += _MAIN_ _NOPVS_ 

TARGET = dataproc
