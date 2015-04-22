#ifndef MATHS_H
#define MATHS_H

#include <Eigen/Dense>

/* bases.cpp */
int     my_put_nbr_base(int nbr, const char * base);
int     check_neg(const char * s);
int     check_base(const char * base, int n);
int     my_getnbr_base(const char * str, const char * base);

/* bases_string.cpp */
int     my_put_nbr_base(int nbr, string & base);
int     check_neg(string & s, int mark = 0);
int     check_base(string & base, int n);
int     my_getnbr_base(string & str, string & base, int j = 0);

/* matrix.cpp */
void resize_matrix(MatrixXd & out, int words);
void matrix_initialisator(MatrixXd & matrix);
void user_input_to_matrix(MatrixXd & out, string & input, const char * lib);

#endif