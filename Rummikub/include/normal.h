#ifndef NORMAL_H
#define NORMAL_H

#include "tuile.h"
#include <iostream>

using namespace std;

class normal : public tuile
{
    public:
        normal(int, int, string, int);
        int getId();
        int getValeur();
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

#endif // NORMAL_H
