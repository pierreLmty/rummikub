#ifndef TUILEFACTORY_H
#define TUILEFACTORY_H

#include "factory.h"
#include "tuile.h"
#include "normal.h"
#include "joker.h"

using namespace std;

class tuileFactory : public factory
{
    public:
        tuileFactory();
        tuile *createTuile(string, int, int, string);
    protected:
    private:
        tuile * tuile_;
};

#endif // TUILEFACTORY_H
