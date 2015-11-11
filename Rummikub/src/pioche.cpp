#include "pioche.h"
#include "tuile.h"

#include <algorithm>
#include "tuileFactory.h"

using namespace std;

pioche::pioche()
{
    piocheListe_.resize(106);
    fact_ = new tuileFactory();
}

void pioche::createPioche()
{
    int indice = 0;

    for (int k=1; k<=2; ++k) //on double le jeu
    {
        for (int i=0; i<=3; ++i) //choix de la couleur
        {
            for (int j=1; j<=13; ++j) //choix de la valeur
            {
                piocheListe_[indice] = fact_->createTuile("normal", indice, j, couleur[i]);
                ++indice;
            }
        }
    }
    piocheListe_[indice] = fact_->createTuile("joker", indice, 30, "noir");
    ++indice;
    piocheListe_[indice] = fact_->createTuile("joker", indice, 30, "rouge");
    random_shuffle (piocheListe_.begin(), piocheListe_.end());
}

void pioche::distribuer(vector<joueur *> listeJoueur)
{
    for(int i=1; i<= 13; ++i)
    {
        for(int j = 0; j != listeJoueur.size();++j)
        {
            listeJoueur[j]->setChevalet(piocher());
        }
    }
}

tuile *pioche::piocher()
{
    tuile * t = piocheListe_.at(0);
    piocheListe_.erase(piocheListe_.begin());
    return t;
}
