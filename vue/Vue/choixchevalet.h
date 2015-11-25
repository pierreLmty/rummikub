#ifndef CHOIXCHEVALET_H
#define CHOIXCHEVALET_H

#include <QObject>
#include <QWidget>
#include <QLayout>
#include "Modele/joueur.h"

class choixChevalet : public QGridLayout
{
public:
    choixChevalet();
    virtual QLayout *utiliserChevalet() = 0;

};

#endif // CHOIXCHEVALET_H
