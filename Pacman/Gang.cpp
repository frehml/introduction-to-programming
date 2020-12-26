//
// Created by Frederic Hamelink on 06/12/2020.
//

#include "Gang.h"
#include <string>
using namespace std;
    //constructor
    Gang::Gang(int x, int y) : Vak(x, y){
        personage = nullptr;
        heeft_voedsel = true;
    }
    //gang is altijd begaanbaar
    bool Gang::isBegaanbaar(){
        return true;
    }
    //als er een personage opstaat is het niet vrij anders wel
    bool Gang::isVrij(){
        if (personage == nullptr)
            return true;
        return false;
    }
    //plaatst gegeven personage op gang
    void Gang::plaats_personage(Personage* p){
        personage = p;
    }
    //zet personage van gang terug op nullptr
    void Gang::verwijder_personage(Personage* p){
        p = nullptr;
    }
    //gang heeft initeel voedel
    bool Gang::heeftVoedsel(){
        return heeftVoedsel();
    }
    //zet voedsel op false
    void Gang::eetVoedsel(){
        heeft_voedsel = false;
    }
    //zet gang om naar string, als voedself dan . , geen voedsel dan "" en anders personage
    string Gang::toString(){
        if (personage != nullptr)
            return personage->toString();
        else if (heeft_voedsel)
            return ".";
        else
            return "";
    }