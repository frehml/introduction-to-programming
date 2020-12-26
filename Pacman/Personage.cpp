//
// Created by Frederic on 06/12/2020.
//

#include "Personage.h"
#include "Vak.h"
#include <string>
#include "Ghost.h"
using namespace std;


    Vak* vak;
    //constructor
    Personage::Personage(Vak* v){
        vak = v;
    }
    //attr_reader
    Vak* Personage::getVak(){
        return vak;
    };
    //checkt of personage botst met iets
    bool Personage::botstMet(Personage* p){
        if (getVak() == p->getVak())
            return true;
        return false;
    }
    //geeft de volgender rij pos adhv richting
    int Personage::volgende_rij_positie(char richting){
        int rij = getVak()->getRij();
        if (richting == 'B')
            rij--;
        else if (richting == 'O')
            rij++;

        return rij;
    }
    //geeft de volgender kolom pos adhv richting
    int Personage::volgende_kolom_positie(char richting){
        int kol = getVak()->getKolom();
        if (richting == 'L')
            kol--;
        else if (richting == 'R')
            kol++;


        return kol;
    }

    //verplaatst personage naar nieuw vak
    void Personage::verplaats(Vak* nieuw_vak){
        vak = nieuw_vak;
    }

    //string van personage 
    string Personage::toString() {
        return "O";
    }
