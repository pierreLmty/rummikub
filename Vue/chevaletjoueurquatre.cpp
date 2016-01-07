/**
* \file chevaletjoueurquatre.cpp
* \author Lemétayer Pierre - Maël Quémard
* \version 1.0
* \date 27 Novembre 2015
* \brief Classe qui définit le layout du joueur 4
*/

#include "Vue/chevaletjoueurquatre.h"
#include <QPushButton>
#include <QSettings>
#include <QSignalMapper>
#include <QMessageBox>
#include <typeinfo>

using namespace std;

chevaletJoueurQuatre::chevaletJoueurQuatre(joueur * j, boutonSlot * buttonS){
    joueur_ = j;
    bu = buttonS;
}

/**
* \fn QLayout utiliserChevalet()
* \brief Créer le layout du joueur 4
* \return Un layout qui contient un chevalet
*/
QLayout *chevaletJoueurQuatre::utiliserChevalet(){
    this->setColumnMinimumWidth(12, 0);
    QSignalMapper *signalMapper = new QSignalMapper(bu);
    QObject::connect(signalMapper, SIGNAL(mapped(QString)), bu, SLOT(creerBoutonChevalet(QString)));
    vector<tuile *> chevalet = joueur_->getChevalet()->getChevalet();
    for(unsigned int i = 0; i < chevalet.size(); ++i){
            QPushButton *button = new QPushButton;
            QString val;
            val = QString::number(chevalet[i]->getValeur());
            QString couleur;
            couleur = QString::fromStdString(chevalet[i]->getCouleur());
            button->setIcon(QIcon("image/"+val+"_"+couleur+".png"));
            button->setFixedSize(45,45);
            button->setIconSize(QSize(45,45));
            if(i < 14){
                this->addWidget(button,0,i);
            }
            else if(i < 28){
                this->addWidget(button, 1, i-14);
            }
            else if(i < 42){
                this->addWidget(button, 2, i-28);
            }
            else if(i < 56){
                this->addWidget(button, 3, i-42);
            }
            //Mappage, puis connexion du signal au mapper
            signalMapper->setMapping(button, "image/"+val+"_"+couleur+".png");
            QObject::connect(button, SIGNAL(clicked()), signalMapper, SLOT(map()));
    }
    return this;
}
