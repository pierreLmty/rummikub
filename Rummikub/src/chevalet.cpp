#include "chevalet.h"
#include "tuile.h"
#include <algorithm>
#include <iostream>
#include "normal.h"
#include <string>

using namespace std;

chevalet::chevalet(){
    chevalet_.push_back(new normal(1, 8, "jaune"));
    chevalet_.push_back(new normal(2, 7, "rouge"));
    chevalet_.push_back(new normal(3, 6, "noir"));
    chevalet_.push_back(new normal(4, 5, "jaune"));
    chevalet_.push_back(new normal(5, 4, "bleu"));
    chevalet_.push_back(new normal(6, 3, "rouge"));
    chevalet_.push_back(new normal(7, 2, "noir"));
    chevalet_.push_back(new normal(8, 1, "bleu"));
}

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

    /*
    for(unsigned int i = 0; i < chevalet_.size()-1; ++i){
        if(chevalet_.at(i)->getCouleur() < chevalet_.at(i+1)->getCouleur()){
            tuile * tmp = chevalet_.at(i);
            chevalet_[i] = chevalet_[i+1];
            chevalet_[i+1] = tmp;
        }
    }
    cout << endl;
    for(unsigned int i = 0; i < chevalet_.size(); ++i){
        cout << " | " << chevalet_.at(i)->getValeur() << chevalet_.at(i)->getCouleur();
    }*/
}

bool chevalet::getTuile(tuile * t){
    bool tuileIn = false;
    for(unsigned int i = 0; i < chevalet_.size(); ++i){
        if(chevalet_[i] == t){
            chevalet_.erase(chevalet_.begin()+i);
            tuileIn = true;
        }
    }
    return tuileIn;
}
