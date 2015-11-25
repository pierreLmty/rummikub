/**
* \file verification.cpp
* \author Lemétayer Pierre - Mael Quemard
* \version 1.0
* \date 16 Novembre 2015
* \brief Définit l'état de vérification du plateau, fait suite à l'état d'attente
*/

#include "Modele/verification.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
* \brief Constructeur de la classe verification.cpp
* \param p le nouvel objet à instancier
*/
verification::verification(plateau * p)
{
    plateau_ = p;
}

/**
* \fn void faireVerif()
* \brief Lance la série de vérifications à effectuer sur les listes envoyées par le joueur
*/
void verification::faireVerif(){
    vector<tuile *> tab = plateau_->getList();
    bool verif = false;
    bool boolProbCouleurSuite = false;
    bool boolProbNumeroSuite = false;
    bool boolProbCouleurBC = false;
    bool boolProbNumeroBC = false;
    bool boolVerifSuite = false;
    bool boolVerifBC = false;
    if(!tab.empty()){
        for(int i = 0; i < tab.size(); ++i){
            if(tab[i] != NULL)
                cout << tab[i]->getCouleur() << " " << tab[i]->getValeur();
        }
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
}
    if((!plateau_->getJoueur()->getFirstMain()) && boolVerifBC || boolVerifSuite){
        verif = true;
    }
    if(plateau_->getJoueur()->getFirstMain()){
        bool firstMainOK = firstMain(tab, boolVerifSuite, boolVerifBC);
        if(firstMainOK){
            verif = true;
        }
        else{
            cout << "Vous êtes à votre premier tour, il vous faut donc 30 points pour lancer la partie : ";
        }
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

/**
* \fn bool longueurMin(vector<tuile *> listAVerif)
* \brief Vérifie si la liste envoyée est au moins de longueur 3
* \param listAVerif La liste de tuile à vérifier
* \return Retourne Vrai si la longueur est supérieure à 3 sinon faux
*/
bool verification::longueurMin(vector<tuile *> listAVerif){
    bool minOk = true;
    if(listAVerif.size() < 3){
        minOk = false;
    }
    return minOk;
}

/**
* \fn bool longueurMax(vector<tuile *> listAVerif)
* \brief Vérifie si la liste envoyée est inférieure à 13
* \param listAVerif La liste de tuile à vérifier
* \return Retourne Vrai si la longueur est inférieure à 13 sinon faux
*/
bool verification::longueurMax(vector<tuile *> listAVerif){
    bool maxOk = true;
    if(listAVerif.size() > 13){
        maxOk = false;
    }
    return maxOk;
}

/**
* \fn bool longueurMaxBC(vector<tuile *> listAVerif)
* \brief Vérifie si la liste envoyée est inférieure à 4 dans le cas où le joueur envoie une liste de brelan ou de carré
* \param listAVerif La liste de tuile à vérifier
* \return Retourne Vrai si la longueur est inférieure à 4 sinon faux
*/
bool verification::longueurMaxBC(vector<tuile *> listAVerif){
    bool maxBCOK = true;
    if(listAVerif.size() > 4){
        maxBCOK = false;
    }
    return maxBCOK;
}

/**
* \fn bool problemeCouleurSuite(vector<tuile *> listAVerif)
* \brief Vérifie si la liste envoyée ne contient pas de problemes de couleur. Cette fonction concernera les listes qui seront composées de suite de numéro d'une même couleur. Elle parcourt la liste et selon la présence ou non de joker, verifie si les tuiles avant et après sont valides par rapport à la tuile en cours de traitement.
* \param listAVerif La liste de tuile à vérifier
* \return Retourne Vrai s'il n'y a pas de problème sinon Faux
*/
bool verification::problemeCouleurSuite(vector<tuile *> listAVerif){
    bool probCouleur = false;
    for(unsigned int i = 0; i < listAVerif.size()-1; ++i){
        if(listAVerif.at(i)->getValeur() != 30){
            if(listAVerif.at(i)->getCouleur() != listAVerif.at(i+1)->getCouleur() && listAVerif.at(i+1)->getValeur() != 30){
                probCouleur = true;
            }
        }
        if(listAVerif.at(i)->getValeur() == 30 && i != 0 && i != listAVerif.size()-1){
            if(listAVerif.at(i-1)->getCouleur() != listAVerif.at(i+1)->getCouleur() && listAVerif.at(i+1)->getValeur() != 30 && listAVerif.at(i-1)->getValeur() != 30){
                probCouleur = true;
            }
        }
    }
    return probCouleur;
}

/**
* \fn bool problemeNumeroSuite(vector<tuile *> listAVerif)
* \brief Vérifie si la liste envoyée ne contient pas de problemes de numéro. Cette fonction concernera les listes qui seront composées de suite de numéro d'une même couleur. Elle parcourt la liste et selon la présence ou non de joker, verifie si les tuiles avant et après sont valides par rapport à la tuile en cours de traitement.
* \param listAVerif La liste de tuile à vérifier
* \return Retourne Vrai s'il n'y a pas de problème sinon Faux
*/
bool verification::problemeNumeroSuite(vector<tuile *> listAVerif){
    bool probNumero = false;
    if(listAVerif.front()->getValeur() == 30 && listAVerif.at(1)->getValeur() == 1){
        probNumero = true;
    }
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

/**
* \fn bool problemeCouleurBC(vector<tuile *> listAVerif)
* \brief Vérifie si la liste envoyée ne contient pas de problemes de couleur. Cette fonction concernera les listes qui seront composées de suite de même numéro et de couleurs differentes. Elle parcourt la liste et selon la présence ou non de joker, verifie si les tuiles avant et après sont valides par rapport à la tuile en cours de traitement.
* \param listAVerif La liste de tuile à vérifier
* \return Retourne Vrai s'il n'y a pas de problème sinon Faux
*/
bool verification::problemeCouleurBC(vector<tuile *> listAVerif){
    bool probCouleur = false;
    vector<string> listCouleur;
    for(unsigned int i = 0; i < listAVerif.size()-1; ++i){
        vector<string>::iterator it = find(listCouleur.begin(), listCouleur.end(), listAVerif.at(i)->getCouleur());
        if(it == listCouleur.end() && listAVerif.at(i)->getValeur() != 30){
            listCouleur.push_back(listAVerif.at(i)->getCouleur());
        }
        else if(it != listCouleur.end() && listAVerif.at(i)->getValeur() != 30){
            probCouleur = true;
        }
    }

    for(unsigned int i = 0; i < listAVerif.size()-1; ++i){
        if(listAVerif.at(i)->getValeur() != 30){
            if(listAVerif.at(i)->getCouleur() == listAVerif.at(i+1)->getCouleur() && listAVerif.at(i+1)->getValeur() != 30){
                probCouleur = true;
            }
        }
        if(listAVerif.at(i)->getValeur() == 30){
            if(listAVerif.at(i-1)->getCouleur() == listAVerif.at(i+1)->getCouleur() && listAVerif.at(i+1)->getValeur() != 30 && listAVerif.at(i-1)->getValeur() != 30){
                probCouleur = true;
            }
        }
        if(listAVerif.at(i)->getValeur() == 30 && listAVerif.at(i+1)->getValeur() == 30 && i+1 != listAVerif.size()-1){
            if(listAVerif.at(i-1)->getCouleur() == listAVerif.at(i+2)->getCouleur() && i != 0){
                probCouleur = true;
            }
        }
    }
    return probCouleur;
}

/**
* \fn bool problemeNumeroBC(vector<tuile *> listAVerif)
* \brief Vérifie si la liste envoyée ne contient pas de problemes de numéro. Cette fonction concernera les listes qui seront composees de suite de meme numero et de couleurs differentes. Elle parcourt la liste et selon la présence ou non de joker, verifie si les tuiles avant et après sont valides par rapport à la tuile en cours de traitement.
* \param listAVerif La liste de tuile à vérifier
* \return Retourne Vrai s'il n'y a pas de problème sinon Faux
*/
bool verification::problemeNumeroBC(vector<tuile *> listAVerif){
    bool probNumero = false;
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

/**
* \fn bool verifSuite(vector<tuile *> listAVerif, bool boolProbCouleurSuite, bool boolProbNumeroSuite)
* \brief Rassemble les resultats des fonctions problemeCouleurSuite(), problemeNumeroSuite(), longueurMin() et longueurMax() pour renvoyer un booleen verifSuiteOK à Vrai ou à Faux. La fonction va vérifier que la liste est de bonne longueur (longueur minimale et maximale) en appelant les fonctions longueurMin() et longueurMax(). Elle va aussi vérifier que la composition des listes est bonne grace aux résultats des fonctions problemeCouleurSuite() et problemeNumeroSuite()
* \param listAVerif La liste de tuile à vérifier
* \param boolProbCouleurSuite Indique si il y a des problèmes de couleurs dans la liste de type suite
* \param boolProbNumeroSuite Indique si il y a des problèmes de numéros dans la liste de type suite
* \return Retourne Vrai s'il n'y a pas de problème sinon Faux
*/
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

/**
* \fn bool verifBC(vector<tuile *> listAVerif, bool boolProbCouleurBC, bool boolProbNumeroBC)
* \brief Rassemble les résultats des fonctions problemeCouleurBC(), problemeNumeroBC(), longueurMin() et longueurMaxBC() pour renvoyer un booleen verifBCOK à Vrai ou à Faux. La fonction va vérifier que la liste est de bonne longueur (longueur minimale et maximale) en appelant les fonctions longueurMin() et longueurMaxBC(). Elle va aussi vérifier que la composition des listes est bonne grace aux résultats des fonctions problemeCouleurBC() et problemeNumeroBC()
* \param listAVerif La liste de tuile à vérifier
* \param boolProbCouleurBC Indique si il y a des problèmes de couleurs dans la liste de type BC
* \param boolProbNumeroBC Indique si il y a des problèmes de numéros dans la liste de type BC
* \return Retourne Vrai s'il n'y a pas de problème sinon Faux
*/
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

/**
* \fn bool firstMain(vector<tuile *> listAVerif, bool boolVerifSuiteOk, bool boolVerifBCOK)
* \brief Intervient seulement lors du premier tour d'un joueur. Compte le nombre de joker et utilise les résultats des booleens boolVerifSuiteOK et boolVerifBCOK pour renvoyer un booleen firstMainOK à Vrai ou à Faux.
* \param listAVerif La liste de tuile à vérifier
* \param boolVerifSuiteOk Indique si la liste de type suite est valide ou non
* \param boolVerifBCOK Indique si la liste de type BC est valide ou non
* \return Retourne Vrai s'il n'y a pas de problème sinon Faux
*/
bool verification::firstMain(vector<tuile *> listAVerif, bool boolVerifSuiteOk, bool boolVerifBCOK){
    bool firstMainOK = true;
    int cptJoker = 0;
    int scoreList = 0;
    for(unsigned int joker = 0; joker < listAVerif.size(); ++joker){
        if(listAVerif.at(joker)->getValeur() == 30){
            cptJoker += 1;
        }
        scoreList += listAVerif[joker]->getValeur();
    }
    cout << "score de la liste : " << scoreList << endl;
    if(cptJoker != 0){
        firstMainOK = false;
    }
    if(!boolVerifBCOK && !boolVerifSuiteOk){
        firstMainOK = false;
    }
    if(plateau_->getJoueur()->getFirstMain() && scoreList < 30){
        firstMainOK = false;
    }
    else{
        plateau_->getJoueur()->setFirstMain(false);
    }
    return firstMainOK;
}

/**
* \fn void afficher()
* \brief Fonction à destination du joueur pour lui indiquer que la liste envoyée est en cours de vérification
*/
void verification::afficher(){
    cout << "Verification en cours" << endl;
}
