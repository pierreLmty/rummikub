#ifndef TUILEFACTORY_H
#define TUILEFACTORY_H

#include "factory.h"
#include "tuile.h"
#include "normal.h"
#include "joker.h"

using namespace std;

class tuileFactory : public factory
{
    public:
	    /**
* \brief Constructeur de la classe tuileFactory.cpp
*/
        tuileFactory();
	/**
* \fn tuile * createTuile(string type, int id, int valeur, string couleur)
* \brief Créée des objets de type normal ou joker en fonction des paramètres rentrés
* \param type le type de l'objet (normal ou joker)
* \param id l'id de l'objet
* \param valeur la valeur de l'objet
* \param couleur la couleur de l'objet (noir ou rouge)
* \param Retourne un objet de type normal si le paramètre "type" était "normal" sinon retourne un objet de type joker
*/
        tuile *createTuile(string, int, int, string);
    protected:
    private:
        tuile *tuile_;
};

#endif // TUILEFACTORY_H
