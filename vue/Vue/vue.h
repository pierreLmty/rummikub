#ifndef VUE_H
#define VUE_H

#include <QObject>
#include <QWidget>
#include "choixchevalet.h"

class vue : public QWidget
{
    public:
        vue();
        virtual void setChevalet(choixChevalet *) = 0;
        virtual void afficher() = 0;
    protected:
        choixChevalet * chevalet_;
};

#endif // VUE_H
