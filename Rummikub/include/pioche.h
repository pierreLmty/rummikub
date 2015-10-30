#ifndef PIOCHE_H
#define PIOCHE_H

#include "tuile.h"
#include <vector>
#include "factory.h"

using namespace std;

class pioche
{
    public:
        pioche();
        void createPioche();
        void distribuer();
        tuile *piocher();
    protected:
    private:
       vector<tuile *> piocheListe_;
       string couleur[4] = {"rouge", "jaune", "bleu", "noir"};
       factory *fact_;
};

#endif // PIOCHE_H
