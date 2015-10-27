#ifndef VERIFICATION_H
#define VERIFICATION_H
#include "etat.h"
#include "plateau.h"

using namespace std;

class verification : public etat
{
    public:
        verification(plateau *);
        void faireVerif();
        void afficher();
        bool longueurMin(vector<int>);
        bool longueurMax(vector<int>);
        bool longueurMaxBC(vector<int>);
        bool problemeCouleurSuite(vector<int>);
        bool problemeNumeroSuite(vector<int>);
        bool problemeCouleurBC(vector<int>);
        bool problemeNumeroBC(vector<int>);
        bool verifSuite(vector<int>, bool, bool);
        bool verifBC(vector<int>, bool, bool);
        bool fisrtMain(vector<int>, bool, bool);
        void enAttente(){}
        void valider(){}
    private:
        plateau * plateau_;
};

#endif // VERIFICATION_H
