/**
* \file valide.cpp
* \author Lemétayer Pierre - Mael Quemard
* \version 1.0
* \date 16 Novembre 2015
* \brief Définit l'état valide du plateau, fait suite à l'état de vérification
*/

#include "valide.h"
#include <iostream>
#include "plateau.h"
#include <vector>

using namespace std;

/**
* \brief Constructeur de la classe valide.cpp
* \param p le nouvel objet à instancier
*/
valide::valide(plateau * p)
{
    plateau_ = p;
}

/**
* \fn void valider(plateau * p)
* \brief Transfert les tuiles du chevalet du joueur et du plateau de jeu (pour les listes modifiées) vers le plateau de jeu pour former les nouvelles listes valides
*/
void valide::valider(){
    vector<vector<tuile *> > tab = plateau_->getList();
    vector<vector<tuile *> > mat;
    for(unsigned int i = 0; i < tab.size(); ++i){
        for(unsigned int j =0; j<mat.size(); ++j){
            if(tab[i][j] != NULL){
                if(tab[i][j]->getEmplacement() == 1){
                    plateau_->getJoueur()->retirerTuile(tab[i][j]);
                }
                if(tab[i][j]->getEmplacement() == 2){
                    plateau_->retirerTuile(tab[i][j]);
                }
            }
        }
    }
    mat = plateau_->getPlateau();
    int k = 0;
    for(unsigned int i = 0; i<mat.size(); ++i){
        for(unsigned int j =0; j<mat.size(); ++j){
            if(tab[k][0] != NULL){
                if(mat[i][0] == 0){
                    plateau_->setPlateau(tab[k].front(), i, j);
                    tab[k].erase(tab[k].begin());
                    ++k;
                }
            }
        }
    }
    plateau_->setState(plateau_->getStateAttente());
    plateau_->afficher();
}

/**
* \fn void afficher()
* \brief Fonction à destination du joueur pour lui indiquer que la liste envoyée est valide
*/
void valide::afficher(){
    cout << "Valider";
}
