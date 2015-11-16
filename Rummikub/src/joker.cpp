/**
* \file joker.cpp
* \author Lemétayer Pierre - Mael Quemard
* \version 1.0
* \date 16 Novembre 2015
* \brief Classe qui définit les objets de type joker héritant de la classe abstraite tuile.cpp
* \see tuile.cpp
*/

#include <string>
#include "joker.h"

using namespace std;

joker::joker(int id, int valeur, string couleur, int emplacement) : id_(id), valeur_(30), couleur_(couleur), emplacement_(emplacement) {}

/**
* \fn int getId()
* \brief Récupère l'id d'un objet joker
* \return l'id de l'objet
*/
int joker :: getId()
{
    return id_;
}

/**
* \fn int getValeur()
* \brief Récupère la valeur d'un objet joker
* \return la valeur de l'objet
*/
int joker :: getValeur()
{
    return valeur_;
}

/**
* \fn string getCouleur()
* \brief Récupère la couleur d'un objet joker
* \return la couleur de l'objet
*/
string joker :: getCouleur()
{
    return couleur_;
}

/**
* \fn void setValeur(int valeur)
* \brief Définit la nouvelle valeur de l'objet joker
* \param valeur la nouvelle valeur de l'objet
*/
void joker::setValeur(int valeur)
{
    valeur_ = valeur;
}

/**
* \fn int getEmplacement()
* \brief Récupère l'emplacement d'un objet joker
* \return l'emplacement de l'objet
*/
int joker :: getEmplacement()
{
    return emplacement_;
}

/**
* \fn void setEmplacement(int e)
* \brief Définit le nouvel emplacement d'un objet joker si celui-çi est utilisé par un joueur
* \param e le futur emplacement de l'objet joker (ne peut pas être égal à 0)
*/
void joker :: setEmplacement(int e)
{
    emplacement_ = e;
}

/**
* \fn string toString()
* \brief Affiche les caractéristiques de l'objet joker
*/
string joker::toString()
{
    cout << id_ << " " << valeur_ << " " << couleur_ << " " << emplacement_ << endl;
}
