#ifndef CHOIXCHEVALET_H
#define CHOIXCHEVALET_H

#include <QObject>
#include <QWidget>
#include <QLayout>
#include "Modele/joueur.h"

class choixChevalet : public QGridLayout
{
public:
    choixChevalet();
    /**
* \fn QLayout utiliserChevalet()
* \brief Créer le layout d'un joueur du jeu
* \return Un layout qui contient un chevalet
*/
    virtual QLayout *utiliserChevalet() = 0;

};

#endif // CHOIXCHEVALET_H
