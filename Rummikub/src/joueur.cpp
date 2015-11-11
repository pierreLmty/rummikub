#include "joueur.h"

using namespace std;

joueur::joueur(){
    firstMain_ = true;
    chevalet_ = new chevalet;
}

bool joueur::getFirstMain(){
    return firstMain_;
}

void joueur::setFirstMain(bool firstMain){
    firstMain_ = firstMain;
}

int joueur::getId(){
    return id_;
}

chevalet * joueur::getChevalet(){
    return chevalet_;
}

void joueur::setChevalet(tuile * t){
    chevalet_->addTuile(t);
}

void joueur::retirerTuile(tuile * tuile){
    chevalet_->deleteTuile(tuile);
}
