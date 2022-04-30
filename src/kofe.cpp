Copyright [year] <Copyright Owner>
#include "kofe.h"

using std::cout;
using std::endl;

kofe::kofe() {
    cash = 0;
    menu = new std::string[3];
    menu[0] = "Item 1";
    menu[1] = "Item 2";
    menu[2] = "Item 3";
    prices = new int[3];
    prices[0] = 10;
    prices[1] = 20;
    prices[2] = 30;
    state = OFF;
}
void kofe::on() {
    if (state == OFF) state = WAIT;
}
void kofe::off() {
    if (state == WAIT) state = OFF;
}
void kofe::coin(int money) {
    if (state == WAIT) {
        state = ACCEPT;
    }
    cash += money;
}
void kofe::getMenu() {
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ". " << menu[i] << " " << prices[i] << endl;
    }
}
States kofe::getState() {
    return state;
}
void kofe::choice(int _choice) {
    if (state == ACCEPT) {
        state = CHECK;
        option = _choice;
    }
}
bool kofe::check() {
    if (state == CHECK && cash >= prices[option - 1]) return true;
    return false;
}
int kofe::cancel() {
    int cash2 = 0;
    if (state == ACCEPT || state == CHECK) {
        state = WAIT;
        cash2 = cash;
        cash = 0;
    }
    return cash2;
}
void kofe::cook() {
    if (state == CHECK) {
        state = COOK;
        cash -= prices[option - 1];
    }
}
int kofe::finish() {
    int temp = 0;
    if (state == COOK) {
        state = WAIT;
        temp = cash;
        cash = 0;
    }
    return temp;
}
