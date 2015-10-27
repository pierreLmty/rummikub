#include "attente.h"
#include <iostream>
#include <vector>

using namespace std;

attente::attente(plateau * p){
    plateau_ = p;
}

void attente::enAttente(){
    int a = 0;
    plateau_->clearTab();
    while(a != -1){
        cin >> a;
        if(a != -1){
            plateau_->setList(a);
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
