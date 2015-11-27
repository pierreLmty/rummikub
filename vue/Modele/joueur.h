#ifndef JOUEUR_H
#define JOUEUR_H
#include <vector>
#include "chevalet.h"

using namespace std;

class joueur
{
    public:
        joueur(int);
        bool getFirstMain();
        void setFirstMain(bool);
        int getId();
        int getScore();
        void setScore(int);
        chevalet *getChevalet();
        void setChevalet(tuile *);
        void retirerTuile(tuile *);
        tuile *getTuile(int, string);
    private:
        bool firstMain_;
        int id_;
        int score_;
        chevalet * chevalet_;
};

#endif // JOUEUR_H
