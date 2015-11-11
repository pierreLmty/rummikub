#include <string>
#include "joker.h"

using namespace std;

joker::joker(int id, int valeur, string couleur, int emplacement) : id_(id), valeur_(30), couleur_(couleur), emplacement_(emplacement) {}

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

void joker::setValeur(int valeur)
{
    valeur_ = valeur;
}

int joker :: getEmplacement()
{
    return emplacement_;
}

void joker :: setEmplacement(int e)
{
    emplacement_ = e;
}

string joker::toString()
{
    cout << id_ << " " << valeur_ << " " << couleur_ << " " << emplacement_ << endl;
}
