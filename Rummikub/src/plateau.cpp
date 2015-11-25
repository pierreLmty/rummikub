/**
* \file plateau.cpp
* \author Lemétayer Pierre - Mael Quemard
* \version 1.0
* \date 16 Novembre 2015
* \brief Classe qui définit le plateau de jeu
*/

#include "plateau.h"
#include "attente.h"
#include "verification.h"
#include "valide.h"
#include <iostream>

using namespace std;

/**
* \brief Constructeur de la classe plateau.cpp
*/
plateau::plateau(){
    etatCourant_ = new attente(this);
    etatAttente_ = new attente(this);
    etatVerification_ = new verification(this);
    etatValide_ = new valide(this);
    mat_.resize(13, std::vector<tuile *>(13, NULL));
    tab_.resize(13, std::vector<tuile *>(13, NULL));
}

/**
* \fn etat * getState()
* \brief Retourne l'état dans lequel se trouve le plateau
* \return Un état du plateau
*/
etat *plateau::getState(){
    return etatCourant_;
}

/**
* \fn etat * getStateVerif()
* \brief Retourne l'état de vérification
* \return L'état de vérification
*/
etat *plateau::getStateVerif(){
    return etatVerification_;
}

/**
* \fn etat * getStateValide()
* \brief Retourne l'état valide
* \return L'état valide
*/
etat *plateau::getStateValide(){
    return etatValide_;
}

/**
* \fn etat * getStateAttente()
* \brief Retourne l'état d'attente
* \return L'état d'attente
*/
etat *plateau::getStateAttente(){
    return etatAttente_;
}

/**
* \fn void setState(etat * etat)
* \brief Définit le nouvel du plateau dans lequel il vient d'arriver
* \param etat Le nouvel état du plateau
*/
void plateau::setState(etat * etat){
    etatCourant_ = etat;
}

/**
* \fn void faireVerif()
* \brief Lance la série de vérification sur les listes envoyées par le joueur
*/
void plateau::faireVerif(){
    etatCourant_->faireVerif();
}

/**
* \fn void valider()
* \brief Transfert les tuiles du chevalet du joueur et du plateau de jeu (pour les listes modifiées) vers le plateau de jeu pour former les nouvelles listes valides
*/
void plateau::valider(){
    etatCourant_->valider();
}

/**
* \fn void enAttente()
* \brief Le plateau attend que le joueur entre une série de tuile pour ensuite les faire vérifier. Si le joueur ne rentre rien, le plateau reste dans cet état d'attente
*/
void plateau::enAttente(){
    etatCourant_->enAttente();
}

/**
* \fn void afficher()
* \brief Affiche le plateau de jeu (mode console uniquement)
*/
void plateau::afficher(){
    cout << endl;
    for(unsigned int i=0; i < mat_.size(); ++i){
        for(unsigned int j=0; j < mat_.size(); ++j){
            cout << "|";
            if(mat_[i][j] != NULL){
                cout << mat_[i][j]->getValeur() << " ";
                cout << mat_[i][j]->getCouleur();
            }
            else{
                cout << 0;
            }
//            cout << "|";
        }
        cout << "|" << endl;
    }
    etatCourant_->afficher();
}

/**
* \fn vector<tuile *> getList()
* \brief Récupère la liste de tuiles temporaires faite par le joueur
* \return tab_ La liste de tuile temporaire
*/
vector<vector<tuile *> > plateau::getList(){
    return tab_;
}

/**
* \fn void setList(tuile * a)
* \brief Ajoute une tuile à la liste temporaire qui sera vérifiée par la fonction de vérification
* \param a Une tuile à ajouter à la liste temporaire
*/
void plateau::setList(tuile * a, int indice){
    tab_[indice].push_back(a);
}

/**
* \fn bool emptyList()
* \brief Vérifie si la liste temporaire est vide ou non
* \return Retourne Vrai si la liste est vide sinon Faux
*/
bool plateau::emptyList(){
    for(unsigned int i = 0; i < tab_.size(); ++i){
        if(!tab_[i].empty()){
            return false;
        }
    }
    return true;
}

/**
* \fn void clearTab()
* \brief Supprime tous les éléments de la liste temporaire
*/
void plateau::clearTab(){
    for(unsigned int i = 0; i < tab_.size(); ++i){
        tab_[i].clear();
    }
}

/**
* \fn vector<vector<tuile *> > getPlateau()
* \brief Retourne le plateau de jeu
* \return La matrice qui sert de plateau de jeu
*/
vector<vector<tuile *> > plateau::getPlateau(){
    return mat_;
}


/**
* \fn void setPlateau(tuile * a, int i, int j)
* \brief
* \param a
* \param i
* \param j
*/
void plateau::setPlateau(tuile * a, int i, int j){
    mat_[i][j] = a;
}

/**
* \fn tuile * getTuile(int val, string couleur)
* \brief Récupère une tuile du plateau de jeu en fonction de la valeur et de la couleur passées en paramètre
* \param val la valeur de la tuile recherchée
* \param couleur La couleur de la tuile recherchée
* \return Un objet de type tuile
*/
tuile *plateau::getTuile(int val, string couleur){
    for(unsigned int i = 0; i < mat_.size(); ++i){
        for(unsigned int j = 0; j < mat_.size(); ++j){
            if(mat_[i][j] != NULL){
                if(mat_[i][j]->getValeur() == val && mat_[i][j]->getCouleur() == couleur){
                    return mat_[i][j];
                }
            }
        }
    }
}

/**
* \fn void retirerTuile(tuile * t)
* \brief Supprime une tuile passée en paramètre
* \param t La tuile à supprimer
*/
void plateau::retirerTuile(tuile * t){
    /*for(vector<vector<tuile *> >::iterator i = mat_->begin(); i != mat_->end(); ++i){
        if(i->pointer == t){
            mat_->erase(i);
        }
    }*/
    for(unsigned int i = 0; i < mat_.size(); ++i){
        for(unsigned int j = 0; j < mat_.size(); ++j){
            if(mat_[i][j] != NULL){
                if(mat_[i][j] == t){
                    mat_[i].erase(mat_[i].begin()+j);
                }
            }
        }
    }
}

/**
* \fn void setJoueur()
* \brief Définit un nouveau joueur pour le jeu
* \param j Un objet de type joueur
*/
void plateau::setJoueur(joueur * j){
    joueur_ = j;
}

/**
* \fn joueur * getJoueur()
* \brief Retourne un joueur du jeu
* \return Un objet de type joueur
*/
joueur *plateau::getJoueur(){
    return joueur_;
}

void plateau::afficherMatTmp(){
    for(int i = 0; i <tab_.size(); ++i){
        for(int j = 0; j<tab_.size(); ++j){
            cout << tab_[i][j];
        }
        cout << endl;
    }
}
