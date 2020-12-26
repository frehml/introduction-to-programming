//
// Created by Frederic Hamelink on 06/12/2020.
//

#include "Muur.h"
#include <string>
using namespace std;

Muur::Muur(int x, int y) : Vak(x, y){

}
//muur is nooit begaanbaar
bool Muur::isBegaanbaar(){
    return false;
}
//muur is nooit vrij
bool Muur::isVrij(){
    return false;
}
// string van muur is M
string Muur::toString(){
    return "M";
}