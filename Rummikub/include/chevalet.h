#ifndef CHEVALET_H
#define CHEVALET_H
#include "tuile.h"
#include <vector>

using namespace std;

class chevalet
{
    public:
        chevalet();
        void trierChevalet();
        tuile *getTuile(int, string);
        void addTuile(tuile*);
        void deleteTuile(tuile*);
        void afficher();
    private:
        vector<tuile *> chevalet_;
};

#endif // CHEVALET_H
