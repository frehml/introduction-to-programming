
#ifndef HUISTAAK8_GHOST_H
#define HUISTAAK8_GHOST_H

#include "Personage.h"
#include <string>
using namespace std;

class Ghost : public Personage{
public:
    Ghost(Vak* vak);
    string toString();
};


#endif //HUISTAAK8_GHOST_H
