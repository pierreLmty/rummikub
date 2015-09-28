#include <iostream>
#include <string>

using namespace std;

class Joueur
{
	private:
	
	int id;
	string pseudo;
	int score;
	bool firstMain;
	
	public:
	
	int getId()
	{
		return id;
	}
	
	string getPseudo()
	{
		return pseudo;
	}
	
	int getScore()
	{
		return score;
	}
};
