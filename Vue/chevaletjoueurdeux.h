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
	/**
* \fn QLayout utiliserChevalet()
* \brief Créer le layout du joueur 2
* \return Un layout qui contient un chevalet
*/
        QLayout *utiliserChevalet();
    private:
        joueur * joueur_;
        boutonSlot * bu;
};

#endif // CHEVALETJOUEURDEUX_H
