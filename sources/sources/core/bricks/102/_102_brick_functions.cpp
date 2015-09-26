#include <iostream>
#include "102.hpp"
#include "utilitaires.h"

Brick::identity _102::who() {
    return Brick::_102;
}

void _102::present() {
    
}

void _102::get_key() {
    std::string key_matrix;
    std::string key_base;
    _102::Check_102_key key_check;
    _102::Check_102_base base_check;

    std::cout << "Clefs pour le 102" << std::endl;
    std::cout << "Veuillez écrire la clef utilisée pour la matrice ( la première clef )" << std::endl;
    std::cout << std::endl;
    user_string(key_matrix);
    std::cout << std::endl;
    key_check = key_input(key_matrix);
    while (key_check != _102::GOOD) {
	switch (key_check) {
	    case _102::BAD_CARACTER :
		c_str((char*)"Error :\n", 'r');
		std::cout << "The caracter '" << bad_carac() << "' is not allowed for the matrix key" << std::endl;
		 break;
	    case _102::NOT_ENOUGH_NUMBERS :
		c_str((char*)"Error :\n", 'r');
		std::cout << "You did not write enough numbers for the matrix key" << std::endl;
		 break;
	    case _102::NO_0 :
		c_str((char*)"Error :\n", 'r');
		std::cout << "You cannot write a 0 : it would result in a data loss" << std::endl;
		 break;
	    case _102::INPUT_ERROR:
		c_str((char*)"Error :\n", 'r');
		std::cout << "Input error ( not enough numbers or weird number)" << std::endl;
		 break;
	    default :
		c_str((char*)"Return Error \n:", 'r');
		std::cout << "key check function returned : '" << key_check << "' witch should not have been possible" << std::endl;
		return ;
	}
	std::cout << std::endl;
        user_string(key_matrix);
	std::cout << std::endl;
	key_check = key_input(key_matrix);
    }
    std::cout << "La seconde clef ( la base ) nécéssite que les caractères choisis ( min 2 ) soient tous différents" << std::endl;
    user_string(key_base);
    while ((base_check = base_input(key_base)) != _102::OK) {
	switch (base_check) {
	    case _102::DUPLICATE :
		c_str((char*)"Error :\n", 'r');
		std::cout << "You cannot have a caracter duplicate as it would result in a data loss" << std::endl;
		std::cout << "The duplicated caracter is : '" << bad_carac() << "'" << std::endl;
		break;
	    case _102::NO_NEG :
		c_str((char*)"Error :\n", 'r');
		std::cout << "You cannot use the '-' caracter in the base ( yet )" << std::endl;
		break;
	    case _102::BAD_CARAC :
		c_str((char*)"Error :\n", 'r');
		std::cout << "The caracter '" << bad_carac() << "' is not part of the lib" << std::endl;
		break;
	    case _102::NO_SPACE :
		c_str((char*)"Error :\n", 'r');
		std::cout << "Spaces cannot be used in the base as it would result in a data loss" << std::endl;
		break;
	    default :
		c_str((char*)"Return Error \n:", 'r');
		std::cout << "base check function returned : '" << base_check << "' witch should not have been possible" << std::endl;
		return ;
	}
	user_string(key_base);
    }
    std::cout << std::endl;
}
