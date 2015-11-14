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
    mat_.resize(13, std::vector<tuile *>(13, NULL));
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

vector<tuile *> plateau::getList(){
    return tab_;
}

void plateau::setList(tuile * a){
    tab_.push_back(a);
}

bool plateau::emptyList(){
    return tab_.empty();
}

void plateau::clearTab(){
    tab_.clear();
}

vector<vector<tuile *> > plateau::getPlateau(){
    return mat_;
}

void plateau::setPlateau(tuile * a, int i, int j){
    mat_[i][j] = a;
}

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

void plateau::setJoueur(joueur * j){
    joueur_ = j;
}

joueur *plateau::getJoueur(){
    return joueur_;
}
