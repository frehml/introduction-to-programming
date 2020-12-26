//
// Created by Frederic on 06/12/2020.
//
#include "Vak.h"
#ifndef HUISTAAK8_PERSONAGE_H
#define HUISTAAK8_PERSONAGE_H

#include <string>
using namespace std;

class Personage{
public:
    Vak* vak;

    Personage(Vak* v);

    Vak* getVak();

    bool botstMet(Personage* p);

    int volgende_rij_positie(char richting);

    int volgende_kolom_positie(char richting);

    void verplaats(Vak* nieuw_vak);

    string toString();
};
#endif //HUISTAAK8_PERSONAGE_H
