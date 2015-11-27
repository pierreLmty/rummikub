#include <QApplication>
#include "Vue/vueprincipale.h"
#include "Vue/vuechoixjoueur.h"
#include "Vue/chevaletjoueurun.h"
#include "Vue/chevaletjoueurdeux.h"
#include "Modele/plateau.h"
#include "Modele/pioche.h"
#include "Vue/boutonslot.h"
#include <iostream>
#include "Vue/fenetre.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  fenetre * fenetre_ = new fenetre();
  fenetre_->show();
  return app.exec();
}
