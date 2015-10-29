#ifndef FACTORY_H
#define FACTORY_H

#include "tuile.h"

class factory
{
    public:
        factory();
        virtual tuile *createTuile(string, int, int, string) = 0;
    protected:
    private:
};

#endif // FACTORY_H
