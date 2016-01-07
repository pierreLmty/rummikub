#ifndef VERIFICATION_H
#define VERIFICATION_H
#include "etat.h"
#include "plateau.h"

using namespace std;

class verification : public etat
{
    public:
        verification(plateau *);
	/**
* \fn void faireVerif()
* \brief Lance la série de vérifications à effectuer sur les listes envoyées par le joueur
*/
        void faireVerif();
	/**
* \fn void afficher()
* \brief Fonction à destination du joueur pour lui indiquer que la liste envoyée est en cours de vérification
*/
        void afficher();
	/**
* \fn bool longueurMin(vector<tuile *> listAVerif)
* \brief Vérifie si la liste envoyée est au moins de longueur 3
* \param listAVerif La liste de tuile à vérifier
* \return Retourne Vrai si la longueur est supérieure à 3 sinon faux
*/
        bool longueurMin(vector<tuile *>);
	/**
* \fn bool longueurMax(vector<tuile *> listAVerif)
* \brief Vérifie si la liste envoyée est inférieure à 13
* \param listAVerif La liste de tuile à vérifier
* \return Retourne Vrai si la longueur est inférieure à 13 sinon faux
*/
        bool longueurMax(vector<tuile *>);
	/**
* \fn bool longueurMaxBC(vector<tuile *> listAVerif)
* \brief Vérifie si la liste envoyée est inférieure à 4 dans le cas où le joueur envoie une liste de brelan ou de carré
* \param listAVerif La liste de tuile à vérifier
* \return Retourne Vrai si la longueur est inférieure à 4 sinon faux
*/
        bool longueurMaxBC(vector<tuile *>);
	/**
* \fn bool problemeCouleurSuite(vector<tuile *> listAVerif)
* \brief Vérifie si la liste envoyée ne contient pas de problemes de couleur. Cette fonction concernera les listes qui seront composées de suite de numéro d'une même couleur. Elle parcourt la liste et selon la présence ou non de joker, verifie si les tuiles avant et après sont valides par rapport à la tuile en cours de traitement.
* \param listAVerif La liste de tuile à vérifier
* \return Retourne Vrai s'il n'y a pas de problème sinon Faux
*/
        bool problemeCouleurSuite(vector<tuile *>);
	/**
* \fn bool problemeNumeroSuite(vector<tuile *> listAVerif)
* \brief Vérifie si la liste envoyée ne contient pas de problemes de numéro. Cette fonction concernera les listes qui seront composées de suite de numéro d'une même couleur. Elle parcourt la liste et selon la présence ou non de joker, verifie si les tuiles avant et après sont valides par rapport à la tuile en cours de traitement.
* \param listAVerif La liste de tuile à vérifier
* \return Retourne Vrai s'il n'y a pas de problème sinon Faux
*/
        bool problemeNumeroSuite(vector<tuile *>);
	/**
* \fn bool problemeCouleurBC(vector<tuile *> listAVerif)
* \brief Vérifie si la liste envoyée ne contient pas de problemes de couleur. Cette fonction concernera les listes qui seront composées de suite de même numéro et de couleurs differentes. Elle parcourt la liste et selon la présence ou non de joker, verifie si les tuiles avant et après sont valides par rapport à la tuile en cours de traitement.
* \param listAVerif La liste de tuile à vérifier
* \return Retourne Vrai s'il n'y a pas de problème sinon Faux
*/
        bool problemeCouleurBC(vector<tuile *>);
	/**
* \fn bool problemeNumeroBC(vector<tuile *> listAVerif)
* \brief Vérifie si la liste envoyée ne contient pas de problemes de numéro. Cette fonction concernera les listes qui seront composees de suite de meme numero et de couleurs differentes. Elle parcourt la liste et selon la présence ou non de joker, verifie si les tuiles avant et après sont valides par rapport à la tuile en cours de traitement.
* \param listAVerif La liste de tuile à vérifier
* \return Retourne Vrai s'il n'y a pas de problème sinon Faux
*/
        bool problemeNumeroBC(vector<tuile *>);
	/**
* \fn bool verifSuite(vector<tuile *> listAVerif, bool boolProbCouleurSuite, bool boolProbNumeroSuite)
* \brief Rassemble les resultats des fonctions problemeCouleurSuite(), problemeNumeroSuite(), longueurMin() et longueurMax() pour renvoyer un booleen verifSuiteOK à Vrai ou à Faux. La fonction va vérifier que la liste est de bonne longueur (longueur minimale et maximale) en appelant les fonctions longueurMin() et longueurMax(). Elle va aussi vérifier que la composition des listes est bonne grace aux résultats des fonctions problemeCouleurSuite() et problemeNumeroSuite()
* \param listAVerif La liste de tuile à vérifier
* \param boolProbCouleurSuite Indique si il y a des problèmes de couleurs dans la liste de type suite
* \param boolProbNumeroSuite Indique si il y a des problèmes de numéros dans la liste de type suite
* \return Retourne Vrai s'il n'y a pas de problème sinon Faux
*/
        bool verifSuite(vector<tuile *>, bool, bool);
	/**
* \fn bool verifBC(vector<tuile *> listAVerif, bool boolProbCouleurBC, bool boolProbNumeroBC)
* \brief Rassemble les résultats des fonctions problemeCouleurBC(), problemeNumeroBC(), longueurMin() et longueurMaxBC() pour renvoyer un booleen verifBCOK à Vrai ou à Faux. La fonction va vérifier que la liste est de bonne longueur (longueur minimale et maximale) en appelant les fonctions longueurMin() et longueurMaxBC(). Elle va aussi vérifier que la composition des listes est bonne grace aux résultats des fonctions problemeCouleurBC() et problemeNumeroBC()
* \param listAVerif La liste de tuile à vérifier
* \param boolProbCouleurBC Indique si il y a des problèmes de couleurs dans la liste de type BC
* \param boolProbNumeroBC Indique si il y a des problèmes de numéros dans la liste de type BC
* \return Retourne Vrai s'il n'y a pas de problème sinon Faux
*/
        bool verifBC(vector<tuile *>, bool, bool);
	/**
* \fn bool compteur30Points(vector<tuile *> matAVerif)
* \brief Intervient seulement lors du premier tour d'un joueur. Compte le nombre de joker, si l'ensemble des tuiles fait 30 points ou plus et si elles ne viennent pas du plateau de jeu.
* \param matAVerif La liste de tuile à vérifier
* \return Retourne Vrai s'il n'y a pas de problème sinon Faux
*/
        bool compteur30Points(vector<tuile *>);
        void enAttente(){}
        void valider(){}
    private:
        plateau * plateau_;
};

#endif // VERIFICATION_H
