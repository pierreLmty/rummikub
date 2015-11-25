#ifndef CHEVALETJOUEURUN_H
#define CHEVALETJOUEURUN_H

#include <QObject>
#include <QWidget>
#include "choixchevalet.h"
#include <QtGui>
#include <QApplication>
#include "Vue/boutonslot.h"

class chevaletJoueurUn : public choixChevalet
{
    public:
        chevaletJoueurUn(joueur *, boutonSlot *);
        QLayout *utiliserChevalet();
    private:
        joueur * joueur_;
        boutonSlot * bu;
};

#endif // CHEVALETJOUEURUN_H
