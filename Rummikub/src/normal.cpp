#include <string>
#include "normal.h"

using namespace std;

normal::normal(int id, int valeur, string couleur, int emplacement) : id_(id), valeur_(valeur), couleur_(couleur), emplacement_(emplacement) {}

int normal :: getId()
{
    return id_;
}

int normal :: getValeur()
{
    return valeur_;
}

string normal :: getCouleur()
{
    return couleur_;
}

int normal :: getEmplacement()
{
    return emplacement_;
}

void normal :: setEmplacement(int e)
{
    emplacement_ = e;
}
