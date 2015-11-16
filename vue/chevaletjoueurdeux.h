#ifndef CHEVALETJOUEURDEUX_H
#define CHEVALETJOUEURDEUX_H

#include <QObject>
#include <QWidget>
#include "choixchevalet.h"

class chevaletJoueurDeux : public choixChevalet
{
    public:
        chevaletJoueurDeux();
        QLayout *utiliserChevalet();
};

#endif // CHEVALETJOUEURDEUX_H
