

#ifndef HUISTAAK8_PACMAN_H
#define HUISTAAK8_PACMAN_H

#include "Personage.h"
#include <string>
using namespace std;

class Pacman : public Personage{
public:
    Pacman(Vak* vak);

    string toString();
};


#endif //HUISTAAK8_PACMAN_H
