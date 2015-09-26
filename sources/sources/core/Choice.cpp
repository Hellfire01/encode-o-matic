#include <iostream>
#include "utilitaires.h"
#include "Choice.hpp"

int Choice::menu_choice(int min, int max) {
    int user_choice = user_input();
    while (user_choice == 0 || user_choice < min || user_choice > max) {
      std::cout << "le nombre saisi : '" << user_choice << "' ne correspond pas à un des choix du menu" << std::endl;
      user_choice = user_input();
    }
    std::cout << std::endl;
    return user_choice;
}

Choice::Choice() {
}

Choice::~Choice() {
}
