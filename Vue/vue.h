#ifndef VUE_H
#define VUE_H

#include <QObject>
#include <QWidget>
#include "choixchevalet.h"

class vue : public QWidget
{
    public:
        vue();
	/**
* \fn void setChevalet(choixChevalet * chevalet)
* \brief Définit le chevalet à chaque changement de joueur
* \param chevalet le nouveau chevalet
*/
        virtual void setChevalet(choixChevalet *) = 0;
	/**
* \fn void afficher()
* \brief Affiche le chevalet du joueur courant
*/
        virtual void afficher() = 0;
    protected:
        choixChevalet * chevalet_;
};

#endif // VUE_H
