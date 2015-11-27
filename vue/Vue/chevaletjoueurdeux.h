#ifndef CHEVALETJOUEURDEUX_H
#define CHEVALETJOUEURDEUX_H

#include <QObject>
#include <QWidget>
#include "choixchevalet.h"
#include <QtGui>
#include <QApplication>
#include "Vue/boutonslot.h"

class chevaletJoueurDeux : public choixChevalet
{
    public:
        chevaletJoueurDeux(joueur *, boutonSlot *);
        QLayout *utiliserChevalet();
    private:
        joueur * joueur_;
        boutonSlot * bu;
};

#endif // CHEVALETJOUEURDEUX_H
