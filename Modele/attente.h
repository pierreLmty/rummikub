#ifndef ATTENTE_H
#define ATTENTE_H

#include "etat.h"
#include "plateau.h"

using namespace std;

class attente : public etat
{
    public:
        attente(plateau *);
	/**
	* \fn void enAttente()
	* \brief Le plateau attend que le joueur entre une série de tuile pour ensuite les faire vérifier. Si le joueur ne rentre rien, le plateau reste dans cet état d'attente
	*/
        void enAttente();
        void faireVerif(){}
        void valider(){}
        /**
	* \fn void afficher()
	* \brief Fonction à destination du joueur pour lui indiquer que le plateau est en attente d'une liste
	*/
        void afficher();
    private:
        plateau * plateau_;
};

#endif // ATTENTE_H
