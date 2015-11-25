/**
* \file attente.cpp
* \author Lemétayer Pierre - Mael Quemard
* \version 1.0
* \date 16 Novembre 2015
* \brief Définit l'état d'attente du plateau
*/

#include "attente.h"
#include <iostream>
#include <vector>
#include "tuile.h"
#include "normal.h"
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
    vector<vector<tuile *> > tab = plateau_->getList();
    vector<vector<tuile *> > mat;
    tuile * t;
    int val;
    int indiceMatTemp = 0;
    string couleur;
    int empl;
    plateau_->clearTab();
    while(val != -1){
        cout << "Valeur : ";
        cin >> val;
        if(val != -1){
            cout << "Couleur : ";
            cin >> couleur;
            cout << "Emplacement : ";
            cin >> empl;
            if(empl == 1){
                t = plateau_->getJoueur()->getTuile(val, couleur);
            }else{
                t = plateau_->getTuile(val, couleur);

                //Ajout de la liste du plateau que le joueur vient de changer
                /**TODO
                * Récupérer où se trouve l'indice de la liste modifiée et là placer dans la matrice
                */
            }
            if(t != NULL){
                cout << t->getValeur() << endl;
                plateau_->setList(t, indiceMatTemp);
            }
        }
        if(val == -2){//On ajoute une nouvelle liste dans la matrice temporaire
            for(unsigned int i = 0; i<mat.size(); ++i){
                if(tab[i][0] != NULL){
                    indiceMatTemp = 1; //On récupère la prmière ligne disponible pour prendre une nouvelle liste
                }
            }
        }
    }
    if(!plateau_->emptyList())
    {
        plateau_->setState(plateau_->getStateVerif());
        plateau_->afficher();
    }
    else{
        afficher();
        enAttente();
    }
}

/**
* \fn void afficher()
* \brief Fonction à destination du joueur pour lui indiquer que le plateau est en attente d'une liste
*/
void attente::afficher(){
    cout << "en attente d'une liste" << endl;
}
