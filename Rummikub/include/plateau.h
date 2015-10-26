#ifndef PLATEAU_H
#define PLATEAU_H
#include "etat.h"

using namespace std;

class plateau
{
    public:
        plateau();
        etat *getState();
        void setState(etat *);
        etat *getStateVerif();
        void afficher();
        void enAttente();
        void faireVerif();
    private:
        etat * etatAttente_;
        etat * etatVerification_;
        etat * etatCourant_;
};

#endif // PLATEAU_H
