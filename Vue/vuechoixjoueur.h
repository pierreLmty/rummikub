#ifndef VUECHOIXJOUEUR_H
#define VUECHOIXJOUEUR_H

#include <QObject>
#include <QApplication>
#include <QWidget>
#include <QLayout>
#include <QPushButton>
#include <QIcon>
#include "vue.h"
#include "choixchevalet.h"
#include "chevaletjoueurun.h"
#include "chevaletjoueurdeux.h"
#include "Modele/plateau.h"
#include "boutonslot.h"
#include "Modele/pioche.h"
#include "Vue/fenetre.h"

class vueChoixJoueur : public vue
{
    Q_OBJECT
    public:
	    /**
* \brief Construit la vue de la fenêtre de sélection des joueurs
* \param p le plateau
* \param f la fenetre
* \param name le nom de la vue
*/
        vueChoixJoueur(plateau *, QWidget *, QString);
	/**
* \fn void setChevalet(choixChevalet * chevalet)
* \brief Définit le chevalet à chaque changement de joueur
* \param chevalet le nouveau chevalet
*/
        void setChevalet(choixChevalet *);
	/**
* \fn void afficher()
* \brief Affiche le chevalet du joueur courant
*/
        void afficher();

    signals:
        void changeInterface(QString name);

    public slots:
	    /**
* \fn void nbJoueur2()
* \brief Lance le programme avec 2 joueurs
*/
        void nbJoueur2();
	/**
* \fn void nbJoueur3()
* \brief Lance le programme avec 3 joueurs
*/
        void nbJoueur3();
	/**
* \fn void nbJoueur3()
* \brief Lance le programme avec 4 joueurs
*/
        void nbJoueur4();
    private:
        QWidget * fenetre_;
        plateau * plateau_;
        QVBoxLayout * layout_;
        QPushButton * nbJoueurDeux_;
        QPushButton * nbJoueurTrois_;
        QPushButton * nbJoueurQuatre_;
};

#endif // VUECHOIXJOUEUR_H
