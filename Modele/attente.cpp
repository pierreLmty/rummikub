/**
* \file attente.cpp
* \author Lemétayer Pierre - Maël Quémard
* \version 1.0
* \date 16 Novembre 2015
* \brief Définit l'état d'attente du plateau
*/

#include "Modele/attente.h"
#include <iostream>
#include <vector>
#include "Modele/tuile.h"
#include "Modele/normal.h"
#include <string>

using namespace std;

attente::attente(plateau * p){
    plateau_ = p;
}

/**
* \fn void enAttente()
* \brief Le plateau attend que le joueur entre une série de tuile pour ensuite les faire vérifier. Si le joueur ne rentre rien, le plateau reste dans cet état d'attente
*/
void attente::enAttente(){
    if(!plateau_->emptyList())
    {
        cout << "pas empty";
        plateau_->setState(plateau_->getStateVerif());
        plateau_->afficher();
    }
    else{
        afficher();
    }
}

/**
* \fn void afficher()
* \brief Fonction à destination du joueur pour lui indiquer que le plateau est en attente d'une liste
*/
void attente::afficher(){
    cout << "en attente d'une liste" << endl;
}
