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
    protected:
    private:
};

#endif // TUILE_H
