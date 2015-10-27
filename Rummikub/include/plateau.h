#ifndef PLATEAU_H
#define PLATEAU_H
#include "etat.h"
#include <vector>

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
    vector<int> getList();
    void setList(int);
    bool emptyList();
    void clearTab();
    vector<vector<int> > getPlateau();
    void setPlateau(int, int, int);

private:
    etat * etatAttente_;
    etat * etatVerification_;
    etat * etatCourant_;
    etat * etatValide_;
    vector<vector<int> > mat;
    vector<int> tab;
};

#endif // PLATEAU_H
