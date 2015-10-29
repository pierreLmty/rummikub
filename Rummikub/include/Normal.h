#ifndef NORMAL_H
#define NORMAL_H

using namespace std;

class Normal : public Tuile
{
    public:
        Normal(int, int, string);
        virtual ~Normal();
        int getId();
        int getValeur();
        string getCouleur();
    protected:
    private:
        int id_;
        int valeur_;
        string couleur_;
};

#endif // NORMAL_H
