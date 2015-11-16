QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test_vue2

HEADERS += \
    myframe.h \
    vue.h \
    choixchevalet.h \
    vueprincipale.h \
    chevaletjoueurun.h \
    chevaletjoueurdeux.h \
    boutonslot.h

SOURCES += \
    myframe.cpp \
    main.cpp \
    vue.cpp \
    choixchevalet.cpp \
    vueprincipale.cpp \
    chevaletjoueurun.cpp \
    chevaletjoueurdeux.cpp \
    boutonslot.cpp

DISTFILES +=
