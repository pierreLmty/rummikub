/**
* \file vuechoixjoueur.cpp
* \author Lemétayer Pierre - Maël Quémard
* \version 1.0
* \date 27 Novembre 2015
* \brief 
*/

#include "vuechoixjoueur.h"
#include <QLabel>

using namespace std;

/**
* \brief Construit la vue de la fenêtre de sélection des joueurs
* \param p le plateau
* \param f la fenetre
* \param name le nom de la vue
*/
vueChoixJoueur::vueChoixJoueur(plateau * p, QWidget * f, QString name)
{
    fenetre_ = f;
    plateau_ = p;
    layout_ = new QVBoxLayout;
    nbJoueurDeux_ = new QPushButton("2 Joueurs");
    nbJoueurTrois_ = new QPushButton("3 Joueurs");
    nbJoueurQuatre_ = new QPushButton("4 Joueurs");
    QLabel * l = new QLabel("Veuillez choisir le nombre de joueur");

    nbJoueurDeux_->setFixedSize(120,35);
    nbJoueurTrois_->setFixedSize(120,35);
    nbJoueurQuatre_->setFixedSize(120,35);

    layout_->addWidget(l);
    layout_->addWidget(nbJoueurDeux_);
    layout_->addWidget(nbJoueurTrois_);
    layout_->addWidget(nbJoueurQuatre_);
    layout_->setAlignment(l, Qt::AlignCenter);
    layout_->setAlignment(nbJoueurDeux_ , Qt::AlignCenter);
    layout_->setAlignment(nbJoueurTrois_ , Qt::AlignCenter);
    layout_->setAlignment(nbJoueurQuatre_ , Qt::AlignCenter);
    QObject::connect(nbJoueurDeux_, SIGNAL(clicked()), this, SLOT(nbJoueur2()));
    QObject::connect(nbJoueurTrois_, SIGNAL(clicked()), this, SLOT(nbJoueur3()));
    QObject::connect(nbJoueurQuatre_, SIGNAL(clicked()), this, SLOT(nbJoueur4()));

    this->setLayout(layout_);
    this->setObjectName(name);
    connect(this,SIGNAL(changeInterface(QString)),qobject_cast<fenetre *>(f),SLOT(changerFenetre(QString)));
}

/**
* \fn void setChevalet(choixChevalet * chevalet)
* \brief Définit le chevalet à chaque changement de joueur
* \param chevalet le nouveau chevalet
*/
void vueChoixJoueur::setChevalet(choixChevalet *){}

/**
* \fn void afficher()
* \brief Affiche le chevalet du joueur courant
*/
void vueChoixJoueur::afficher(){}

/**
* \fn void nbJoueur2()
* \brief Lance le programme avec 2 joueurs
*/
void vueChoixJoueur::nbJoueur2(){
    qobject_cast<fenetre *>(fenetre_)->changerFenetre("vuePrincipale");
    qobject_cast<fenetre *>(fenetre_)->nbJoueur2();
}

/**
* \fn void nbJoueur3()
* \brief Lance le programme avec 3 joueurs
*/
void vueChoixJoueur::nbJoueur3(){
    qobject_cast<fenetre *>(fenetre_)->changerFenetre("vuePrincipale");
    qobject_cast<fenetre *>(fenetre_)->nbJoueur3();
}

/**
* \fn void nbJoueur4()
* \brief Lance le programme avec 4 joueurs
*/
void vueChoixJoueur::nbJoueur4(){
    qobject_cast<fenetre *>(fenetre_)->changerFenetre("vuePrincipale");
    qobject_cast<fenetre *>(fenetre_)->nbJoueur4();
}
