//
// Created by Frederic Hamelink on 06/12/2020.
//

#ifndef HUISTAAK8_SUPERGHOST_H
#define HUISTAAK8_SUPERGHOST_H
#include "Ghost.h"
#include "Personage.h"


class SuperGhost : public Ghost{
public:
    SuperGhost(Vak* vak);

    char toString();

    int volgende_rij_positie(char richting);

    int volgende_kolom_positie(char richting);
};


#endif //HUISTAAK8_SUPERGHOST_H
