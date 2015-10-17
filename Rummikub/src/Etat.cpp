#include <string>
#include <iostream>
#include "Etat.h"
#include "Plateau.h"

using namespace std;
Etat(Plateau *p){}
virtual void faireVerif() = 0;
virtual void enAttente(){}
virtual void validation(){}
void afficher(){
    cout << "ici";
}
