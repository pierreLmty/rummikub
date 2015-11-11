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
        bool getTuile(tuile*);
        void addTuile(tuile*);
        void deleteTuile(tuile*);
    private:
        vector<tuile *> chevalet_;
};

#endif // CHEVALET_H
