#ifndef CHEVALETJOUEURUN_H
#define CHEVALETJOUEURUN_H

#include <QObject>
#include <QWidget>
#include "choixchevalet.h"

class chevaletJoueurUn : public choixChevalet
{
    public:
        chevaletJoueurUn();
        QLayout *utiliserChevalet();
};

#endif // CHEVALETJOUEURUN_H
