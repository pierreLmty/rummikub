#ifndef ETAT_H
#define ETAT_H
#include <string>
#include <iostream>
#include "Plateau.h"

using namespace std;

class Etat
{
    protected:
    Plateau plateau;

    public:
        Etat(Plateau p){
            plateau = p;
        }
        virtual void faireVerif(){}
        virtual void enAttente(){}
        virtual void validation(){}
        virtual void afficher() = 0;
};

#endif
