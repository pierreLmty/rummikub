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
    vector<int> tab = plateau_->getList();
    vector<vector<int> > mat = plateau_->getPlateau();
    for(unsigned int i = 0; i<mat.size(); ++i){
        for(unsigned int j =0; j<mat.size(); ++j){
            if(!tab.empty()){
                if(mat[i][0] == 0){
                    plateau_->setPlateau(tab.back(), i, j);
                    tab.pop_back();
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
