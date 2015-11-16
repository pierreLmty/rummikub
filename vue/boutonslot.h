#ifndef BOUTONSLOT_H
#define BOUTONSLOT_H

#include <QObject>
#include <QWidget>

class boutonSlot : public QObject
{
    Q_OBJECT
public:
    boutonSlot();
public slots:
    void creerBouton();
};

#endif // BOUTONSLOT_H
