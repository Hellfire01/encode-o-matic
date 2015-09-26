#include "102.hpp"
#include "my_maths.h"

#include <stdlib.h>
#include <iostream>

std::string  _102::dechiffre(std::string & input) {
  std::stringstream out;
  int a = 0;
  int b;
  MatrixXd tmp;

  this->user_input_to_matrix_base(input);  
  tmp = this->key_matrix.inverse() * this->text_matrix;
  while (a < tmp.cols()) {
    b = 0;
    while (b < tmp.rows()) {
      out << _lib[(int)round(tmp(b,a))]; // la fonction round() est utilisée avant le cast pour éviter les pertes de données liées à celui-ci
      b++;
    }
    a++;
  }
  return (out.str());
}

std::string  _102::chiffre(std::string & input) {
  std::stringstream out;
  MatrixXd output;
  int a = 0;
  int b;
  int space = 1;

  user_input_to_matrix(this->text_matrix, input, _lib);
  output = this->key_matrix * this->text_matrix;
  while (a < output.cols()) {
    b = 0;
    while (b < output.rows()) {
      if (space == 1) {
        space = 0;
      } else {
        out << " ";
      }
      base_to_stream(output(b,a), this->base, out); // cette fonction se charge d'écrire dans le stringstream
      b++;
    }
    a++;
  }
  return out.str();
}
