#ifndef TUILE_H
#define TUILE_H
#include <string>

using namespace std;

class tuile
{
    public:
        tuile();
        virtual string getCouleur() = 0;
        virtual int getValeur() = 0;
        virtual int getId() = 0;
        virtual int getEmplacement() = 0;
        virtual void setEmplacement(int) = 0;
    protected:
    private:
        int emplacement_;//0 : pioche, 1 : chevalet, 2 : plateau
};

#endif // TUILE_H
