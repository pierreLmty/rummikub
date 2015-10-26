#include "attente.h"
#include <iostream>

using namespace std;

attente::attente(plateau * p){
    plateau_ = p;
}

void attente::enAttente(){
    cout << "en attente";
    plateau_->setState(plateau_->getStateVerif());
}

void attente::afficher(){
    cout << "en attente afficher";
}
