#include "chevaletjoueurdeux.h"
#include <QPushButton>

using namespace std;

chevaletJoueurDeux::chevaletJoueurDeux(){}

QLayout *chevaletJoueurDeux::utiliserChevalet(){

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
    return this;
}
