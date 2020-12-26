//
// Created by Frederic on 06/12/2020.
//

#include "Vak.h"
    //constructor
    Vak::Vak(int x, int y){
        rij = x;
        kolom = y;
    }
    //attr_reader
    int Vak::getKolom()
    {
        return kolom;
    }
    //attr_reader
    int Vak::getRij()
    {
        return rij;
    }