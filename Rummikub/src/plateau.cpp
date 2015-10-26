#include "plateau.h"
#include "attente.h"
#include "verification.h"

using namespace std;

plateau::plateau()
{
    etatCourant_ = new attente(this);
    etatAttente_ = new attente(this);
    etatVerification_ = new verification(this);
}

etat *plateau::getState(){
    return etatAttente_;
}

void plateau::setState(etat * etat){
    etatCourant_ = etat;
}

etat *plateau::getStateVerif()
{
    return etatVerification_;
}

void plateau::afficher(){
    etatCourant_->afficher();
}

void plateau::enAttente()
{
    etatCourant_->enAttente();
}

void plateau::faireVerif()
{
    etatCourant_->faireVerif();
}
