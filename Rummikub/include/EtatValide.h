#ifndef ETATVALIDE_H
#define ETATVALIDE_H

using namespace std;

class EtatValide : public Etat
{
    private:
        Plateau plateau;
    public:
        EtatValide(Plateau p);
        virtual ~EtatValide();
        void afficher();
};

#endif // ETATVALIDE_H
