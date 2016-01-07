#ifndef PLATEAU_H
#define PLATEAU_H
#include "Modele/etat.h"
#include <vector>
#include "Modele/tuile.h"
#include "Modele/joueur.h"

using namespace std;

class plateau
{
public:
    plateau(vector<joueur *>);
    /**
* \fn etat * getState()
* \brief Retourne l'état dans lequel se trouve le plateau
* \return Un état du plateau
*/
    etat *getState();
    /**
* \fn etat * getStateVerif()
* \brief Retourne l'état de vérification
* \return L'état de vérification
*/
    etat *getStateVerif();
    /**
* \fn etat * getStateValide()
* \brief Retourne l'état valide
* \return L'état valide
*/
    etat *getStateValide();
    /**
* \fn etat * getStateAttente()
* \brief Retourne l'état d'attente
* \return L'état d'attente
*/
    etat *getStateAttente();
    /**
* \fn void setState(etat * etat)
* \brief Définit le nouvel du plateau dans lequel il vient d'arriver
* \param etat Le nouvel état du plateau
*/
    void setState(etat *);
    /**
* \fn void faireVerif()
* \brief Lance la série de vérification sur les listes envoyées par le joueur
*/
    void faireVerif();
    /**
* \fn void valider()
* \brief Transfert les tuiles du chevalet du joueur et du plateau de jeu (pour les listes modifiées) vers le plateau de jeu pour former les nouvelles listes valides
*/
    void valider();
    /**
* \fn void enAttente()
* \brief Le plateau attend que le joueur entre une série de tuile pour ensuite les faire vérifier. Si le joueur ne rentre rien, le plateau reste dans cet état d'attente
*/
    void enAttente();
    /**
* \fn void afficher()
* \brief Affiche le plateau de jeu (mode console uniquement)
*/
    void afficher();
    /**
* \fn vector<tuile *> getList()
* \brief Récupère la liste de tuiles temporaires faite par le joueur
* \return tab_ La liste de tuile temporaire
*/
    vector<tuile *> getList();
    /**
* \fn void setList(tuile * a)
* \brief Ajoute une tuile à la liste temporaire qui sera vérifiée par la fonction de vérification
* \param a Une tuile à ajouter à la liste temporaire
*/
    void setList(tuile *, int);
    /**
* \fn bool emptyList()
* \brief Vérifie si la liste temporaire est vide ou non
* \return Retourne Vrai si la liste est vide sinon Faux
*/
    bool emptyList();
    /**
* \fn void clearTab()
* \brief Supprime tous les éléments de la liste temporaire
*/
    void clearTab();
    /**
* \fn vector<vector<tuile *> > getPlateau()
* \brief Retourne le plateau de jeu
* \return La matrice qui sert de plateau de jeu
*/
    vector<vector<tuile *> > getPlateau();
    /**
* \fn void setPlateau(tuile * a, int i, int j)
* \brief
* \param a
* \param i
* \param j
*/
    void setPlateau(tuile *, int, int);
    /**
* \fn tuile * getTuile(int val, string couleur)
* \brief Récupère une tuile du plateau de jeu en fonction de la valeur et de la couleur passées en paramètre
* \param val la valeur de la tuile recherchée
* \param couleur La couleur de la tuile recherchée
* \return Un objet de type tuile
*/
    tuile *getTuile(int, string);
    /**
* \fn void retirerTuile(tuile * t)
* \brief Supprime une tuile passée en paramètre
* \param t La tuile à supprimer
*/
    void retirerTuile(tuile *);
    /**
* \fn void setJoueur()
* \brief Définit un nouveau joueur pour le jeu
* \param j Un objet de type joueur
*/
    void setJoueur(joueur *);
    /**
* \fn joueur * getJoueur()
* \brief Retourne un joueur du jeu
* \return Un objet de type joueur
*/
    joueur *getJoueur();
    /**
* \fn void ajouterTuile(tuile * t)
* \brief Ajoute un objet tuile à la liste temporaire
* \param t Un objet de type tuile
*/
    void ajouterTuile(tuile *);
    /**
* \fn void setListeJoueur(vector<joueur *> j)
* \brief définit la liste de joueur du jeu
* \param j une liste d'objet de type joueur
*/
    void setListeJoueur(vector<joueur *>);
    /**
* \fn joueur * getJoueur()
* \brief Retourne la liste des joueurs du jeu
* \return La liste des objets de type joueur
*/
    vector<joueur *> getListeJoueur();

private:
    etat * etatAttente_;
    etat * etatVerification_;
    etat * etatCourant_;
    etat * etatValide_;
    vector<vector<tuile *> > mat_;
    vector<tuile *> tab_;
    joueur * joueur_;
    vector<joueur *> listeJoueur_;
};

#endif // PLATEAU_H
