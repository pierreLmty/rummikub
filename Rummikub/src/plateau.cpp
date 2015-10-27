#include "plateau.h"
#include "attente.h"
#include "verification.h"
#include "valide.h"
#include <iostream>

using namespace std;

plateau::plateau(){
    etatCourant_ = new attente(this);
    etatAttente_ = new attente(this);
    etatVerification_ = new verification(this);
    etatValide_ = new valide(this);
    mat.resize(13, std::vector<int>(13, 0));
}

etat *plateau::getState(){
    return etatAttente_;
}

etat *plateau::getStateVerif(){
    return etatVerification_;
}

etat *plateau::getStateValide(){
    return etatValide_;
}

etat *plateau::getStateAttente(){
    return etatAttente_;
}

void plateau::setState(etat * etat){
    etatCourant_ = etat;
}

void plateau::faireVerif(){
    etatCourant_->faireVerif();
}

void plateau::valider(){
    etatCourant_->valider();
}

void plateau::enAttente(){
    etatCourant_->enAttente();
}

void plateau::afficher(){
    cout << endl;
    for(unsigned int i=0; i< mat.size(); ++i){
        for(unsigned int j=0; j< mat.size(); ++j){
            cout << mat[i][j];
        }
        cout << " | " << endl;
    }
    etatCourant_->afficher();
}

vector<int> plateau::getList(){
    return tab;
}

void plateau::setList(int a){
    tab.push_back(a);
}

bool plateau::emptyList(){
    return tab.empty();
}

void plateau::clearTab(){
    tab.clear();
}

vector<vector<int> > plateau::getPlateau(){
    return mat;
}

void plateau::setPlateau(int a, int i, int j){
    mat[i][j] = a;
}
