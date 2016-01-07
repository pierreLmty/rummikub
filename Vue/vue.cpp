/**
* \file vue.cpp
* \author Lemétayer Pierre - Maël Quémard
* \version 1.0
* \date 27 Novembre 2015
* \brief Classe abstraite qui s'occupe de la vue
*/

#include "Vue/vue.h"

using namespace std;

vue::vue(){}

/**
* \fn void setChevalet(choixChevalet * chevalet)
* \brief Définit le chevalet à chaque changement de joueur
* \param chevalet le nouveau chevalet
*/
void vue::setChevalet(choixChevalet * chevalet){}

/**
* \fn void afficher()
* \brief Affiche le chevalet du joueur courant
*/
void vue::afficher(){}
