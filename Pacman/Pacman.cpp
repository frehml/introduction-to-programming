//
// Created by Frederic Hamelink on 06/12/2020.
//
#include "Pacman.h"
#include <string>
#include "Personage.h"

using namespace std;
//constructor
    Pacman::Pacman(Vak* vak) : Personage(vak){

    }
    //string van pacman is O
    string Pacman::toString(){
        return "O";
    }
