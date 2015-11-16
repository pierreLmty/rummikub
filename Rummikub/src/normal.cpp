/**
* \file normal.cpp
* \author Lemétayer Pierre - Mael Quemard
* \version 1.0
* \date 16 Novembre 2015
* \brief Classe qui définit les objets de type normal héritant de la classe abstraite tuile.cpp
* \see tuile.cpp
*/

#include <string>
#include "normal.h"

using namespace std;

normal::normal(int id, int valeur, string couleur, int emplacement) : id_(id), valeur_(valeur), couleur_(couleur), emplacement_(emplacement) {}

/**
* \fn int getId()
* \brief Récupère l'id d'un objet normal
* \return l'id de l'objet
*/
int normal :: getId()
{
    return id_;
}

/**
* \fn int getValeur()
* \brief Récupère la valeur d'un objet normal
* \return la valeur de l'objet
*/
int normal :: getValeur()
{
    return valeur_;
}

/**
* \fn string getCouleur()
* \brief Récupère la couleur d'un objet normal
* \return la couleur de l'objet
*/
string normal :: getCouleur()
{
    return couleur_;
}

/**
* \fn int getEmplacement()
* \brief Récupère l'emplacement d'un objet normal
* \return l'emplacement de l'objet
*/
int normal :: getEmplacement()
{
    return emplacement_;
}

/**
* \fn void setEmplacement(int e)
* \brief Définit le nouvel emplacement d'un objet normal si celui-çi est utilisé par un joueur
* \param e le futur emplacement de l'objet normal (ne peut pas être égal à 0)
*/
void normal :: setEmplacement(int e)
{
    emplacement_ = e;
}

/**
* \fn string toString()
* \brief Affiche les caractéristiques de l'objet normal
*/
string normal::toString()
{
    cout << id_ << " " << valeur_ << " " << couleur_ << " " << emplacement_ << endl;
}
