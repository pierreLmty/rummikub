#ifndef CHEVALETJOUEURTROIS_H
#define CHEVALETJOUEURTROIS_H

#include <QObject>
#include <QWidget>
#include "choixchevalet.h"
#include <QtGui>
#include <QApplication>
#include "Vue/boutonslot.h"

class chevaletJoueurTrois : public choixChevalet
{
    public:
        chevaletJoueurTrois(joueur *, boutonSlot *);
        QLayout *utiliserChevalet();
    private:
        joueur * joueur_;
        boutonSlot * bu;
};

#endif // CHEVALETJOUEURTROIS_H
