#include <string>
#include "Tuile.h"
#include "Normal.h"

using namespace std;

Normal :: Normal(int id, int valeur, string couleur) : id_(id), valeur_(valeur), couleur_(couleur) {}

int Normal :: getId()
{
    return id_;
}

int Normal :: getValeur()
{
    return valeur_;
}

string Normal :: getCouleur()
{
    return couleur_;
}
