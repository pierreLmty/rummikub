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
        bool longueurMin(vector<tuile *>);
        bool longueurMax(vector<tuile *>);
        bool longueurMaxBC(vector<tuile *>);
        bool problemeCouleurSuite(vector<tuile *>);
        bool problemeNumeroSuite(vector<tuile *>);
        bool problemeCouleurBC(vector<tuile *>);
        bool problemeNumeroBC(vector<tuile *>);
        bool verifSuite(vector<tuile *>, bool, bool);
        bool verifBC(vector<tuile *>, bool, bool);
        bool firstMain(vector<tuile *>);
        bool compteur30Points(vector<tuile *>);
        void enAttente(){}
        void valider(){}
    private:
        plateau * plateau_;
};

#endif // VERIFICATION_H
