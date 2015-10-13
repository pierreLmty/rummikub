#ifndef ETATVERIFICATION_H
#define ETATVERIFICATION_H
#include <string>
#include <iostream>
#include "Plateau.h"
#include "Etat.h"

using namespace std;

class EtatVerification : public Etat
{
private:
	Plateau* plateau;

public:
	EtatVerification(Plateau* p){plateau = p;};

	void faireVerif(){
		int i = 0;
		int p = 2;
	}

	void afficher(){
		cout << "Nous effectuons les vérifications nécessaires" << endl;
	}
};
#endif
