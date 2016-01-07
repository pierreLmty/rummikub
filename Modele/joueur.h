#ifndef JOUEUR_H
#define JOUEUR_H
#include <vector>
#include "chevalet.h"

using namespace std;

class joueur
{
    public:
        joueur(int);
	/**
	* \fn bool getFirstMain()
	* \brief Récupère l'état de l'attribut firstMain_ d'un objet joueur
	* \return la valeur du booléen
	*/
        bool getFirstMain();
	/**
	* \fn void setFirstMain(bool firstMain)
	* \brief Définit la nouvelle valeur booléenne de l'attribut firstMain_ de l'objet joueur
	* \param valeur la nouvelle valeur booléenne de firstMain_
	*/
        void setFirstMain(bool);
	/**
	* \fn int getId()
	* \brief Récupère l'id d'un objet joueur
	* \return l'id de l'objet
	*/
        int getId();
	/**
	* \fn int getScore()
	* \brief Récupère le score d'un objet joueur
	* \return le score de l'objet
	*/
        int getScore();
	/**
	* \fn void setScore(int score)
	* \brief Modifie le score du joueur
	* \param score Le score du joueur
	*/
        void setScore(int);
	/**
	* \fn chevalet * getChevalet()
	* \brief Récupère le chevalet d'un objet joueur
	* \see chevalet.cpp
	* \return le chevalet de l'objet
	*/
        chevalet *getChevalet();
	/**
	* \fn void setChevalet(tuile * t)
	* \brief Ajoute un objet de type tuile au chevalet du joueur
	* \see chevalet.cpp
	* \param t la tuile à ajouter au chevalet
	*/
        void setChevalet(tuile *);
	/**
	* \fn void retirerTuile(tuile * tuile)
	* \brief Retire un objet de type tuile du chevalet du joueur et change l'emplacement de cet objet
	* \see chevalet.cpp
	* \param tuile la tuile à retirer du chevalet
	*/
        void retirerTuile(tuile *);
	/**
	* \fn tuile * getTuile(int val, string couleur)
	* \brief Récupère un objet de type tuile du chevalet du joueur selon sa valeur et sa couleur
	* \see chevalet.cpp
	* \param val la valeur de la tuile à récupérer
	* \param couleur la couleur de la tuile à récupérer
	*/
        tuile *getTuile(int, string);
    private:
        bool firstMain_;
        int id_;
        int score_;
        chevalet * chevalet_;
};

#endif // JOUEUR_H
