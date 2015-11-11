#ifndef JOKER_H
#define JOKER_H

#include "tuile.h"
#include <iostream>

using namespace std;

class joker : public tuile
{
    public:
        joker(int, int, string, int);
        int getId();
        int getValeur();
        void setValeur(int);
        string getCouleur();
        int getEmplacement();
        void setEmplacement(int);
        string toString();
    protected:
    private:
        int id_;
        int valeur_;
        string couleur_;
        int emplacement_;
};

#endif // JOKER_H
