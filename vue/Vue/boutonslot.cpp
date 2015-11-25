#include "Vue/boutonslot.h"
#include <QPushButton>
#include <vector>
#include <iostream>
boutonSlot::boutonSlot(){}

boutonSlot::boutonSlot(plateau * p){
    plateau_ = p;
}

void boutonSlot::creerBoutonChevalet(QString buttonName){
    QStringList tab = buttonName.split("_");
    QStringList c;
    QStringList val;
    for(int i = 0; i < tab.size(); i++){
        if(tab[i].contains(".")){
            c = tab[i].split(".");
        }
        if(tab[i].contains("/")){
            val = tab[i].split("/");
        }
    }
    tuile * t = plateau_->getJoueur()->getChevalet()->getTuile(val[1].toInt(), c[0].toStdString());
    plateau_->ajouterTuile(t);
}

void boutonSlot::creerBoutonPlateau(QString buttonName){
    QStringList tab = buttonName.split("_");
    QStringList c;
    QStringList val;
    for(int i = 0; i < tab.size(); i++){
        if(tab[i].contains(".")){
            c = tab[i].split(".");
        }
        if(tab[i].contains("/")){
            val = tab[i].split("/");
        }
    }
    tuile * t = plateau_->getTuile(val[1].toInt(), c[0].toStdString());
    plateau_->ajouterTuile(t);
}
