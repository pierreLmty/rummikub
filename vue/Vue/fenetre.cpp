#include "fenetre.h"
#include <QMessageBox>

using namespace std;


fenetre::fenetre() :
vuePrincipale_(NULL),vueChoixJoueur_(NULL)
{
    plateau_ = new plateau;
    boutonSlot_ = new boutonSlot(plateau_);
    pioche_ = new pioche;
    pioche_->createPioche();

    vuePrincipale_ = new vuePrincipale(plateau_, pioche_, boutonSlot_, this, "vuePrincipale");
    this->addWidget(vuePrincipale_);
    vueChoixJoueur_ = new vueChoixJoueur(plateau_, this, "vueChoixJoueur");
    this->addWidget(vueChoixJoueur_);
    this->setCurrentWidget(vueChoixJoueur_);

    /*choix = new chevaletJoueurDeux;
     vu->setChevalet(choix);
     vu->afficher();*/
    /* choix = new chevaletJoueurUn;
     vu->setChevalet(choix);
     vu->afficher();*/

}

void fenetre::changerFenetre(QString name){
    if((name == vuePrincipale_->objectName())&&vuePrincipale_)
    {
        this->setCurrentWidget(vuePrincipale_);
        return;
    }
    else if((name == vueChoixJoueur_->objectName())&&vueChoixJoueur_)
    {
        this->setCurrentWidget(vueChoixJoueur_);
        return;
    }
    else
    {
        QMessageBox::information(0,tr("Erreur changement onglet"),tr("Impossible de changer l'interface pour l'onglet ")+name+tr(".\nCet onglet n'existe plus ou n'a pas été créer."));
    }
}


void fenetre::nbJoueur2(){
    //Création des joueurs
    joueurUn_ = new joueur;
    joueurDeux_ = new joueur;

    //ajout des joueurs dans la liste
    listeJoueur_.push_back(joueurUn_);
    listeJoueur_.push_back(joueurDeux_);

    //Définition du joueur 1 pour commencer la partie
    plateau_->setJoueur(joueurUn_);

    //Distribution des tuiles
    pioche_->distribuer(listeJoueur_);

    //Création des vues pour chaque chevalet
    choixChevaletJoueurUn_ = new chevaletJoueurUn(joueurUn_, boutonSlot_);
    choixChevaletJoueurDeux_ = new chevaletJoueurDeux(joueurDeux_, boutonSlot_);

    //Mise en place du chevalet à afficher, initialiser comme pour le plateau sur le joueur 1
    vuePrincipale_->setChevalet(choixChevaletJoueurUn_);

    //Affichage de la vue du jeu
    vuePrincipale_->afficher();
}

void fenetre::nbJoueur3(){
    //Création des joueurs
    joueurUn_ = new joueur;
    joueurDeux_ = new joueur;
    joueurTrois_ = new joueur;

    //ajout des joueurs dans la liste
    listeJoueur_.push_back(joueurUn_);
    listeJoueur_.push_back(joueurDeux_);
    listeJoueur_.push_back(joueurTrois_);

    //Définition du joueur 1 pour commencer la partie
    plateau_->setJoueur(joueurUn_);

    //Distribution des tuiles
    pioche_->distribuer(listeJoueur_);

    //Création des vues pour chaque chevalet
    choixChevaletJoueurUn_ = new chevaletJoueurUn(joueurUn_, boutonSlot_);
    choixChevaletJoueurDeux_ = new chevaletJoueurDeux(joueurDeux_, boutonSlot_);
    choixChevaletJoueurTrois_ = new chevaletJoueurUn(joueurTrois_, boutonSlot_);

    //Mise en place du chevalet à afficher, initialiser comme pour le plateau sur le joueur 1
    vuePrincipale_->setChevalet(choixChevaletJoueurUn_);

    //Affichage de la vue du jeu
    vuePrincipale_->afficher();
}

void fenetre::nbJoueur4(){
    //Création des joueurs
    joueurUn_ = new joueur;
    joueurDeux_ = new joueur;
    joueurTrois_ = new joueur;
    joueurQuatre_ = new joueur;

    //ajout des joueurs dans la liste
    listeJoueur_.push_back(joueurUn_);
    listeJoueur_.push_back(joueurDeux_);
    listeJoueur_.push_back(joueurTrois_);
    listeJoueur_.push_back(joueurQuatre_);

    //Définition du joueur 1 pour commencer la partie
    plateau_->setJoueur(joueurUn_);

    //Distribution des tuiles
    pioche_->distribuer(listeJoueur_);

    //Création des vues pour chaque chevalet
    choixChevaletJoueurUn_ = new chevaletJoueurUn(joueurUn_, boutonSlot_);
    choixChevaletJoueurDeux_ = new chevaletJoueurDeux(joueurDeux_, boutonSlot_);
    choixChevaletJoueurTrois_ = new chevaletJoueurUn(joueurTrois_, boutonSlot_);
    choixChevaletJoueurQuatre_ = new chevaletJoueurDeux(joueurQuatre_, boutonSlot_);

    //Mise en place du chevalet à afficher, initialiser comme pour le plateau sur le joueur 1
    vuePrincipale_->setChevalet(choixChevaletJoueurUn_);

    //Affichage de la vue du jeu
    vuePrincipale_->afficher();
}
