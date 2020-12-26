//
// Created by Frederic Hamelink on 06/12/2020.
//

#include "SuperGhost.h"
#include "Ghost.h"
#include "Personage.h"
    //constructor
    SuperGhost::SuperGhost(Vak* vak) : Ghost(vak){

    }
    //string van superghost is S
    char SuperGhost::toString(){
        return 'S';
    }

    //geeft volgende rij positie adhv richting (random)
    int SuperGhost::volgende_rij_positie(char richting){
        int rij = getVak()->getRij();

        if (richting == 'B')
            rij = rij-((rand() % 2) + 1);
        else if (richting == 'O')
            rij = rij+((rand() % 2) + 1);


        return rij;
    }
    //geeft volgende kolom positie adhv richting (random)
    int SuperGhost::volgende_kolom_positie(char richting){
        int kol = getVak()->getKolom();
        if (richting == 'L')
            kol = kol-((rand() % 2) + 1);
        else if (richting == 'R')
            kol = kol+((rand() % 2) + 1);

        return kol;
    }