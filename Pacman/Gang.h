//
// Created by Frederic Hamelink on 06/12/2020.
//

#ifndef HUISTAAK8_GANG_H
#define HUISTAAK8_GANG_H
#include "Personage.h"
#include "Vak.h"
#include <string>
using namespace std;

class Gang : public Vak{
public:
    Personage* personage;
    bool heeft_voedsel;
    Gang(int x, int y);
    bool isBegaanbaar();
    bool isVrij();
    void plaats_personage(Personage* p);
    void verwijder_personage(Personage* p);
    bool heeftVoedsel();
    void eetVoedsel();
    string toString();
};


#endif //HUISTAAK8_GANG_H
