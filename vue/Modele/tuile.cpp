/**
* \file tuile.cpp
* \author Lemétayer Pierre - Mael Quemard
* \version 1.0
* \date 16 Novembre 2015
* \brief Classe abstraite qui définit les différents types de tuiles
*/

#include <string>
#include "Modele/tuile.h"

using namespace std;

tuile::tuile(){}

/**
* \fn string getCouleur()
* \brief Récupère la couleur d'un objet tuile
*/
string tuile::getCouleur(){}

/**
* \fn int getValeur(plateau * p)
* \brief Récupère la valeur d'un objet tuile
*/
int tuile::getValeur(){}

/**
* \fn int getId()
* \brief Récupère l'id d'un objet tuile
*/
int tuile::getId(){}

/**
* \fn int getEmplacement()
* \brief Récupère l'emplacement courant où se trouve l'objet tuile (dans la pioche, dans un chevalet ou sur le plateau)
*/
int tuile::getEmplacement(){}

/**
* \fn void setEmplacement(int)
* \brief Définit le nouvel emplacement d'un objet tuile si celui-çi est utilisé par un joueur
* \param int le futur emplacement de l'objet tuile (ne peut pas être égal à 0)
*/
void tuile::setEmplacement(int){}

/**
* \fn string toString()
* \brief Affiche les caractéristiques de l'objet tuile
*/
string tuile::toString(){}
