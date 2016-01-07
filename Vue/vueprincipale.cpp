/**
* \file vueprincipale.cpp
* \author Lemétayer Pierre - Maël Quémard
* \version 1.0
* \date 27 Novembre 2015
* \brief 
*/

#include "Vue/vueprincipale.h"
#include <vector>
#include <QSignalMapper>
#include "Modele/tuile.h"
#include <sstream>
#include <iostream>

using namespace std;

/**
* \brief Construit la vue de la fenre de sélection des joueurs
* \param p le plateau
* \param laPioche le pioche du jeu
* \param b un bouton
* \param f la fenetre
* \param name le nom de la vue
*/
vuePrincipale::vuePrincipale(plateau * p, pioche * laPioche, boutonSlot * b, QWidget * f, QString name)
{
    //Variables
    plateau_ = p;
    layoutPrincipale_ = new QVBoxLayout;
    layoutDessous_ = new QHBoxLayout;
    layout_ = new QGridLayout;
    layoutInfo_ = new QVBoxLayout;
    pioche_ = new QPushButton("piocher");
    verifier_ = new QPushButton("verifier");
    trier_ = new QPushButton("Trier chevalet par couleur");
    chevaletWidget_ = new QWidget;
    pioch = laPioche;
    boutonSlot_ = b;
    hud = new QLabel;

    //Taille du plateau graphique
    layout_->setRowMinimumHeight(12, 0);
    layout_->setColumnMinimumWidth(12, 0);

    for(unsigned int i = 0; i < 13; ++i){
        for(unsigned int j = 0; j < 13; ++j){
            QPushButton * boutonNull = new QPushButton;
            boutonNull->setDisabled(true);
            boutonNull->setFixedSize(35,35);
            layout_->addWidget(boutonNull, i, j);
        }
    }

    pioche_->setFixedSize(120,35);
    verifier_->setFixedSize(120,35);
    trier_->setFixedSize(120,35);

    //Ajout des différents layouts et boutons
    layoutInfo_->addWidget(pioche_);
    layoutInfo_->addWidget(verifier_);
    layoutInfo_->addWidget(trier_);
    layoutPrincipale_->addWidget(hud);
    layoutPrincipale_->addLayout(layout_);
    layoutPrincipale_->addLayout(layoutDessous_);
    layoutDessous_->addWidget(chevaletWidget_);
    layoutDessous_->addLayout(layoutInfo_);

    //Ajout du layout principale à la fenêtre
    this->setLayout(layoutPrincipale_);
    QObject::connect(pioche_, SIGNAL(clicked()), this, SLOT(piocher()));
    QObject::connect(verifier_, SIGNAL(clicked()), this, SLOT(verifier()));
    QObject::connect(trier_, SIGNAL(clicked()), this, SLOT(trier()));
   // plateau_->enAttente();
    this->setObjectName(name);
    connect(this,SIGNAL(changeInterface(QString)),qobject_cast<fenetre *>(f),SLOT(changerFenetre(QString)));
}

/**
* \fn void utiliserPlateau()
* \brief Permet à l'utilisateur d'utiliser les tuiles qui sont sur le plateau pour former sa liste de tuile
*/
void vuePrincipale::utiliserPlateau(){
    //Signal mapper qui va trouver de quel bouton vient l'evenement
    QSignalMapper *signalMapper = new QSignalMapper(boutonSlot_);
    QObject::connect(signalMapper, SIGNAL(mapped(QString)), boutonSlot_, SLOT(creerBoutonPlateau(QString)));
    vector<vector<tuile *> > mat = plateau_->getPlateau();
    for(unsigned int i = 0; i < mat.size(); ++i){
        for(unsigned int j = 0; j < mat[i].size(); ++j){
            if(mat[i][j] != NULL){
            QPushButton *button = new QPushButton;
            QString val;
            val = QString::number(mat[i][j]->getValeur());
            QString couleur;
            couleur = QString::fromStdString(mat[i][j]->getCouleur());
            button->setIcon(QIcon("image/"+val+"_"+couleur+".png"));
            button->setFixedSize(35,35);
            button->setIconSize(QSize(35,35));
            layout_->addWidget(button, i, j);

            //Mappage, puis connexion du signal au mapper
            signalMapper->setMapping(button, "image/"+val+"_"+couleur+".png");
            QObject::connect(button, SIGNAL(clicked()), signalMapper, SLOT(map()));
            }
            else{
                QPushButton * boutonNull = new QPushButton;
                boutonNull->setDisabled(true);
                boutonNull->setFixedSize(35,35);
                layout_->addWidget(boutonNull, i, j);
            }
        }
    }
}


/**
* \fn void piocher()
* \brief Appelle la méthode piocher de la pioche et place la tuile piochée dans le chevalet du joueur courant
*/
void vuePrincipale::piocher(){
    plateau_->getJoueur()->setChevalet(pioch->piocher());
    vector<joueur *> listeTMP = plateau_->getListeJoueur();
    bool passer = false;
    for(unsigned int i = 0; i < listeTMP.size(); ++i){
        if(listeTMP.size() == 2){
            if(listeTMP[i]->getId() == plateau_->getJoueur()->getId() && !passer){
                if(i == 0){
                    this->setChevalet(new chevaletJoueurDeux(listeTMP[i+1], boutonSlot_));
                    plateau_->setJoueur(listeTMP[i+1]);
                    passer = true;
                }
                else if(i == 1){
                    this->setChevalet(new chevaletJoueurUn(listeTMP[0], boutonSlot_));
                    plateau_->setJoueur(listeTMP[0]);
                    passer = true;
                }
            }
        }
        if(listeTMP.size() == 3){
            if(listeTMP[i]->getId() == plateau_->getJoueur()->getId() && !passer){
                if(i == 0){
                    this->setChevalet(new chevaletJoueurDeux(listeTMP[i+1], boutonSlot_));
                    plateau_->setJoueur(listeTMP[i+1]);
                    passer = true;
                }
                else if(i == 1){
                    this->setChevalet(new chevaletJoueurTrois(listeTMP[i+1], boutonSlot_));
                    plateau_->setJoueur(listeTMP[i+1]);
                    passer = true;
                }
                else if(i == 2){
                    this->setChevalet(new chevaletJoueurUn(listeTMP[0], boutonSlot_));
                    plateau_->setJoueur(listeTMP[0]);
                    passer = true;
                }
            }
        }
        if(listeTMP.size() == 4){
            if(listeTMP[i]->getId() == plateau_->getJoueur()->getId() && !passer){
                if(i == 0){
                    this->setChevalet(new chevaletJoueurDeux(listeTMP[i+1], boutonSlot_));
                    plateau_->setJoueur(listeTMP[i+1]);
                    passer = true;
                }
                else if(i == 1){
                    this->setChevalet(new chevaletJoueurTrois(listeTMP[i+1], boutonSlot_));
                    plateau_->setJoueur(listeTMP[i+1]);
                    passer = true;
                }
                else if(i == 2){
                    this->setChevalet(new chevaletJoueurQuatre(listeTMP[i+1], boutonSlot_));
                    plateau_->setJoueur(listeTMP[i+1]);
                    passer = true;
                }
                else if(i == 4){
                    this->setChevalet(new chevaletJoueurUn(listeTMP[0], boutonSlot_));
                    plateau_->setJoueur(listeTMP[0]);
                    passer = true;
                }
            }
        }
    }
    passer = false;
    updateChevalet();
    afficher();
}


//Passe dans les différents états du pattern state
//Remet a jour le plateau et le chevalet
/**
* \fn void verifier()
* \brief Passe dans les différents états du pattern State et met à jour le plateau et le chevalet du joueur courant dans le cas d'une pioche ou d'une pose
*/
void vuePrincipale::verifier(){
    plateau_->enAttente();
    plateau_->faireVerif();
    plateau_->valider();
    vector<joueur *> listeTMP = plateau_->getListeJoueur();
    for(unsigned int i = 0; i < listeTMP.size(); ++i){
        if(listeTMP.size() == 2){
            cout << "2 j" << endl;
            if(listeTMP[i]->getId() == plateau_->getJoueur()->getId() && i != listeTMP.size()-1){
                if(i == 0){
                    this->setChevalet(new chevaletJoueurDeux(listeTMP[i+1], boutonSlot_));
                }
                if(i == 1){
                    this->setChevalet(new chevaletJoueurUn(listeTMP[0], boutonSlot_));
                }
            }
        }
        if(listeTMP.size() == 3){
            cout << "3 j" << endl;
            if(listeTMP[i]->getId() == plateau_->getJoueur()->getId() && i != listeTMP.size()-1){
                if(i == 0)
                    this->setChevalet(new chevaletJoueurDeux(listeTMP[i+1], boutonSlot_));
                if(i == 1)
                    this->setChevalet(new chevaletJoueurTrois(listeTMP[i+1], boutonSlot_));
                if(i == 2)
                    this->setChevalet(new chevaletJoueurUn(listeTMP[0], boutonSlot_));
            }
        }
        if(listeTMP.size() == 4){
            cout << "4 j" << endl;
            if(listeTMP[i]->getId() == plateau_->getJoueur()->getId() && i != listeTMP.size()-1){
                if(i == 0)
                    this->setChevalet(new chevaletJoueurDeux(listeTMP[i+1], boutonSlot_));
                if(i == 1)
                    this->setChevalet(new chevaletJoueurTrois(listeTMP[i+1], boutonSlot_));
                if(i == 2)
                    this->setChevalet(new chevaletJoueurQuatre(listeTMP[i+1], boutonSlot_));
                if(i == 4)
                    this->setChevalet(new chevaletJoueurUn(listeTMP[0], boutonSlot_));
            }
        }
    }
    updateChevalet();
    updatePlateau();
    afficher();

}

/**
* \fn void trier()
* \brief Appelle la fonction de triage du chevalet
*/
void vuePrincipale::trier(){
    plateau_->getJoueur()->getChevalet()->trierChevalet();
    updateChevalet();
}

/**
* \fn void updateChevalet()
* \brief Met à jour le chevalet du joueur courant dans le cas d'une pioche ou d'une pose
*/
void vuePrincipale::updateChevalet(){
    //Vide le layout des widgets
    QLayoutItem *item;
    while ((item = chevalet_->takeAt(0)) != 0) {
        item->widget()->deleteLater();
        delete item;
    }
    //Appelle la fonction du chevalet pour récupérer les nouvelles tuiles
    chevalet_->utiliserChevalet();
}

/**
* \fn void updatePlateau()
* \brief Met à jour le plateau après une pose de tuile
*/
void vuePrincipale::updatePlateau(){
    //Vide le layout des widgets
    QLayoutItem *item;
    while ((item = layout_->takeAt(0)) != 0) {
        item->widget()->deleteLater();
        delete item;
    }
    utiliserPlateau();
}

/**
* \fn void setChevalet(choixChevalet * chevalet)
* \brief Définit le chevalet à chaque changement de joueur
* \param chevalet le nouveau chevalet
*/
void vuePrincipale::setChevalet(choixChevalet * chevalet){
   chevaletWidget_->setVisible(false);
   if(chevalet_ != NULL){
       QLayoutItem *item;
       while ((item = chevalet_->takeAt(0)) != 0) {
           item->widget()->hide();
       }
   }
   delete chevaletWidget_->layout();
   chevalet_ = chevalet;
   hud->setText("C'est au joueur : "+QString::number(plateau_->getJoueur()->getId())
                +" score : "+QString::number(plateau_->getJoueur()->getScore()));
}

/**
* \fn void afficher()
* \brief Affiche le chevalet du joueur courant
*/
void vuePrincipale::afficher(){
    chevaletWidget_->setLayout(chevalet_->utiliserChevalet());
    chevaletWidget_->setVisible(true);
}

/**
* \fn void setListeChevalet()
* \brief Définit la liste des chevalets
* \param l Un objet chevalet
*/
void vuePrincipale::setListeChevalet(vector<choixChevalet *> l){
    listeChevalet_ = l;
}
