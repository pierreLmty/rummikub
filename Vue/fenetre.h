#ifndef FENETRE_H
#define FENETRE_H

#include <QObject>
#include <QWidget>
#include <QStackedWidget>
#include "vue.h"
#include "vueprincipale.h"
#include "vuechoixjoueur.h"
#include "Modele/plateau.h"
#include "boutonslot.h"
#include "Modele/pioche.h"
#include "choixchevalet.h"
#include "chevaletjoueurun.h"
#include "chevaletjoueurdeux.h"
#include "chevaletjoueurtrois.h"
#include "chevaletjoueurquatre.h"
#include <vector>

class fenetre : public QStackedWidget
{
    Q_OBJECT
    public:
        fenetre();
	/**
* \fn void nbJoueur2()
* \brief Intervient dans le cas où le nombre de joueur est 2. Réalise toutes les initialisations
*/
        void nbJoueur2();
	/**
* \fn void nbJoueur3()
* \brief Intervient dans le cas où le nombre de joueur est 3. Réalise toutes les initialisations
*/
        void nbJoueur3();
	/**
* \fn void nbJoueur4()
* \brief Intervient dans le cas où le nombre de joueur est 4. Réalise toutes les initialisations
*/
        void nbJoueur4();
	/**
* \fn void main()
* \brief Programme principal qui lance le jeu et gère les conditions de fin
*/
        void main();
    public slots:
	    /**
* \fn void changerFenetre()
* \brief Intervient en début de programme, change de la fenêtre de selction des joueurs au plateau de jeu
* \param name le nom du layout
*/
        void changerFenetre(QString name);

    private:
        vue * vuePrincipale_;
        vue * vueChoixJoueur_;
        plateau * plateau_;
        boutonSlot * boutonSlot_;
        pioche * pioche_;
        choixChevalet * choixChevaletJoueurUn_;
        choixChevalet * choixChevaletJoueurDeux_;
        choixChevalet * choixChevaletJoueurTrois_;
        choixChevalet * choixChevaletJoueurQuatre_;
        joueur * joueurUn_;
        joueur * joueurDeux_;
        joueur * joueurTrois_;
        joueur * joueurQuatre_;
        vector<joueur *> listeJoueur_;
        vector<choixChevalet *> listeChevalet_;
};

#endif // FENETRE_H
