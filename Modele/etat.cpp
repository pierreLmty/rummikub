/**
* \file etat.cpp
* \author Lemétayer Pierre - Maël Quémard
* \version 1.0
* \date 16 Novembre 2015
* \brief Classe abstraite qui définit les différents états du plateau
*/

#include "Modele/etat.h"

using namespace std;

etat::etat(){}

/**
* \fn void enAttente()
* \brief Le plateau attend que le joueur entre une série de tuile pour ensuite les faire vérifier. Si le joueur ne rentre rien, le plateau reste dans cet état d'attente
*/
void etat::enAttente(){}

/**
* \fn void afficher()
* \brief Fonction à destination du joueur pour lui indiquer où en est le jeu
*/
void etat::afficher(){}

/**
* \fn void faireVerif()
* \brief Lance la série de vérifications à effectuer sur les listes envoyées par le joueur
*/
void etat::faireVerif(){}

/**
* \fn void valider(plateau * p)
* \brief Transfert les tuiles du chevalet du joueur et du plateau de jeu (pour les listes modifiées) vers le plateau de jeu pour former les nouvelles listes valides
*/
void etat::valider(){}
