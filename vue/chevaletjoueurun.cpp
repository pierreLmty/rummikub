#include "chevaletjoueurun.h"
#include <QPushButton>

using namespace std;

chevaletJoueurUn::chevaletJoueurUn(){}

QLayout *chevaletJoueurUn::utiliserChevalet(){

    this->setColumnMinimumWidth(12, 0);
    QPushButton * button1 = new QPushButton;
    QPushButton * button2 = new QPushButton;
    QPushButton * button3 = new QPushButton;
    QPushButton * button4 = new QPushButton;

    button1->setIcon(QIcon("image/2.png"));
    button1->setFixedSize(40,60);
    button1->setIconSize(QSize(40,60));

    button2->setIcon(QIcon("image/2.png"));
    button2->setFixedSize(40,60);
    button2->setIconSize(QSize(40,60));

    button3->setIcon(QIcon("image/2.png"));
    button3->setFixedSize(40,60);
    button3->setIconSize(QSize(40,60));

    button4->setIcon(QIcon("image/2.png"));
    button4->setFixedSize(40,60);
    button4->setIconSize(QSize(40,60));

    this->addWidget(button1);
    this->addWidget(button2);
    this->addWidget(button3);
    this->addWidget(button4);
    return this;
}
