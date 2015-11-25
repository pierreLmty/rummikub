#ifndef BOUTONSLOT_H
#define BOUTONSLOT_H

#include <QObject>
#include <QWidget>
#include "Modele/plateau.h"
#include "Modele/chevalet.h"

class boutonSlot : public QObject
{
    Q_OBJECT
    public:
        boutonSlot();
        boutonSlot(plateau *);
    public slots:
        void creerBoutonChevalet(QString);
        void creerBoutonPlateau(QString);
    private:
        plateau * plateau_;
};

#endif // BOUTONSLOT_H
