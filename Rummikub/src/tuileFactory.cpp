/**
* \file tuileFactory.cpp
* \author Lemétayer Pierre - Mael Quemard
* \version 1.0
* \date 16 Novembre 2015
* \brief Factory qui créée des objets de type normal ou tuile héritant de la classe factory.cpp
* \see factory.cpp
*/

#include "tuileFactory.h"
#include "normal.h"


using namespace std;

/**
* \brief Constructeur de la classe tuileFactory.cpp
*/
tuileFactory::tuileFactory(){}

/**
* \fn tuile * createTuile(string type, int id, int valeur, string couleur)
* \brief Créée des objets de type normal ou joker en fonction des paramètres rentrés
* \param type le type de l'objet (normal ou joker)
* \param id l'id de l'objet
* \param valeur la valeur de l'objet
* \param couleur la couleur de l'objet (noir ou rouge)
* \param Retourne un objet de type normal si le paramètre "type" était "normal" sinon retourne un objet de type joker
*/
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
