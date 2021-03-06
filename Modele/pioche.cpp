/**
* \file pioche.cpp
* \author Lemétayer Pierre - Maël Quémard
* \version 1.0
* \date 16 Novembre 2015
* \brief Classe qui définit la pioche du jeu
*/

#include "Modele/pioche.h"
#include "Modele/tuile.h"
#include <algorithm>
#include <ctime>
#include "Modele/tuileFactory.h"

using namespace std;

pioche::pioche()
{
    piocheListe_.resize(106);
    fact_ = new tuileFactory();
    createPioche();
}

/**
* \fn void createPioche()
* \brief Construit la pioche en créant 106 objets tuiles (104 objets de type "normal" et 2 objets de type "joker") puis en la mélangeant
*/
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
    srand(time(0));
    random_shuffle (piocheListe_.begin(), piocheListe_.end());
}

/**
* \fn void distribuer(vector<joueur *> listeJoueur)
* \brief Construit la pioche en créant 106 objets tuiles (104 objets de type "normal" et 2 objets de type "joker") puis en la mélangeant
* \param listeJoueur La liste des joueurs qui sont en jeu
*/
void pioche::distribuer(vector<joueur *> listeJoueur)
{
    for(unsigned int i=1; i<= 13; ++i)
    {
        for(unsigned int j = 0; j != listeJoueur.size();++j)
        {
            listeJoueur[j]->setChevalet(piocher());
        }
    }
}

/**
* \fn tuile * piocher()
* \brief Picohe une tuile dans la pioche mélangée
* \return t La tuile piochée par le joueur
*/
tuile *pioche::piocher()
{
    tuile * t = piocheListe_.at(0);
    t->setEmplacement(1);
    piocheListe_.erase(piocheListe_.begin());
    return t;
}
