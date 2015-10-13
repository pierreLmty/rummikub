#ifndef NORMAL_H
#define NORMAL_H
#include <string>
#include "Tuile.h"

using namespace std;

class Normal : public Tuile
{
	private:
	
	int id_;
	int valeur_;
	string couleur_;
	
	public:
	
	Normal(int id, int valeur, string couleur) : id_(id), valeur_(valeur), couleur_(couleur) {}
	
	int getId()
	{
		return id_;
	}
	
	int getValeur()
	{
		return valeur_;
	}
	
	int getCouleur()
	{
		return couleur_;
	}
};
#endif
