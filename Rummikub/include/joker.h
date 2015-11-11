#ifndef JOKER_H
#define JOKER_H

#include "tuile.h"

using namespace std;

class joker : public tuile
{
    public:
        joker(int, int, string);;
        int getId();
        int getValeur();
        void setValeur(int);
        string getCouleur();
    protected:
    private:
        int id_;
        int valeur_;
        string couleur_;
};

#endif // JOKER_H
