#include "term_prototypes.h"
#include "utilitaires.h"
#include "my_maths.h"
    #include <iostream>

void resize_matrix(MatrixXd & out, int words) {
  int len = words;
  
  if (len % 2 == 1)
    len++;    
  out.resize(2,(len / 2));
  matrix_initialisator(out);
}

void matrix_initialisator(MatrixXd & matrix) {
  int rows = matrix.rows();
  int cols = matrix.cols();
  int r;
  int c = 0;
  
  while (c < cols) {
     r = 0;
     while (r < rows) {
        matrix(r,c) = 0;
        r++;
     }
     c++;
  }
}

void user_input_to_matrix(MatrixXd & out, std::string & input, const char * lib) {
  int a = 0;
  int b = 0;
  int i = 0;
  
  resize_matrix(out, input.size());
  while (a < out.cols()) {
    b = 0;
    while (b < out.rows()) {
      out(b,a) = my_isin(input[i], lib);
      b++;
      i++;
    }
    a++;
  }
}
