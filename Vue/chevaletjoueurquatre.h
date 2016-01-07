#ifndef CHEVALETJOUEURQUATRE_H
#define CHEVALETJOUEURQUATRE_H

#include <QObject>
#include <QWidget>
#include "choixchevalet.h"
#include <QtGui>
#include <QApplication>
#include "Vue/boutonslot.h"

class chevaletJoueurQuatre : public choixChevalet
{
    public:
        chevaletJoueurQuatre(joueur *, boutonSlot *);
	/**
* \fn QLayout utiliserChevalet()
* \brief Créer le layout du joueur 4
* \return Un layout qui contient un chevalet
*/
        QLayout *utiliserChevalet();
    private:
        joueur * joueur_;
        boutonSlot * bu;
};

#endif // CHEVALETJOUEURQUATRE_H
