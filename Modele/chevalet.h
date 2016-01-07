#ifndef CHEVALET_H
#define CHEVALET_H
#include "tuile.h"
#include <vector>

using namespace std;

class chevalet
{
    public:
        chevalet();
	/**
	* \fn void trierChevalet()
	* \brief Trie le chevalet du joueur en fonction de la valeur des tuiles
	*/
        void trierChevalet();
	
	/**
	* \fn tuile * getTuile(int val, string couleur)
	* \brief Récupère un objet de type tuile du chevalet du joueur selon sa valeur et sa couleur
	* \param val la valeur de la tuile à récupérer
	* \param couleur la couleur de la tuile à récupérer
	* \return Retourne un objet tuile du chevalet
	*/
        tuile *getTuile(int, string);
	/**
	* \fn void addTuile(tuile * t)
	* \brief Ajoute un objet de type tuile dans le chevalet
	* \param t un objet de type tuile
	*/
        void addTuile(tuile*);
	/**
	* \fn void deleteTuile(tuile * t)
	* \brief Retire un objet de type tuile du chevalet
	* \param t un objet de type tuile
	*/
        void deleteTuile(tuile*);
	/**
	* \fn void getTaille()
	* \brief Retourne la taille de la pioche
	*/
        int getTaille();
	
	/**
	* \fn void getUneTuile(int indice)
	* \brief Retourne une tuile à un indice donné du chevalet
	* \param indice l'indice où l'on cherche la tuile
	*/
        tuile * getUneTuile(int);
	/**
	* \fn void afficher()
	* \brief Affiche l'ensemble des tuiles du chevalet
	*/
        void afficher();
	/**
	* \fn vector<tuile *> getChevalet(indice)
	* \brief Retourne le chevalet
	*/
        vector<tuile *> getChevalet();
    private:
        vector<tuile *> chevalet_;
};

#endif // CHEVALET_H
