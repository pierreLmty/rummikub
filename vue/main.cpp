#include <QApplication>
#include "Vue/vueprincipale.h"
#include "Vue/chevaletjoueurun.h"
#include "Vue/chevaletjoueurdeux.h"
#include "Modele/plateau.h"
#include "Modele/pioche.h"
#include "Vue/boutonslot.h"
#include <iostream>

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  plateau * p = new plateau;

  joueur * j1 = new joueur;
  joueur * j2 = new joueur;
  vector<joueur *> listeJoueur;
  listeJoueur.push_back(j1);
  listeJoueur.push_back(j2);
  p->setJoueur(j1);

  pioche * pioch = new pioche;
  pioch->createPioche();
  pioch->distribuer(listeJoueur);

  boutonSlot * boutonS = new boutonSlot(p);
  choixChevalet * choix = new chevaletJoueurUn(j1, boutonS);
  vuePrincipale * vu = new vuePrincipale(choix, p, pioch, boutonS);
  vu->afficher();
  vu->show();
 /*choix = new chevaletJoueurDeux;
  vu->setChevalet(choix);
  vu->afficher();*/
 /* choix = new chevaletJoueurUn;
  vu->setChevalet(choix);
  vu->afficher();*/

  return app.exec();
}
