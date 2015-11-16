#include <QApplication>
#include "vueprincipale.h"
#include "chevaletjoueurun.h"
#include "chevaletjoueurdeux.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  choixChevalet * choix = new chevaletJoueurUn;
  vue * vu = new vuePrincipale(choix);
  vu->afficher();
 /* choix = new chevaletJoueurDeux;
  vu->setChevalet(choix);
  vu->afficher();*/
 /* choix = new chevaletJoueurUn;
  vu->setChevalet(choix);
  vu->afficher();*/
  vu->show();
  return app.exec();
}
