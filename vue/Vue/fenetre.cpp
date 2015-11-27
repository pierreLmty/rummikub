#include "fenetre.h"
#include <QMessageBox>
#include <iostream>

using namespace std;


fenetre::fenetre() :
vuePrincipale_(NULL),vueChoixJoueur_(NULL)
{
    vector<joueur *> listejoueurTemp;
    plateau_ = new plateau(listejoueurTemp);
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
    joueurUn_ = new joueur(1);
    joueurDeux_ = new joueur(2);

    //ajout des joueurs dans la liste
    listeJoueur_.push_back(joueurUn_);
    listeJoueur_.push_back(joueurDeux_);

    plateau_->setListeJoueur(listeJoueur_);

    //Définition du joueur 1 pour commencer la partie
    plateau_->setJoueur(joueurUn_);

    //Distribution des tuiles
    pioche_->distribuer(listeJoueur_);

    //Création des vues pour chaque chevalet
    choixChevaletJoueurUn_ = new chevaletJoueurUn(joueurUn_, boutonSlot_);
    choixChevaletJoueurDeux_ = new chevaletJoueurDeux(joueurDeux_, boutonSlot_);

    listeChevalet_.push_back(choixChevaletJoueurUn_);
    listeChevalet_.push_back(choixChevaletJoueurDeux_);

    //Mise en place du chevalet à afficher, initialiser comme pour le plateau sur le joueur 1
    vuePrincipale_->setChevalet(choixChevaletJoueurUn_);

    main();
}

void fenetre::nbJoueur3(){
    //Création des joueurs
    joueurUn_ = new joueur(1);
    joueurDeux_ = new joueur(2);
    joueurTrois_ = new joueur(3);

    //ajout des joueurs dans la liste
    listeJoueur_.push_back(joueurUn_);
    listeJoueur_.push_back(joueurDeux_);
    listeJoueur_.push_back(joueurTrois_);

    plateau_->setListeJoueur(listeJoueur_);

    //Définition du joueur 1 pour commencer la partie
    plateau_->setJoueur(joueurUn_);

    //Distribution des tuiles
    pioche_->distribuer(listeJoueur_);

    //Création des vues pour chaque chevalet
    choixChevaletJoueurUn_ = new chevaletJoueurUn(joueurUn_, boutonSlot_);
    choixChevaletJoueurDeux_ = new chevaletJoueurDeux(joueurDeux_, boutonSlot_);
    choixChevaletJoueurTrois_ = new chevaletJoueurTrois(joueurTrois_, boutonSlot_);

    listeChevalet_.push_back(choixChevaletJoueurUn_);
    listeChevalet_.push_back(choixChevaletJoueurDeux_);
    listeChevalet_.push_back(choixChevaletJoueurTrois_);

    //Mise en place du chevalet à afficher, initialiser comme pour le plateau sur le joueur 1
    vuePrincipale_->setChevalet(choixChevaletJoueurUn_);

    main();

}

void fenetre::nbJoueur4(){
    //Création des joueurs
    joueurUn_ = new joueur(1);
    joueurDeux_ = new joueur(2);
    joueurTrois_ = new joueur(3);
    joueurQuatre_ = new joueur(4);

    //ajout des joueurs dans la liste
    listeJoueur_.push_back(joueurUn_);
    listeJoueur_.push_back(joueurDeux_);
    listeJoueur_.push_back(joueurTrois_);
    listeJoueur_.push_back(joueurQuatre_);

    plateau_->setListeJoueur(listeJoueur_);

    //Définition du joueur 1 pour commencer la partie
    plateau_->setJoueur(joueurUn_);

    //Distribution des tuiles
    pioche_->distribuer(listeJoueur_);

    //Création des vues pour chaque chevalet
    choixChevaletJoueurUn_ = new chevaletJoueurUn(joueurUn_, boutonSlot_);
    choixChevaletJoueurDeux_ = new chevaletJoueurDeux(joueurDeux_, boutonSlot_);
    choixChevaletJoueurTrois_ = new chevaletJoueurTrois(joueurTrois_, boutonSlot_);
    choixChevaletJoueurQuatre_ = new chevaletJoueurQuatre(joueurQuatre_, boutonSlot_);

    listeChevalet_.push_back(choixChevaletJoueurUn_);
    listeChevalet_.push_back(choixChevaletJoueurDeux_);
    listeChevalet_.push_back(choixChevaletJoueurTrois_);
    listeChevalet_.push_back(choixChevaletJoueurQuatre_);

    qobject_cast<vuePrincipale *>(vuePrincipale_)->setListeChevalet(listeChevalet_);

    //Mise en place du chevalet à afficher, initialiser comme pour le plateau sur le joueur 1
    vuePrincipale_->setChevalet(choixChevaletJoueurUn_);

    main();
}

void fenetre::main(){
    chevalet * chevaletTmp;
    joueur * joueurGagnant;
    bool finPartie = false;
    int score = 0;
    unsigned int aQuiLeTour = 0;

    do{
        for(unsigned int i = 0; i < listeJoueur_.size(); ++i){
            cout << "for" << endl;
            if(plateau_->getJoueur() == listeJoueur_[i]){
                cout << "if" << endl;
                vuePrincipale_->setChevalet(listeChevalet_[i]);
                vuePrincipale_->afficher();
            }
        }
        if(listeJoueur_[aQuiLeTour]->getChevalet()->getTaille() == 0){
            joueurGagnant = listeJoueur_[aQuiLeTour];
        }

        cout << "aqui le tour  :"  << aQuiLeTour << endl;
        ++aQuiLeTour;
        cout << "aqui le tour  :"  << aQuiLeTour << endl;
        if(aQuiLeTour == listeJoueur_.size()-1){
            aQuiLeTour = 0;
        }
   }while(joueurGagnant == NULL);

    //Instructions de comptage de point
    for(unsigned int l = 0; l != listeJoueur_.size();++l)
    {
        if(listeJoueur_[l] != joueurGagnant){
            chevaletTmp = listeJoueur_[l]->getChevalet();

            for(unsigned int i = 0; i < chevaletTmp->getTaille(); ++i){
                score = chevaletTmp->getUneTuile(i)->getValeur();
            }
        }
    }

    if(joueurGagnant != NULL){
        joueurGagnant->setScore(score);
        score = 0;
        joueurGagnant = NULL;
    }
}
