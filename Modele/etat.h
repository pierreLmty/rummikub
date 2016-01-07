#ifndef ETAT_H
#define ETAT_H

using namespace std;

class etat
{
    public:
        etat();
	/**
	* \fn void enAttente()
	* \brief Le plateau attend que le joueur entre une série de tuile pour ensuite les faire vérifier. Si le joueur ne rentre rien, le plateau reste dans cet état d'attente
	*/
        virtual void enAttente() = 0;
	/**
	* \fn void faireVerif()
	* \brief Lance la série de vérifications à effectuer sur les listes envoyées par le joueur
	*/
        virtual void faireVerif() = 0;
	/**
	* \fn void afficher()
	* \brief Fonction à destination du joueur pour lui indiquer où en est le jeu
	*/
        virtual void afficher() = 0;
	/**
	* \fn void afficher()
	* \brief Fonction à destination du joueur pour lui indiquer où en est le jeu
	*/
	/**
	* \fn void valider(plateau * p)
	* \brief Transfert les tuiles du chevalet du joueur et du plateau de jeu (pour les listes modifiées) vers le plateau de jeu pour former les nouvelles listes valides
	*/
        virtual void valider() = 0;
    private:
};

#endif // ETAT_H
