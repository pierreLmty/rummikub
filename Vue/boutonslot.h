#ifndef BOUTONSLOT_H
#define BOUTONSLOT_H

#include <QObject>
#include <QWidget>
#include "Modele/plateau.h"
#include "Modele/chevalet.h"

class boutonSlot : public QObject
{
    Q_OBJECT
    public:
        boutonSlot();
        boutonSlot(plateau *);
    public slots:
	    /**
* \fn void creerBoutonChevalet(QString buttonName)
* \brief Créer un bouton sur le chevalet du joueur courant
* \param buttonName Le nom du bouton
*/
        void creerBoutonChevalet(QString);
	/**
* \fn void creerBoutonPlateau(QString buttonName)
* \brief Créer un bouton sur le plateau de jeu
* \param buttonName Le nom du bouton
*/
        void creerBoutonPlateau(QString);
    private:
        plateau * plateau_;
};

#endif // BOUTONSLOT_H
