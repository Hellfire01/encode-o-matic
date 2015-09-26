#include <iostream>
#include "102.hpp"
#include "my_maths.h"
#include "utilitaires.h"

using Eigen::MatrixXd;

_102::_102 () {
    _lib = lib_choice(4);
    this->key_check = false;
    this->bad_caracter = '\0';
    this->key_matrix = MatrixXd(2,2);
}

_102::~_102 () {
    
}

_102::Check_102_base _102::base_input(std::string & input) {
  int i = 0;
  int a;
  
  while (input[i] != '\0') {
    if (input[i] == ' ')
        return NO_SPACE;
    if (input[i] == '-')
        return NO_NEG;
    a = i;
    if (my_isin(input[a], _lib) == -1) {
	this->bad_caracter = input[a];
	return BAD_CARAC;
    }
    while (input[a + 1] != '\0') {
      if (input[i] == input[a + 1]) {
	this->bad_caracter = input[a];
	return DUPLICATE;
      }
      a++;
    }
    i++;
  }
  this->base = input;
  this->bad_caracter = '\0';
  return OK;
}

char _102::bad_carac() {
    return this->bad_caracter;
}

char _102::input_validator(std::string & str) {
    int i = 0;
    
    while (str[i] != '\0') {
	if (my_isin(str[i], _lib) == -1) {
	    this->bad_caracter = str[i];
	    return str[i];
	}
	i++;
    }
    return '\0';
}

void  _102::user_input_to_matrix_base(std::string & input) {
  int a = 0;
  int b;
  int i = 0;
  int words = 0;
  
  while (input[i] != '\0') {
    if (input[i] == ' ') {
      words++;
    }
    i++;
  }
  i = 0;
  resize_matrix(this->text_matrix, words);
  matrix_initialisator(this->text_matrix);
  while (a < this->text_matrix.cols()) {
    b = 0;
    while (b < this->text_matrix.rows()) {
      this->text_matrix(b,a) = my_getnbr_base(input, this->base, i);
      while (input[i] != ' ' && input[i] != '\0') {
        i++;
      }
      if (input[i] != '\0') {
        i++;
      }
      b++;
    }
    a++;
  }
}
