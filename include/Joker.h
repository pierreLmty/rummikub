#ifndef JOKER_H
#define JOKER_H

using namespace std;

class Joker : public Tuile
{
    public:
        Joker(int, int, string);
        virtual ~Joker();
        int getId();
        int getValeur();
        string getCouleur();
    protected:
    private:
        int id_;
        int valeur_;
        string couleur_;
};

#endif // JOKER_H
