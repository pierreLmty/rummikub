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
    private:
        vector<tuile *> chevalet_;
};

#endif // CHEVALET_H
