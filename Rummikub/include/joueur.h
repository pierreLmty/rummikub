#ifndef JOUEUR_H
#define JOUEUR_H
#include <vector>

using namespace std;

class joueur
{
    public:
        joueur();
        bool getFirstMain();
        void setFirstMain(bool);
        int getId();
        vector<int> getChevalet();
        void retirerTuile(int);
    private:
        bool firstMain_;
        int id_;
        vector<int> chevalet_;
};

#endif // JOUEUR_H
