Copyright [year] <Copyright Owner>
#pragma once
#include <iostream>
#include <string>

using std::string;

enum States {
  OFF,
  WAIT,
  ACCEPT,
  CHECK,
  COOK
};

class kofe {
 private:
    int cash;
    string* menu;
    int* prices;
    States state;
    int option;

 public:
    kofe();
    void on();
    void off();
    void coin(int money);
    void getMenu();
    States getState();
    void choice(int _choice);
    int cancel();
    bool check();
    void cook();
    int finish();
};
