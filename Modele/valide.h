#ifndef VALIDE_H
#define VALIDE_H
#include "plateau.h"

using namespace std;

class valide : public etat
{
    public:
        valide(plateau *);
	/**
* \fn void afficher()
* \brief Fonction à destination du joueur pour lui indiquer que la liste envoyée est valide
*/
        void afficher();
        void faireVerif(){}
        void enAttente(){}
        /**
* \fn void valider(plateau * p)
* \brief Transfert les tuiles du chevalet du joueur et du plateau de jeu (pour les listes modifiées) vers le plateau de jeu pour former les nouvelles listes valides
*/
        void valider();
    private:
        plateau * plateau_;
};

#endif // VALIDE_H
