/**
* \file factory.cpp
* \author Lemétayer Pierre - Mael Quemard
* \version 1.0
* \date 16 Novembre 2015
* \brief Classe abstraite qui définit les différentes factory
*/

#include "Modele/factory.h"
#include <iostream>

using namespace std;

factory::factory(){}

/**
* \fn tuile * createTuile(string type, int id, int valeur, string couleur)
* \brief Créée des objets de type normal ou joker en fonction des paramètres rentrés
* \param type le type de l'objet (normal ou joker)
* \param id l'id de l'objet
* \param valeur la valeur de l'objet
* \param couleur la couleur de l'objet (noir ou rouge)
*/
tuile *createTuile(string type, int id, int valeur, string couleur){}
