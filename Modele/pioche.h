#ifndef PIOCHE_H
#define PIOCHE_H

#include "tuile.h"
#include <vector>
#include "factory.h"
#include "joueur.h"

using namespace std;

class pioche
{
    public:
        pioche();
	/**
	* \fn void createPioche()
	* \brief Construit la pioche en créant 106 objets tuiles (104 objets de type "normal" et 2 objets de type "joker") puis en la mélangeant
	*/
        void createPioche();
	/**
	* \fn void distribuer(vector<joueur *> listeJoueur)
	* \brief Construit la pioche en créant 106 objets tuiles (104 objets de type "normal" et 2 objets de type "joker") puis en la mélangeant
	* \param listeJoueur La liste des joueurs qui sont en jeu
	*/
        void distribuer(vector<joueur *>);
	/**
	* \fn tuile * piocher()
	* \brief Picohe une tuile dans la pioche mélangée
	* \return t La tuile piochée par le joueur
	*/
        tuile *piocher();
    protected:
    private:
       vector<tuile *> piocheListe_;
       string couleur[4] = {"rouge", "jaune", "bleu", "noir"};
       factory *fact_;
};

#endif // PIOCHE_H
