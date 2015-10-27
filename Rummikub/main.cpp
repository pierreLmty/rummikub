#include <iostream>
#include "plateau.h"

using namespace std;

int main()
{
    plateau * p = new plateau;
    p->enAttente();
    p->faireVerif();
    p->valider();
    p->enAttente();
    p->faireVerif();
    p->valider();
    p->enAttente();
    p->faireVerif();
    p->valider();
    p->enAttente();
    return 0;
}
