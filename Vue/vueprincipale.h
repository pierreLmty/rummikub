#ifndef VUEPRINCIPALE_H
#define VUEPRINCIPALE_H

#include <QObject>
#include <QApplication>
#include <QWidget>
#include <QLayout>
#include <QPushButton>
#include <QIcon>
#include <QLabel>
#include "vue.h"
#include "choixchevalet.h"
#include "Modele/plateau.h"
#include "boutonslot.h"
#include "Modele/pioche.h"
#include "fenetre.h"
#include <vector>

class vuePrincipale : public vue
{
    Q_OBJECT
    public:
        vuePrincipale();
	/**
* \brief Construit la vue de la fenre de sélection des joueurs
* \param p le plateau
* \param laPioche le pioche du jeu
* \param b un bouton
* \param f la fenetre
* \param name le nom de la vue
*/
        vuePrincipale(plateau *, pioche *, boutonSlot *, QWidget *, QString);
	/**
* \fn void updateChevalet()
* \brief Met à jour le chevalet du joueur courant dans le cas d'une pioche ou d'une pose
*/
        void updateChevalet();
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
	/**
* \fn void utiliserPlateau()
* \brief Permet à l'utilisateur d'utiliser les tuiles qui sont sur le plateau pour former sa liste de tuile
*/
        void utiliserPlateau();
	/**
* \fn void updatePlateau()
* \brief Met à jour le plateau après une pose de tuile
*/
        void updatePlateau();
	/**
* \fn void setListeChevalet()
* \brief Définit la liste des chevalets
* \param l Un objet chevalet
*/
        void setListeChevalet(vector<choixChevalet *>);

    signals:
        void changeInterface(QString name);
    private:
        QVBoxLayout * layoutPrincipale_;
        QHBoxLayout * layoutDessous_;
        QGridLayout * layout_;
        QWidget * chevaletWidget_;
        QGridLayout * layoutChevalet_;
        QVBoxLayout * layoutInfo_;
        QPushButton * pioche_;
        QPushButton * verifier_;
        QPushButton * trier_;
        plateau * plateau_;
        pioche * pioch;
        boutonSlot * boutonSlot_;
        QLabel * hud;
        vector<choixChevalet *> listeChevalet_;

    public slots:
	    /**
* \fn void piocher()
* \brief Appelle la méthode piocher de la pioche et place la tuile piochée dans le chevalet du joueur courant
*/
        void piocher();
	* \fn void verifier()
* \brief Passe dans les différents états du pattern State et met à jour le plateau et le chevalet du joueur courant dans le cas d'une pioche ou d'une pose
*/
        void verifier();
	/**
* \fn void trier()
* \brief Appelle la fonction de triage du chevalet
*/
        void trier();
};

#endif // VUEPRINCIPALE_H
