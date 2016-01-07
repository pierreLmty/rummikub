#ifndef TUILE_H
#define TUILE_H
#include <string>

using namespace std;

class tuile
{
    public:
        tuile();
	/**
* \fn string getCouleur()
* \brief Récupère la couleur d'un objet tuile
*/
        virtual string getCouleur() = 0;
	/**
* \fn int getValeur(plateau * p)
* \brief Récupère la valeur d'un objet tuile
*/
        virtual int getValeur() = 0;
	/**
* \fn int getId()
* \brief Récupère l'id d'un objet tuile
*/
        virtual int getId() = 0;
	/**
* \fn int getEmplacement()
* \brief Récupère l'emplacement courant où se trouve l'objet tuile (dans la pioche, dans un chevalet ou sur le plateau)
*/
        virtual int getEmplacement() = 0;
	/**
* \fn void setEmplacement(int)
* \brief Définit le nouvel emplacement d'un objet tuile si celui-çi est utilisé par un joueur
* \param int le futur emplacement de l'objet tuile (ne peut pas être égal à 0)
*/
        virtual void setEmplacement(int) = 0;
	/**
* \fn string toString()
* \brief Affiche les caractéristiques de l'objet tuile
*/
        virtual string toString() = 0;
    protected:
    private:
        int emplacement_;//0 : pioche, 1 : chevalet, 2 : plateau
};

#endif // TUILE_H
