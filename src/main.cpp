//Copyright [year] <Copyright Owner>
#include <iostream>
#include "kofe.h"

using std::string;

int main() {
    kofe machine = kofe();
    machine.on();
    machine.getMenu();
    machine.coin(20);
    machine.choice(1);
    machine.finish();
    machine.coin(10);
    machine.coin(20);
    machine.choice(3);
    machine.finish();
    machine.off();
    return 0;
}
