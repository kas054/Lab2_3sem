#include <iostream>
#include "Limacon.h"
#include "Dialog.h"
int main() {
    Prog2::Limacon* spr = new Prog2::Limacon();
    Menu::start(spr);
    delete spr;
    return 0;
}
