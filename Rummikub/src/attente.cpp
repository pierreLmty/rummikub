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

void attente::enAttente(){
    tuile * t;
    int val;
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
            }
            if(t != NULL){
                cout << t->getValeur() << endl;
                plateau_->setList(t);
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

void attente::afficher(){
    cout << "en attente d'une liste" << endl;
}
