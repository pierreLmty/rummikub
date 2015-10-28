#include <iostream>
#include "plateau.h"

using namespace std;

int main()
{
    plateau * p = new plateau;
    while(1){
        p->enAttente();
        p->faireVerif();
        p->valider();
    }
    return 0;
}
