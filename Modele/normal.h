#ifndef NORMAL_H
#define NORMAL_H

#include "tuile.h"
#include <iostream>

using namespace std;

class normal : public tuile
{
    public:
        normal(int, int, string, int);
	/**
	* \fn int getId()
	* \brief Récupère l'id d'un objet normal
	* \return l'id de l'objet
	*/
        int getId();
	/**
	* \fn int getValeur()
	* \brief Récupère la valeur d'un objet normal
	* \return la valeur de l'objet
	*/
        int getValeur();
	/**
	* \fn string getCouleur()
	* \brief Récupère la couleur d'un objet normal
	* \return la couleur de l'objet
	*/
        string getCouleur();
	/**
	* \fn int getEmplacement()
	* \brief Récupère l'emplacement d'un objet normal
	* \return l'emplacement de l'objet
	*/
        int getEmplacement();
	/**
	* \fn void setEmplacement(int e)
	* \brief Définit le nouvel emplacement d'un objet normal si celui-çi est utilisé par un joueur
	* \param e le futur emplacement de l'objet normal (ne peut pas être égal à 0)
	*/
        void setEmplacement(int);
	/**
	* \fn string toString()
	* \brief Affiche les caractéristiques de l'objet normal
	*/
        string toString();
    protected:
    private:
        int id_;
        int valeur_;
        string couleur_;
        int emplacement_;
};

#endif // NORMAL_H
