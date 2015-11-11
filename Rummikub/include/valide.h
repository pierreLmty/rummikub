#ifndef VALIDE_H
#define VALIDE_H
#include "plateau.h"

using namespace std;

class valide : public etat
{
    public:
        valide(plateau *);
        void afficher();
        void faireVerif(){}
        void enAttente(){}
        void valider();
    private:
        plateau * plateau_;
};

#endif // VALIDE_H
