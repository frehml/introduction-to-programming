#include <iostream>
#include <string>
#include "Vak.h"
#include "Personage.h"
#include "Ghost.h"
#include "Pacman.h"
#include "SuperGhost.h"
#include "Muur.h"
#include "Gang.h"

using namespace std;

int main() {
    Muur* muur = new Muur(0, 0);
    Gang* gang = new Gang(1, 1);

    cout<<gang->toString()<<endl;
    cout<<muur->toString()<<endl;

    Pacman* pacman = new Pacman(gang);
    gang->plaats_personage(pacman);
    cout<<gang->toString()<<endl;
    gang->eetVoedsel();
    cout<<gang->isBegaanbaar()<<endl;
    cout<<gang->isVrij()<<endl;
    gang->verwijder_personage(pacman);
    cout<<muur->isBegaanbaar()<<endl;
    cout<<muur->isVrij()<<endl;
}