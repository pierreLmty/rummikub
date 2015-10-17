#include "Etat.h"
#include "EtatVerification.h"
#include "EtatValide.h"
#include <string>
#include <iostream>

using namespace std;

Plateau::Plateau(EtatVerfication etatCourant, EtatValide etatValide, EtatVerfication etatVerif): etatCourant_(etatCourant), etatValide_(etatValide), etatVerif_(etatVerif){}

Etat getEtat(){
    return etatCourant_;
}

Etat getEtatValide(){
    return etatValide_;
}

void faireVerf(){
    cout << "truc";
}

void afficher(){
    etatCourant_.afficher();
}
