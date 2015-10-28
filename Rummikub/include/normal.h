#ifndef NORMAL_H
#define NORMAL_H

#include "tuile.h"

using namespace std;

class normal : public tuile
{
    public:
        normal(int, int, string);
        int getId();
        int getValeur();
        string getCouleur();
    protected:
    private:
        int id_;
        int valeur_;
        string couleur_;
};

#endif // NORMAL_H
