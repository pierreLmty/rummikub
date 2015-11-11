#include "tuileFactory.h"
#include "normal.h"


using namespace std;

tuileFactory::tuileFactory()
{

}

tuile *tuileFactory::createTuile(string type, int id, int valeur, string couleur)
{
    if(type == "normal")
    {
        tuile_ = new normal(id, valeur, couleur, 0);
    }
    else if(type == "joker")
    {
        tuile_ = new joker(id, 30, couleur, 0);
    }

    return tuile_;
}
