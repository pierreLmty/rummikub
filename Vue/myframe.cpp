/**
* \file myframe.cpp
* \author Lemétayer Pierre - Maël Quémard
* \version 1.0
* \date 27 Novembre 2015
* \brief Classe qui définit les différents éléments de la fenêtre
*/

#include "Vue/myframe.h"
#include <QLayout>
#include <QPushButton>
#include <QLabel>
#include <QIcon>
#include <QPixmap>
#include <QGraphicsEffect>

myFrame::myFrame()
{
    QVBoxLayout * layoutPrincipale = new QVBoxLayout;

    QHBoxLayout * layout_dessous = new QHBoxLayout;

    QGridLayout * layout_ = new QGridLayout;
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


    QGridLayout * layoutchevalet_ = new QGridLayout;
    layoutchevalet_->setColumnMinimumWidth(12, 0);
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

    layoutchevalet_->addWidget(button1);
    layoutchevalet_->addWidget(button2);
    layoutchevalet_->addWidget(button3);
    layoutchevalet_->addWidget(button4);

    QVBoxLayout * layoutInfo_ = new QVBoxLayout;
    QPushButton * pioche_ = new QPushButton("Pioche");
    QPushButton * verifier_ = new QPushButton("Verifier");
    pioche_->setFixedSize(65,35);
    verifier_->setFixedSize(65,35);
    layoutInfo_->addWidget(pioche_);
    layoutInfo_->addWidget(verifier_);

    layoutPrincipale->addLayout(layout_);
    layoutPrincipale->addLayout(layout_dessous);
    layout_dessous->addLayout(layoutchevalet_);
    layout_dessous->addLayout(layoutInfo_);
    this->setLayout(layoutPrincipale);
 }

