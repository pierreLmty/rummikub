#include "vuechoixjoueur.h"
#include <QLabel>

using namespace std;


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

void vueChoixJoueur::setChevalet(choixChevalet *){}

void vueChoixJoueur::afficher(){}

void vueChoixJoueur::nbJoueur2(){
    qobject_cast<fenetre *>(fenetre_)->changerFenetre("vuePrincipale");
    qobject_cast<fenetre *>(fenetre_)->nbJoueur2();
}

void vueChoixJoueur::nbJoueur3(){
    qobject_cast<fenetre *>(fenetre_)->changerFenetre("vuePrincipale");
    qobject_cast<fenetre *>(fenetre_)->nbJoueur3();
}

void vueChoixJoueur::nbJoueur4(){
    qobject_cast<fenetre *>(fenetre_)->changerFenetre("vuePrincipale");
    qobject_cast<fenetre *>(fenetre_)->nbJoueur4();
}
