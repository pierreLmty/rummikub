#ifndef FACTORY_H
#define FACTORY_H

#include "tuile.h"

class factory
{
    public:
        factory();
	/**
	* \fn tuile * createTuile(string type, int id, int valeur, string couleur)
	* \brief Créée des objets de type normal ou joker en fonction des paramètres rentrés
	* \param type le type de l'objet (normal ou joker)
	* \param id l'id de l'objet
	* \param valeur la valeur de l'objet
	* \param couleur la couleur de l'objet (noir ou rouge)
	*/
        virtual tuile *createTuile(string, int, int, string) = 0;
    protected:
    private:
};

#endif // FACTORY_H
