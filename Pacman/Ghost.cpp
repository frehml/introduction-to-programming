//
// Created by Frederic Hamelink on 06/12/2020.
//

#include "Ghost.h"
#include "Pacman.h"
#include <string>
#include "Personage.h"
//constructor
using namespace std;
    Ghost::Ghost(Vak* vak) : Personage(vak){

    }
    //string van ghost
    string Ghost::toString(){
        return "s";
    }