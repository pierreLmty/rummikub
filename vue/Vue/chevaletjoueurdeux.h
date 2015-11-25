#ifndef CHEVALETJOUEURDEUX_H
#define CHEVALETJOUEURDEUX_H

#include <QObject>
#include <QWidget>
#include "choixchevalet.h"

class chevaletJoueurDeux : public choixChevalet
{
    public:
        chevaletJoueurDeux(joueur *);
        QLayout *utiliserChevalet();
    private:
        joueur * joueur_;
};

#endif // CHEVALETJOUEURDEUX_H
