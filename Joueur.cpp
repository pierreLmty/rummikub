#include <iostream>
#include <string>

using namespace std;

class Joueur
{
	private:
	
	int id_;
	string pseudo_;
	int score_;
	bool firstMain_;
	
	public:
	
	Joueur(int id_, string pseudo_, int score_, bool firstMain_);
	
	int getId()
	{
		return id_;
	}
	
	string getPseudo()
	{
		return pseudo_;
	}
	
	int getScore()
	{
		return score_;
	}
	
	bool getFisrtMain()
	{
		return firstMain_;
	}
};
