#ifndef ETAT_H
#define ETAT_H
#include "Plateau.h"

using namespace std;

class Etat
{
    private:

    public:
        Etat(Plateau* p);
        virtual ~Etat();
        virtual void faireVerif();
        virtual void enAttente();
        virtual void validation();
        virtual void afficher();
    protected:
};

#endif // ETAT_H
