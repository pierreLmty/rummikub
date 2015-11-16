/**
* \file joueur.cpp
* \author Lemétayer Pierre - Mael Quemard
* \version 1.0
* \date 16 Novembre 2015
* \brief Classe qui définit les objets de type joueur
*/

#include "joueur.h"

using namespace std;

joueur::joueur(){
    firstMain_ = true;
    chevalet_ = new chevalet;
}

/**
* \fn bool getFirstMain()
* \brief Récupère l'état de l'attribut firstMain_ d'un objet joueur
* \return la valeur du booléen
*/
bool joueur::getFirstMain(){
    return firstMain_;
}

/**
* \fn void setFirstMain(bool firstMain)
* \brief Définit la nouvelle valeur booléenne de l'attribut firstMain_ de l'objet joueur
* \param valeur la nouvelle valeur booléenne de firstMain_
*/
void joueur::setFirstMain(bool firstMain){
    firstMain_ = firstMain;
}

/**
* \fn int getId()
* \brief Récupère l'id d'un objet joueur
* \return l'id de l'objet
*/
int joueur::getId(){
    return id_;
}

/**
* \fn int getScore()
* \brief Récupère le score d'un objet joueur
* \return le score de l'objet
*/
int joueur::getScore(){
    return score_;
}

/**
* \fn void setScore(int score)
* \brief Modifie le score du joueur
* \param score Le score du joueur
*/
void joueur::setScore(int score){
    score_ = score
}

/**
* \fn chevalet * getChevalet()
* \brief Récupère le chevalet d'un objet joueur
* \see chevalet.cpp
* \return le chevalet de l'objet
*/
chevalet * joueur::getChevalet(){
    return chevalet_;
}

/**
* \fn void setChevalet(tuile * t)
* \brief Ajoute un objet de type tuile au chevalet du joueur
* \see chevalet.cpp
* \param t la tuile à ajouter au chevalet
*/
void joueur::setChevalet(tuile * t){
    chevalet_->addTuile(t);
}

/**
* \fn void retirerTuile(tuile * tuile)
* \brief Retire un objet de type tuile du chevalet du joueur et change l'emplacement de cet objet
* \see chevalet.cpp
* \param tuile la tuile à retirer du chevalet
*/
void joueur::retirerTuile(tuile * tuile){
    tuile->setEmplacement(2);
    chevalet_->deleteTuile(tuile);
}

/**
* \fn tuile * getTuile(int val, string couleur)
* \brief Récupère un objet de type tuile du chevalet du joueur selon sa valeur et sa couleur
* \see chevalet.cpp
* \param val la valeur de la tuile à récupérer
* \param couleur la couleur de la tuile à récupérer
*/
tuile *joueur::getTuile(int val, string couleur){
    return chevalet_->getTuile(val, couleur);
}
