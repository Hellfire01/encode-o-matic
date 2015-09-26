#include <string.h>
#include <iostream>
#include "Cesars.hpp"
#include "utilitaires.h"

Cesars::Cesars() {
}

Cesars::~Cesars() {
}

void Cesars::present() {
    std::cout << "Le Césars est une méthode de chiffrement se basant sur un décalage monoalphabétique" << std::endl;
    std::cout << "Toutes les lettres seront décalées de la valeur choisie ( clef ) dans l'alphabet choisit" << std::endl;
}

void Cesars::get_key() {
    int key;

    key = user_input();
    while (key <= 0 || key % _lib_size == 0) {
      if (key < 0) {
        std::cout << "pas de clefs négatives svp ( le césars ne s'utilise qu'avec des nombres entiers positifs )" << std::endl;
      } else {
        std::cout << "la valeur de la clef ( après modulo ) est de : " << key << " % (" << _lib_size << " / 2) = 0" << std::endl;
	std::cout << "elle ne peut donc pas être utilisée car elle ne peut pas chiffrer" << std::endl;
      }
      key = user_input();
    }
    _key = key;
}

Brick::identity Cesars::who() {
    return Brick::C;
}

std::string Cesars::chiffre (std::string & input) {
    std::stringstream out;
    int tmp = 0;
    int i = 0;
    int input_size = input.size();
    
    while (i <= input_size) {
	if ((tmp = my_isin(input[i], _lib)) >= 0) {
	    tmp += (_key % _lib_size);
	    tmp %= _lib_size;
	    out << _lib[tmp];
	} else {
	    out << input[i];
	}
	i++;
    }
    return out.str();
}

std::string Cesars::dechiffre (std::string & input) {
    std::stringstream out;
    int tmp = 0;
    int i = 0;
    int input_size = input.size();
    while (i <= input_size) {
	if ((tmp = my_isin(input[i], _lib)) >= 0) {
	    tmp += _lib_size - _key % _lib_size;
	    tmp %= _lib_size;
	    out << _lib[tmp];
	} else {
	    out << input[i];
	}
	i++;
    }
    return out.str();
}
