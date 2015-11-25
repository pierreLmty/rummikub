#ifndef ETAT_H
#define ETAT_H

using namespace std;

class etat
{
    public:
        etat();
        virtual void enAttente() = 0;
        virtual void faireVerif() = 0;
        virtual void afficher() = 0;
        virtual void valider() = 0;
    private:
};

#endif // ETAT_H
