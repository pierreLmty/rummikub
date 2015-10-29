#include "valide.h"
#include <iostream>
#include "plateau.h"
#include <vector>

using namespace std;

valide::valide(plateau * p)
{
    plateau_ = p;
}

void valide::valider(){
    vector<tuile *> tab = plateau_->getList();
    vector<vector<tuile *> > mat = plateau_->getPlateau();
    for(unsigned int i = 0; i<mat.size(); ++i){
        for(unsigned int j =0; j<mat.size(); ++j){
            if(!tab.empty()){
                if(mat[i][0] == 0){
                    plateau_->setPlateau(tab.front(), i, j);
                    tab.erase(tab.begin());
                }
            }
        }
    }
    plateau_->setState(plateau_->getStateAttente());
    plateau_->afficher();
}

void valide::afficher(){
    cout << "Valider";
}
