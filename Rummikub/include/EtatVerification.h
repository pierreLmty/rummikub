#ifndef ETATVERIFICATION_H
#define ETATVERIFICATION_H

using namespace std;

class EtatVerification : public Etat
{
    private:
        Plateau * plateau;
    public:
        EtatVerification(Plateau * p);
        virtual ~EtatVerification();
        void faireVerif();
        void afficher();
};

#endif // ETATVERIFICATION_H
