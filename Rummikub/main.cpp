#include <iostream>
#include "plateau.h"
#include "joueur.h"
#include "chevalet.h"
#include "pioche.h"
#include <vector>

using namespace std;

int main()
{
    plateau * p = new plateau;
    joueur * j1 = new joueur;
    joueur * j2 = new joueur;
    pioche * pioch = new pioche;
    pioch->createPioche();
    vector<joueur *> listeJoueur;
    listeJoueur.push_back(j1);
    listeJoueur.push_back(j2);
    p->setJoueur(j1);
    //pioch->distribuer(listeJoueur);
    j1->getChevalet()->afficher();
    int i = 0;
    while(1){
        cout << "choisissez une action :" << endl << " 1. Piocher" << endl << " 2. Envoyer une liste" << endl;
        cin >> i;
        if(i == 1){
            j1->setChevalet(pioch->piocher());
            j1->getChevalet()->afficher();
        }
        else{
            p->enAttente();
            j1->getChevalet()->afficher();
            p->faireVerif();
            p->valider();
            j1->getChevalet()->afficher();
        }
    }
    return 1;
}
