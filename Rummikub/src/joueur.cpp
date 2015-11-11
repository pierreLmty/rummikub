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

int joueur::getScore(){
    return score_;
}

void joueur::setScore(int s){
    score_ = s;
}

chevalet * joueur::getChevalet(){
    return chevalet_;
}

void joueur::setChevalet(tuile * t){
    chevalet_->addTuile(t);
}

void joueur::retirerTuile(tuile * tuile){
    tuile->setEmplacement(2);
    chevalet_->deleteTuile(tuile);
}
