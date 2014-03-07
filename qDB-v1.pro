Qt+= widget
TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    dipendente.cpp \
    dipendenteore.cpp \
    dipendentemensilizzato.cpp \
    capoturno.cpp \
    smartpdip.cpp \
    impiegato.cpp \
    azienda.cpp

HEADERS += \
    containerTemplate.h \
    dipendente.h \
    dipendenteore.h \
    dipendentemensilizzato.h \
    capoturno.h \
    smartpdip.h \
    impiegato.h \
    azienda.h

