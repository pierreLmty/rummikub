#ifndef TUILE_H
#define TUILE_H
#include <string>

using namespace std;

class Tuile
{
    public:
        virtual string getCouleur();
        virtual int getValeur();
        virtual int getId();
    protected:
    private:
};

#endif // TUILE_H
