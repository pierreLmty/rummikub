#ifndef ETATVALIDE_H
#define ETATVALIDE_H
#include <string>
#include <iostream>
#include "Plateau.h"
#include "Etat.h"

using namespace std;

class EtatValide : public Etat
{
private:
	Plateau plateau;
public:
	EtatValide(Plateau p){
        plateau = p;
	}
	void afficher(){
		cout << "Les verifs sont OK";
	}
};

#endif
