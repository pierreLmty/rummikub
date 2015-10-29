#include "joueur.h"

using namespace std;

joueur::joueur(){
    firstMain_ = true;
    chevalet_.push_back(9);
    chevalet_.push_back(10);
    chevalet_.push_back(11);
    chevalet_.push_back(12);
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

vector<int> joueur::getChevalet(){
    return chevalet_;
}

void joueur::retirerTuile(int tuile){
    chevalet_.erase(chevalet_.begin()+tuile);
}
