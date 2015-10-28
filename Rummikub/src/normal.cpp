#include <string>
#include "normal.h"

using namespace std;

normal::normal(int id, int valeur, string couleur) : id_(id), valeur_(valeur), couleur_(couleur) {}

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
