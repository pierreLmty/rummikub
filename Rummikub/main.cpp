#include <iostream>
#include "plateau.h"

using namespace std;

int main()
{
    plateau * p = new plateau;
    p->afficher();
    p->enAttente();
    p->afficher();
    return 0;
}
