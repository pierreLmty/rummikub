#ifndef CHOIXCHEVALET_H
#define CHOIXCHEVALET_H

#include <QObject>
#include <QWidget>
#include <QLayout>

class choixChevalet : public QGridLayout
{
public:
    choixChevalet();
    virtual QLayout *utiliserChevalet() = 0;
};

#endif // CHOIXCHEVALET_H
