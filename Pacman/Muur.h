
#ifndef HUISTAAK8_MUUR_H
#define HUISTAAK8_MUUR_H
#include "Vak.h"
#include <string>
using namespace std;

class Muur : public Vak{
public:
    Muur(int x, int y);
    bool isBegaanbaar();
    bool isVrij();
    string toString();
};


#endif //HUISTAAK8_MUUR_H
