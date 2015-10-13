#ifndef NORMAL_H
#define NORMAL_H
#include <string>
#include "Tuile.h"

using namespace std;

class Joker : public Tuile
{
	private:
	
	int id_;
	int valeur_;
	string couleur_;
	
	public:
	
	Joker(int id, int valeur, string couleur) : id_(id), valeur_(30), couleur_(couleur) {}
	
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
