#include "verification.h"
#include <iostream>
#include <vector>

using namespace std;

verification::verification(plateau * p)
{
    plateau_ = p;
}

void verification::faireVerif(){
    vector<tuile *> tab = plateau_->getList();
    bool verif = false;
    bool boolProbCouleurSuite = false;
    bool boolProbNumeroSuite = false;
    bool boolProbCouleurBC = false;
    bool boolProbNumeroBC = false;
    bool boolVerifSuite = false;
    bool boolVerifBC = false;
    boolProbCouleurSuite = problemeCouleurSuite(tab);
    boolProbNumeroSuite = problemeNumeroSuite(tab);
    boolProbCouleurBC = problemeCouleurBC(tab);
    boolProbNumeroBC = problemeNumeroBC(tab);
    cout << "prob c suite : " << boolProbCouleurSuite << endl;
    cout << "prob N suite : " << boolProbNumeroSuite << endl;
    cout << "prob c BC : " << boolProbCouleurBC << endl;
    cout << "prob N BC : " << boolProbNumeroBC << endl;
    boolVerifSuite = verifSuite(tab, boolProbCouleurSuite, boolProbNumeroSuite);
    boolVerifBC = verifBC(tab, boolProbCouleurBC, boolProbNumeroBC);
    cout << "prob s : " << boolVerifSuite << endl;
    cout << "prob bc : " << boolVerifBC << endl;

    if(boolVerifBC || boolVerifSuite){
        verif = true;
    }
    cout << "verification : " << verif << endl;
    if(verif){
        plateau_->setState(plateau_->getStateValide());
        plateau_->afficher();
    }
    else{
        cout << "Liste non valide" << endl;
        plateau_->setState(plateau_->getStateAttente());
    }
}

bool verification::longueurMin(vector<tuile *> listAVerif){
    bool minOk = true;
    if(listAVerif.size() < 3){
        minOk = false;
    }
    return minOk;
}

bool verification::longueurMax(vector<tuile *> listAVerif){
    bool maxOk = true;
    if(listAVerif.size() > 13){
        maxOk = false;
    }
    return maxOk;
}

bool verification::longueurMaxBC(vector<tuile *> listAVerif){
    bool maxBCOK = true;
    if(listAVerif.size() > 4){
        maxBCOK = false;
    }
    return maxBCOK;
}

bool verification::problemeCouleurSuite(vector<tuile *> listAVerif){
    bool probCouleur = false;
    for(unsigned int i = 0; i < listAVerif.size(); ++i){
        if(listAVerif.at(i)->getValeur() != 30){
            //mettre les conditions correspondant au couleur lorsque les tuiles seront utilisable
           // probCouleur = true;
        }
        if(listAVerif.at(i)->getValeur() == 30 && i != 0 && i != listAVerif.size()-1){
            //idem qu'au dessus
            //probCouleur = true;
        }
    }
    return probCouleur;
}

bool verification::problemeNumeroSuite(vector<tuile *> listAVerif){
    bool probNumero = false;
    if(listAVerif.front()->getValeur() == 30 && listAVerif.at(1)->getValeur() == 1){
        probNumero = true;
    }
    //peut etre ajouter une boucle -1
    for(unsigned int i = 0; i < listAVerif.size(); ++i){
        if(listAVerif.at(i)->getValeur() == 13 && i != listAVerif.size()-1){
            probNumero = true;
        }
    }
    for(unsigned int i = 0; i < listAVerif.size()-1; ++i){
        if(listAVerif.at(i)->getValeur() != 30){
            if(listAVerif.at(i)->getValeur() != listAVerif.at(i+1)->getValeur()-1 && listAVerif.at(i+1)->getValeur() != 30){
                probNumero = true;
            }
        }
        if(listAVerif.at(i)->getValeur() == 30){
            if(listAVerif.at(i-1)->getValeur() != listAVerif.at(i+1)->getValeur()-2 && listAVerif.at(i+1)->getValeur() != 30 && i!=0 && listAVerif.at(i-1)->getValeur() != 30){
                probNumero = true;
            }
        }
        if(listAVerif.at(i)->getValeur() == 30 && listAVerif.at(i+1)->getValeur() == 30 && i+1 != listAVerif.size()-1){
            if(listAVerif.at(i-1)->getValeur() !=  listAVerif.at(i+2)->getValeur()-3 && i != 0){
                probNumero = true;
            }
        }
        if(listAVerif.at(i)->getValeur() == 30  && listAVerif.at(i+1)->getValeur() == 30 && i == 0 && listAVerif.size() > 3){
            if(listAVerif.at(i+2)->getValeur() != listAVerif.at(i+3)->getValeur()-1 || listAVerif.at(2)->getValeur() == 1 || listAVerif.at(2)->getValeur() == 2){
                probNumero = true;
            }
        }
    }
    return probNumero;
}

bool verification::problemeCouleurBC(vector<tuile *> listAVerif){
    //mettre en place cette fonction lorsque la tuile seront prete
    return false;
}

bool verification::problemeNumeroBC(vector<tuile *> listAVerif){
    bool probNumero = false;
    //ICI la boucle est peut a mettre a -1
    for(unsigned int i = 0; i < listAVerif.size()-1; ++i){
        if(listAVerif.at(i)->getValeur() != 30){
            if(listAVerif.at(i)->getValeur() != listAVerif.at(i+1)->getValeur() && listAVerif.at(i+1)->getValeur() != 30){
                probNumero = true;
            }
        }
        if(listAVerif.at(i)->getValeur() == 30){
            if(listAVerif.at(i-1)->getValeur() != listAVerif.at(i+1)->getValeur() && listAVerif.at(i+1)->getValeur() != 30 && listAVerif.at(i-1)->getValeur() != 30){
                probNumero = true;
            }
        }
        if(listAVerif.at(i)->getValeur() == 30 && listAVerif.at(i+1)->getValeur() == 30 && i != 0 && listAVerif.size() > 3 && i != listAVerif.size()-2){
            if(listAVerif.at(i-1)->getValeur() != listAVerif.at(i+2)->getValeur()){
                probNumero = true;
            }
        }
    }
    return probNumero;
}

bool verification::verifSuite(vector<tuile *> listAVerif, bool boolProbCouleurSuite, bool boolProbNumeroSuite){
    bool verifSuiteOk = true;
    if(!longueurMin(listAVerif) || !longueurMax(listAVerif)){
        verifSuiteOk = false;
    }
    if(boolProbCouleurSuite || boolProbNumeroSuite){
        verifSuiteOk = false;
    }
    return verifSuiteOk;
}

bool verification::verifBC(vector<tuile *> listAVerif, bool boolProbCouleurBC, bool boolProbNumeroBC){
    bool verifBCOK = true;
    if(!longueurMin(listAVerif) || !longueurMaxBC(listAVerif)){
        verifBCOK = false;
    }
    if(boolProbCouleurBC || boolProbNumeroBC){
        verifBCOK = false;
    }
    return verifBCOK;
}

bool verification::firstMain(vector<tuile *> listAVerif, bool boolVerifSuiteOk, bool boolVerifBCOK){
    bool firstMainOK = true;
    int cptJoker = 0;
    for(unsigned int joker = 0; joker < listAVerif.size(); ++joker){
        if(listAVerif.at(joker)->getValeur() == 30){
            cptJoker += 1;
        }
    }
    if(cptJoker != 0){
        firstMainOK = false;
    }
    if(!boolVerifBCOK && !boolVerifSuiteOk){
        firstMainOK = false;
    }
    else{
        //mettre le firstmain du joueur a faux
    }
    return firstMainOK;
}

void verification::afficher(){
    cout << "Verification en cours" << endl;
}
