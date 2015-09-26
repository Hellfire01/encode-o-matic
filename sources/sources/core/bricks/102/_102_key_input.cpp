#include "my_maths.h"
#include "utilitaires.h"
#include "102.hpp"

using Eigen::MatrixXd;

int _102::write_matrix(std::string tmp) { // ne PAS envoyer la référence
    int i = 0;
    int a = 0;
    
    while(i < 4) {
	tmp = &tmp[a]; // la raison pour laquelle il ne faut PAS envoyer la référence
	a = 0;
	if (tmp[a] == '\0') {
	    return 1;
	}
	switch (i) {
	    case 0:
		this->key_matrix(0,0) = stoi(tmp);
		break;
	    case 1:
		this->key_matrix(1,0) = stoi(tmp);
		break;
	    case 2:
		this->key_matrix(0,1) = stoi(tmp);
		break;
	    case 3:
		this->key_matrix(1,1) = stoi(tmp);
		break;
	    default :
		return 1;
	}
	while (tmp[a] != '\0' && tmp[a] != ' ')
	    a++;
	if (tmp[a] != '\0')
	    a++;
	i++;
	}
    return (0);
}

int _102::last_check() {
    if (this->key_matrix(0,0) == 0)
	return (1);
    if (this->key_matrix(1,0) == 0)
	return (1);
    if (this->key_matrix(0,1) == 0)
	return (1);
    if (this->key_matrix(1,1) == 0)
	return (1);
    return (0);
}

_102::Check_102_key _102::key_input(std::string & input) {
    matrix_initialisator(this->key_matrix);
    epur_str(input);
    if (numbers_only(input) == 1) {
        this->key_check = false;
	return BAD_CARACTER;
    }
    if (fast_check(input) == 1) {
        this->key_check = false;
	return NOT_ENOUGH_NUMBERS;
    }
    if (write_matrix(input) == 1) {
        this->key_check = false;
	return INPUT_ERROR;
    }
    if (last_check() == 1) {
        this->key_check = false;
	return NO_0;
    }
    this->key_check = true;
    this->bad_caracter = '\0';
    return GOOD;
}
