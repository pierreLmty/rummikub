/**
* \file boutonslot.cpp
* \author Lemétayer Pierre - Maël Quémard
* \version 1.0
* \date 27 Novembre 2015
* \brief gère les boutons du plateau de jeu
*/

#include "Vue/boutonslot.h"
#include <QPushButton>
#include <vector>
#include <iostream>
boutonSlot::boutonSlot(){}

boutonSlot::boutonSlot(plateau * p){
    plateau_ = p;
}

/**
* \fn void creerBoutonChevalet(QString buttonName)
* \brief Créer un bouton sur le chevalet du joueur courant
* \param buttonName Le nom du bouton
*/
void boutonSlot::creerBoutonChevalet(QString buttonName){
    QStringList tab = buttonName.split("_");
    QStringList c;
    QStringList val;
    for(int i = 0; i < tab.size(); i++){
        if(tab[i].contains(".")){
            c = tab[i].split(".");
        }
        if(tab[i].contains("/")){
            val = tab[i].split("/");
        }
    }
    tuile * t = plateau_->getJoueur()->getChevalet()->getTuile(val[1].toInt(), c[0].toStdString());
    plateau_->ajouterTuile(t);
}

/**
* \fn void creerBoutonPlateau(QString buttonName)
* \brief Créer un bouton sur le plateau de jeu
* \param buttonName Le nom du bouton
*/
void boutonSlot::creerBoutonPlateau(QString buttonName){
    QStringList tab = buttonName.split("_");
    QStringList c;
    QStringList val;
    for(int i = 0; i < tab.size(); i++){
        if(tab[i].contains(".")){
            c = tab[i].split(".");
        }
        if(tab[i].contains("/")){
            val = tab[i].split("/");
        }
    }
    tuile * t = plateau_->getTuile(val[1].toInt(), c[0].toStdString());
    plateau_->ajouterTuile(t);
}
