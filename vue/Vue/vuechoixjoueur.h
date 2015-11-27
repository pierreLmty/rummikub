#ifndef VUECHOIXJOUEUR_H
#define VUECHOIXJOUEUR_H

#include <QObject>
#include <QApplication>
#include <QWidget>
#include <QLayout>
#include <QPushButton>
#include <QIcon>
#include "vue.h"
#include "choixchevalet.h"
#include "chevaletjoueurun.h"
#include "chevaletjoueurdeux.h"
#include "Modele/plateau.h"
#include "boutonslot.h"
#include "Modele/pioche.h"
#include "Vue/fenetre.h"

class vueChoixJoueur : public vue
{
    Q_OBJECT
    public:
        vueChoixJoueur(plateau *, QWidget *, QString);
        void setChevalet(choixChevalet *);
        void afficher();

    signals:
        void changeInterface(QString name);

    public slots:
        void nbJoueur2();
        void nbJoueur3();
        void nbJoueur4();
    private:
        QWidget * fenetre_;
        plateau * plateau_;
        QVBoxLayout * layout_;
        QPushButton * nbJoueurDeux_;
        QPushButton * nbJoueurTrois_;
        QPushButton * nbJoueurQuatre_;
};

#endif // VUECHOIXJOUEUR_H
