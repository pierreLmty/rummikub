#ifndef FENETRE_H
#define FENETRE_H

#include <QObject>
#include <QWidget>
#include <QStackedWidget>
#include "vue.h"
#include "vueprincipale.h"
#include "vuechoixjoueur.h"
#include "Modele/plateau.h"
#include "boutonslot.h"
#include "Modele/pioche.h"
#include "choixchevalet.h"
#include "chevaletjoueurun.h"
#include "chevaletjoueurdeux.h"
#include "chevaletjoueurtrois.h"
#include "chevaletjoueurquatre.h"
#include <vector>

class fenetre : public QStackedWidget
{
    Q_OBJECT
    public:
        fenetre();
        void nbJoueur2();
        void nbJoueur3();
        void nbJoueur4();
        void main();
    public slots:
        void changerFenetre(QString name);

    private:
        vue * vuePrincipale_;
        vue * vueChoixJoueur_;
        plateau * plateau_;
        boutonSlot * boutonSlot_;
        pioche * pioche_;
        choixChevalet * choixChevaletJoueurUn_;
        choixChevalet * choixChevaletJoueurDeux_;
        choixChevalet * choixChevaletJoueurTrois_;
        choixChevalet * choixChevaletJoueurQuatre_;
        joueur * joueurUn_;
        joueur * joueurDeux_;
        joueur * joueurTrois_;
        joueur * joueurQuatre_;
        vector<joueur *> listeJoueur_;
        vector<choixChevalet *> listeChevalet_;
};

#endif // FENETRE_H
