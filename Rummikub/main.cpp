#include <iostream>
#include "plateau.h"
#include "joueur.h"
#include "chevalet.h"
#include "pioche.h"
#include <vector>

using namespace std;

int main()
{
    vector<joueur *> listeJoueur;
    chevalet * chevaletTmp;
    plateau * p = new plateau;
    joueur * joueurGagnant;
    unsigned int nbrJoueur = 0;
    bool finPartie = false;
    int score = 0;
    unsigned int aQuiLeTour = 0;
    int i,j = 0;

    do{
        cout << "Entrez le nombre de joueur :" << endl;
        cin >> nbrJoueur;
    }while(nbrJoueur < 2 || nbrJoueur > 4);
    cout << "Nombre de joueur dans la partie : " << nbrJoueur << endl;

    for(unsigned int k = 1; k <= nbrJoueur; ++k){
        listeJoueur.push_back(new joueur(k));
        p->setJoueur(listeJoueur[k]);
    }

    pioche * pioch = new pioche;
    pioch->createPioche();
    pioch->distribuer(listeJoueur);

    do{
        do{
            cout << endl;
            cout << "C'est au joueur " << aQuiLeTour +1 << " de jouer" << endl;
            listeJoueur[aQuiLeTour]->getChevalet()->afficher();
            cout << "choisissez une action :" << endl << " 1. Piocher" << endl << " 2. Envoyer une liste" << endl;
            cin >> i;
            if(i == 1){
                listeJoueur[aQuiLeTour]->setChevalet(pioch->piocher());
            }
            else{
                p->enAttente();
                listeJoueur[aQuiLeTour]->getChevalet()->afficher();
                p->afficherMatTmp();
                p->faireVerif();
                p->valider();
                listeJoueur[aQuiLeTour]->getChevalet()->afficher();
            }

            //Vérification si le chevalet du joueur est vide
            if(listeJoueur[aQuiLeTour]->getChevalet()->getTaille() == 0){
                joueurGagnant = listeJoueur[aQuiLeTour];
            }

            ++aQuiLeTour;
            if(aQuiLeTour == nbrJoueur) aQuiLeTour = 0;

        }while(joueurGagnant = NULL);

        //Instructions de comptage de point
        for(unsigned int l = 0; l != listeJoueur.size();++l)
        {
            if(listeJoueur[l] != joueurGagnant){
                chevaletTmp = listeJoueur[l]->getChevalet();

                for(unsigned int i = 0; i < chevaletTmp->getTaille(); ++i){
                    score = chevaletTmp->getUneTuile(i)->getValeur();
                }
            }
        }

        if(joueurGagnant != NULL){
            joueurGagnant->setScore(score);
            score = 0;
            joueurGagnant = NULL;

            cout << "Recommencer une manche ?" << endl << "1. oui" << endl << "2. non" << endl;
            cin >> j;
            if(j == 2) finPartie = true;
        }
    }while(!finPartie);

    cout << "Fin de la partie" << endl;

    return 1;
}
