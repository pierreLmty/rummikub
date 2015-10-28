#include "tuileFactory.h"


using namespace std;

tuileFactory::tuileFactory(){}

tuile *tuileFactory::createTuile(string type, int id, int valeur, string couleur)
{
    if(type == "normal")
    {
        tuile_ = new normal(id, valeur, couleur);
        return tuile_;
    }
    else if(type == "joker")
    {
        tuile_ = new joker(id, valeur, couleur);
        return tuile_;
    }
}
