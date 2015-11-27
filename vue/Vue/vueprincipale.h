#ifndef VUEPRINCIPALE_H
#define VUEPRINCIPALE_H

#include <QObject>
#include <QApplication>
#include <QWidget>
#include <QLayout>
#include <QPushButton>
#include <QIcon>
#include <QLabel>
#include "vue.h"
#include "choixchevalet.h"
#include "Modele/plateau.h"
#include "boutonslot.h"
#include "Modele/pioche.h"
#include "fenetre.h"

class vuePrincipale : public vue
{
    Q_OBJECT
    public:
        vuePrincipale();
        vuePrincipale(plateau *, pioche *, boutonSlot *, QWidget *, QString);
        void updateChevalet();
        void setChevalet(choixChevalet *);
        void afficher();
        void utiliserPlateau();
        void updatePlateau();

    signals:
        void changeInterface(QString name);
    private:
        QVBoxLayout * layoutPrincipale_;
        QHBoxLayout * layoutDessous_;
        QGridLayout * layout_;
        QWidget * chevaletWidget_;
        QGridLayout * layoutChevalet_;
        QVBoxLayout * layoutInfo_;
        QPushButton * pioche_;
        QPushButton * verifier_;
        QPushButton * trier_;
        QPushButton * ajoutListe_;
        plateau * plateau_;
        pioche * pioch;
        boutonSlot * boutonSlot_;
        QLabel * hud;

    public slots:
        void piocher();
        void verifier();
        void trier();
        void nouvelleListe();
};

#endif // VUEPRINCIPALE_H
