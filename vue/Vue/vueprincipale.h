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
#include <vector>

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
        void setListeChevalet(vector<choixChevalet *>);

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
        plateau * plateau_;
        pioche * pioch;
        boutonSlot * boutonSlot_;
        QLabel * hud;
        vector<choixChevalet *> listeChevalet_;

    public slots:
        void piocher();
        void verifier();
        void trier();
};

#endif // VUEPRINCIPALE_H
