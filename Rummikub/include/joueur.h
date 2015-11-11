#ifndef JOUEUR_H
#define JOUEUR_H
#include <vector>
#include "chevalet.h"

using namespace std;

class joueur
{
    public:
        joueur();
        bool getFirstMain();
        void setFirstMain(bool);
        int getId();
        chevalet *getChevalet();
        void setChevalet(tuile *);
        void retirerTuile(tuile *);
    private:
        bool firstMain_;
        int id_;
        chevalet * chevalet_;
};

#endif // JOUEUR_H
