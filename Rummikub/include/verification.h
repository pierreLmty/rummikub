#ifndef VERIFICATION_H
#define VERIFICATION_H
#include "etat.h"
#include "plateau.h"

using namespace std;

class verification : public etat
{
    public:
        verification(plateau *);
        void faireVerif();
        void enAttente(){}
        void afficher();
    private:
        plateau * plateau_;
};

#endif // VERIFICATION_H
