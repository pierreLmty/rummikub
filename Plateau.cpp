#ifndef PLATEAU_H
#define PLATEAU_H
#include "Etat.h"
#include "EtatVerification.h"
#include "EtatValide.h"
#include <string>
#include <iostream>

using namespace std;

class Plateau
{
    private:
	Etat etatCourant_;
	Etat etatValide_;
	Etat etatVerif_;

    public:
	Plateau(){
        etatCourant_ = new EtatVerification(this);
        etatValide_ = new EtatValide(this);
        etatVerif_ = new EtatVerification(this);
    }

	Etat getEtat(){
		return etatCourant_;
	}

	Etat getEtatValide(){
		return etatValide_;
	}

	void faireVerf(){
		cout << "truc";
	}

	void afficher(){
		etatCourant_.afficher();
	}
};

#endif
