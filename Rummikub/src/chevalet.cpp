/**
* \file chevalet.cpp
* \author Lemétayer Pierre - Mael Quemard
* \version 1.0
* \date 16 Novembre 2015
* \brief Classe qui définit les objets de type chevalet
*/

#include "chevalet.h"
#include "tuile.h"
#include <algorithm>
#include <iostream>
#include "normal.h"
#include <string>

using namespace std;

chevalet::chevalet(){}

/**
* \fn void trierChevalet()
* \brief Trie le chevalet du joueur en fonction de la valeur des tuiles
*/
void chevalet::trierChevalet(){
    for(unsigned int i = 0; i < chevalet_.size(); ++i){
        cout << " | " << chevalet_.at(i)->getValeur() << chevalet_.at(i)->getCouleur();
    }
    int i;
    bool perm;
    int longueur = chevalet_.size();
    do{
        perm = false;
        for(i=0; i < longueur-1; ++i){
            if(chevalet_.at(i)->getCouleur() > chevalet_.at(i+1)->getCouleur()){
                tuile * tmp = chevalet_.at(i);
                chevalet_[i] = chevalet_[i+1];
                chevalet_[i+1] = tmp;
                perm = true;
            }
        }
        longueur--;
    }while(perm);
    cout << endl;
    for(unsigned int i = 0; i < chevalet_.size(); ++i){
        cout << " | " << chevalet_.at(i)->getValeur() << chevalet_.at(i)->getCouleur();
    }
}

/**
* \fn tuile * getTuile(int val, string couleur)
* \brief Récupère un objet de type tuile du chevalet du joueur selon sa valeur et sa couleur
* \param val la valeur de la tuile à récupérer
* \param couleur la couleur de la tuile à récupérer
* \return Retourne un objet tuile du chevalet
*/
tuile *chevalet::getTuile(int val, string couleur){
    tuile* t;
    for(unsigned int i = 0; i < chevalet_.size(); ++i){
        if(chevalet_[i]->getCouleur() == couleur && chevalet_[i]->getValeur() == val){
            t = chevalet_[i];
        }
    }
    return t;
}

/**
* \fn void addTuile(tuile * t)
* \brief Ajoute un objet de type tuile dans le chevalet
* \param t un objet de type tuile
*/
void chevalet::addTuile(tuile * t){
    chevalet_.push_back(t);
}

/**
* \fn void deleteTuile(tuile * t)
* \brief Retire un objet de type tuile du chevalet
* \param t un objet de type tuile
*/
void chevalet::deleteTuile(tuile * t){
    for(unsigned int i = 0; i < chevalet_.size(); ++i){
        if(chevalet_[i] == t){
            chevalet_.erase(chevalet_.begin()+i);
        }
    }
}

/**
* \fn void afficher()
* \brief Affiche l'ensemble des tuiles du chevalet
*/
void chevalet::afficher(){
    for(unsigned int i = 0; i < chevalet_.size(); ++i){
        cout << chevalet_[i]->getValeur() << endl;
    }
}
