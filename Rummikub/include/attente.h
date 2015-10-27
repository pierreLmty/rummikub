#ifndef ATTENTE_H
#define ATTENTE_H

#include "etat.h"
#include "plateau.h"

using namespace std;

class attente : public etat
{
    public:
        attente(plateau *);
        void enAttente();
        void faireVerif(){}
        void valider(){}
        void afficher();
    private:
        plateau * plateau_;
};

#endif // ATTENTE_H
