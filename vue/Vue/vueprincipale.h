#ifndef VUEPRINCIPALE_H
#define VUEPRINCIPALE_H

#include <QObject>
#include <QApplication>
#include <QWidget>
#include <QLayout>
#include <QPushButton>
#include <QIcon>
#include "vue.h"
#include "choixchevalet.h"
#include "Modele/plateau.h"
#include "boutonslot.h"
#include "Modele/pioche.h"

class vuePrincipale : public vue
{
    Q_OBJECT
    public:
        vuePrincipale();
        vuePrincipale(choixChevalet *, plateau *, pioche *, boutonSlot *);
        void updateChevalet();
        void setChevalet(choixChevalet *);
        void afficher();
        void utiliserPlateau();
        void updatePlateau();
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
    public slots:
        void piocher();
        void verifier();
        void trier();
};

#endif // VUEPRINCIPALE_H
