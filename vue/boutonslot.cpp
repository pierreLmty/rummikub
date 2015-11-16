#include "boutonslot.h"
#include <QPushButton>

boutonSlot::boutonSlot()
{

}

void boutonSlot::creerBouton(){
    QPushButton * b = new QPushButton;
    b->show();
}
