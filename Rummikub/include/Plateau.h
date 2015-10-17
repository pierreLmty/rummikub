#ifndef PLATEAU_H
#define PLATEAU_H
#include "Etat.h"

using namespace std;

class Plateau
{
    public:
        Plateau(EtatVerfication());
        virtual ~Plateau();
        void afficher();
        void faireVerf();
        Etat getEtatValide();
        Etat getEtat();
    protected:
    private:
	Etat etatCourant_;
	Etat etatValide_;
	Etat etatVerif_;
};

#endif // PLATEAU_H
