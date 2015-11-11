#include "chevalet.h"
#include "tuile.h"
#include <algorithm>
#include <iostream>
#include "normal.h"
#include <string>

using namespace std;

chevalet::chevalet(){}

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

tuile *chevalet::getTuile(int val, string couleur){
    tuile* t;
    for(unsigned int i = 0; i < chevalet_.size(); ++i){
        if(chevalet_[i]->getCouleur() == couleur && chevalet_[i]->getValeur() == val){
            t = chevalet_[i];
        }
    }
    return t;
}

void chevalet::addTuile(tuile * t){
    chevalet_.push_back(t);
}

void chevalet::deleteTuile(tuile * t){
    for(unsigned int i = 0; i < chevalet_.size(); ++i){
        if(chevalet_[i] == t){
            chevalet_.erase(chevalet_.begin()+i);
        }
    }
}

void chevalet::afficher(){
    for(unsigned int i = 0; i < chevalet_.size(); ++i){
        cout << chevalet_[i]->getValeur() << endl;
    }
}
