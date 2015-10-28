#include <string>
#include "joker.h"

using namespace std;

joker::joker(int id, int valeur, string couleur) : id_(id), valeur_(30), couleur_(couleur) {}

int joker :: getId()
{
    return id_;
}

int joker :: getValeur()
{
    return valeur_;
}

string joker :: getCouleur()
{
    return couleur_;
}
