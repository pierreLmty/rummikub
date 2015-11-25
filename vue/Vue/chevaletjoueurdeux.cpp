#include "Vue/chevaletjoueurdeux.h"
#include <QPushButton>
#include <QSettings>
#include <QSignalMapper>
#include <QMessageBox>
#include "Vue/boutonslot.h"

using namespace std;

chevaletJoueurDeux::chevaletJoueurDeux(joueur * j){
    joueur_ = j;
}

QLayout *chevaletJoueurDeux::utiliserChevalet(){

    this->setColumnMinimumWidth(12, 0);
    QSettings iniFile("chevalet2.ini", QSettings::IniFormat);
    iniFile.beginGroup("Buttons");

    boutonSlot * b = new boutonSlot;
    //Déclaration du mapper, qu'on connecte au slot
    QSignalMapper *signalMapper = new QSignalMapper(b);
    QObject::connect(signalMapper, SIGNAL(mapped(QString)), b, SLOT(creerBouton(QString)));

    //Lecture d'un tableau de clés
    foreach(QString key, iniFile.childKeys()) {
        //Récupération du nom du bouton
        QString buttonName(iniFile.value(key,"").toString());
        QPushButton *button = new QPushButton;
        button->setIcon(QIcon("image/"+buttonName+".png"));
        button->setFixedSize(65,65);
        button->setIconSize(QSize(65,65));
        //button->setText(buttonName);
        this->addWidget(button);

        //Mappage, puis connexion du signal au mapper
        signalMapper->setMapping(button, buttonName);
        QObject::connect(button, SIGNAL(clicked()), signalMapper, SLOT(map()));
    }
    iniFile.endGroup();
    return this;
    /*
    this->setColumnMinimumWidth(12, 0);
    QPushButton * button1 = new QPushButton;
    QPushButton * button2 = new QPushButton;
    QPushButton * button3 = new QPushButton;

    button1->setIcon(QIcon("image/2.png"));
    button1->setFixedSize(40,60);
    button1->setIconSize(QSize(40,60));

    button2->setIcon(QIcon("image/2.png"));
    button2->setFixedSize(40,60);
    button2->setIconSize(QSize(40,60));

    button3->setIcon(QIcon("image/2.png"));
    button3->setFixedSize(40,60);
    button3->setIconSize(QSize(40,60));

    this->addWidget(button1);
    this->addWidget(button2);
    this->addWidget(button3);
    return this;*/
}
