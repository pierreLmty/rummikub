#include "vueprincipale.h"
#include "boutonslot.h"

using namespace std;

vuePrincipale::vuePrincipale(choixChevalet * chevalet)
{
    chevalet_ = chevalet;
    layoutPrincipale_ = new QVBoxLayout;
    layoutDessous_ = new QHBoxLayout;
    layout_ = new QGridLayout;
    layoutInfo_ = new QVBoxLayout;
    pioche_ = new QPushButton("piocher");
    verifier_ = new QPushButton("verifier");
    chevaletWidget_ = new QWidget;

    layout_->setRowMinimumHeight(12, 0);
    layout_->setColumnMinimumWidth(12, 0);
    QPushButton * tuile1 = new QPushButton;
    QPushButton * tuile2 = new QPushButton;
    QPushButton * tuile3 = new QPushButton;
    QPushButton * tuile4 = new QPushButton;
    QPushButton * tuile5 = new QPushButton;
    QPushButton * tuile6 = new QPushButton;
    QPushButton * tuile7 = new QPushButton;
    tuile1->setIcon(QIcon("image/test.png"));
    tuile1->setFixedSize(65,65);
    tuile1->setIconSize(QSize(65,65));

    tuile2->setIcon(QIcon("image/test.png"));
    tuile2->setFixedSize(65,65);
    tuile2->setIconSize(QSize(65,65));

    tuile3->setIcon(QIcon("image/test.png"));
    tuile3->setFixedSize(65,65);
    tuile3->setIconSize(QSize(65,65));

    tuile4->setIcon(QIcon("image/test.png"));
    tuile4->setFixedSize(65,65);
    tuile4->setIconSize(QSize(65,65));

    tuile5->setIcon(QIcon("image/test.png"));
    tuile5->setFixedSize(65,65);
    tuile5->setIconSize(QSize(65,65));

    tuile6->setIcon(QIcon("image/test.png"));
    tuile6->setFixedSize(65,65);
    tuile6->setIconSize(QSize(65,65));

    tuile7->setIcon(QIcon("image/test.png"));
    tuile7->setFixedSize(65,65);
    tuile7->setIconSize(QSize(65,65));

    layout_->addWidget(tuile1);
    layout_->addWidget(tuile2);
    layout_->addWidget(tuile3);
    layout_->addWidget(tuile4);
    layout_->addWidget(tuile5);
    layout_->addWidget(tuile6);
    layout_->addWidget(tuile7);

    pioche_->setFixedSize(65,35);
    verifier_->setFixedSize(65,35);
    layoutInfo_->addWidget(pioche_);
    layoutInfo_->addWidget(verifier_);

    layoutPrincipale_->addLayout(layout_);
    layoutPrincipale_->addLayout(layoutDessous_);
    layoutDessous_->addWidget(chevaletWidget_);
    layoutDessous_->addLayout(layoutInfo_);
    this->setLayout(layoutPrincipale_);
    boutonSlot * b = new boutonSlot;
    QObject::connect(pioche_, SIGNAL(clicked()), b, SLOT(creerBouton()));
}

void vuePrincipale::setChevalet(choixChevalet * chevalet){
   chevaletWidget_->setVisible(false);
   delete chevaletWidget_->layout();
   chevalet_ = chevalet;
}

void vuePrincipale::afficher(){
    chevaletWidget_->setLayout(chevalet_->utiliserChevalet());
    chevaletWidget_->setVisible(true);
}
