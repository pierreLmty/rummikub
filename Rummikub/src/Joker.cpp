#include <string>
#include "Tuile.h"
#include "Joker.h"

using namespace std;

Joker :: Joker(int id, int valeur, string couleur) : id_(id), valeur_(30), couleur_(couleur) {}

int Joker :: getId()
{
    return id_;
}

int Joker :: getValeur()
{
    return valeur_;
}

string Joker :: getCouleur()
{
    return couleur_;
}
