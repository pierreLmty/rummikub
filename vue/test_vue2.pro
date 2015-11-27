QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test_vue2

HEADERS += \
    Modele/attente.h \
    Modele/verification.h \
    Modele/valide.h \
    Modele/tuileFactory.h \
    Modele/tuile.h \
    Modele/plateau.h \
    Modele/pioche.h \
    Modele/normal.h \
    Modele/joueur.h \
    Modele/joker.h \
    Modele/factory.h \
    Modele/etat.h \
    Modele/chevalet.h \
    Vue/vueprincipale.h \
    Vue/vue.h \
    Vue/choixchevalet.h \
    Vue/chevaletjoueurun.h \
    Vue/chevaletjoueurdeux.h \
    Vue/boutonslot.h \
    Vue/vuechoixjoueur.h \
    Vue/fenetre.h \
    Vue/chevaletjoueurtrois.h \
    Vue/chevaletjoueurquatre.h

SOURCES += \
    Modele/attente.cpp \
    Modele/verification.cpp \
    Modele/valide.cpp \
    Modele/tuileFactory.cpp \
    Modele/tuile.cpp \
    Modele/plateau.cpp \
    Modele/pioche.cpp \
    Modele/normal.cpp \
    Modele/joueur.cpp \
    Modele/joker.cpp \
    Modele/factory.cpp \
    Modele/etat.cpp \
    Modele/chevalet.cpp \
    Vue/vueprincipale.cpp \
    Vue/vue.cpp \
    Vue/choixchevalet.cpp \
    Vue/chevaletjoueurun.cpp \
    Vue/chevaletjoueurdeux.cpp \
    Vue/boutonslot.cpp \
    main.cpp \
    Vue/vuechoixjoueur.cpp \
    Vue/fenetre.cpp \
    Vue/chevaletjoueurtrois.cpp \
    Vue/chevaletjoueurquatre.cpp

DISTFILES += \
    Modele/attente.o \
    Modele/verification.o \
    Modele/valide.o \
    Modele/tuileFactory.o \
    Modele/tuile.o \
    Modele/plateau.o \
    Modele/pioche.o \
    Modele/normal.o \
    Modele/joueur.o \
    Modele/joker.o \
    Modele/factory.o \
    Modele/etat.o \
    Modele/chevalet.o \
    Vue/vueprincipale.o \
    Vue/vue.o \
    Vue/choixchevalet.o \
    Vue/chevaletjoueurun.o \
    Vue/chevaletjoueurdeux.o \
    Vue/boutonslot.o
