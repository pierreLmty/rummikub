#ifndef PLATEAU_H
#define PLATEAU_H
#include "etat.h"
#include <vector>
#include "tuile.h"
#include "joueur.h"

using namespace std;

class plateau
{
public:
    plateau();
    etat *getState();
    etat *getStateVerif();
    etat *getStateValide();
    etat *getStateAttente();
    void setState(etat *);
    void faireVerif();
    void valider();
    void enAttente();
    void afficher();
    vector<tuile *> getList();
    void setList(tuile *);
    bool emptyList();
    void clearTab();
    vector<vector<tuile *> > getPlateau();
    void setPlateau(tuile *, int, int);
    tuile *getTuile(int, string);
    void setJoueur(joueur *);
    joueur *getJoueur();

private:
    etat * etatAttente_;
    etat * etatVerification_;
    etat * etatCourant_;
    etat * etatValide_;
    vector<vector<tuile *> > mat_;
    vector<tuile *> tab_;
    joueur * joueur_;
};

#endif // PLATEAU_H
