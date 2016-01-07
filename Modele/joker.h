#ifndef JOKER_H
#define JOKER_H

#include "tuile.h"
#include <iostream>

using namespace std;

class joker : public tuile
{
    public:
        joker(int, int, string, int);
        int getId();
        int getValeur();
	/**
	* \fn void setValeur(int valeur)
	* \brief Définit la nouvelle valeur de l'objet joker
	* \param valeur la nouvelle valeur de l'objet
	*/
        void setValeur(int);
	/**
	* \fn string getCouleur()
	* \brief Récupère la couleur d'un objet joker
	* \return la couleur de l'objet
	*/
        string getCouleur();
	/**
	* \fn int getEmplacement()
	* \brief Récupère l'emplacement d'un objet joker
	* \return l'emplacement de l'objet
	*/
        int getEmplacement();
	/**
	* \fn void setEmplacement(int e)
	* \brief Définit le nouvel emplacement d'un objet joker si celui-çi est utilisé par un joueur
	* \param e le futur emplacement de l'objet joker (ne peut pas être égal à 0)
	*/
        void setEmplacement(int);
	/**
	* \fn string toString()
	* \brief Affiche les caractéristiques de l'objet joker
	*/
        string toString();
    protected:
    private:
        int id_;
        int valeur_;
        string couleur_;
        int emplacement_;
};

#endif // JOKER_H
