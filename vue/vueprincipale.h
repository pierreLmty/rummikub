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

class vuePrincipale : public vue
{
    public:
        vuePrincipale(choixChevalet *);
        void setChevalet(choixChevalet *);
        void afficher();
    private:
        QVBoxLayout * layoutPrincipale_;
        QHBoxLayout * layoutDessous_;
        QGridLayout * layout_;
        QWidget * chevaletWidget_;
        QGridLayout * layoutChevalet_;
        QVBoxLayout * layoutInfo_;
        QPushButton * pioche_;
        QPushButton * verifier_;
};

#endif // VUEPRINCIPALE_H
