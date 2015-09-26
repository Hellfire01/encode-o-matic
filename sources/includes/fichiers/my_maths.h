#ifndef MATHS_H
#define MATHS_H

#include <Eigen/Dense>
#include <string>
#include <sstream>

using Eigen::MatrixXd;

/* bases.cpp */
int     my_put_nbr_base(int nbr, const char * base);
int     check_neg(const char * s);
int     check_base(const char * base, int n);
int     my_getnbr_base(const char * str, const char * base);

/* bases_string.cpp */
int     my_put_nbr_base(int nbr, std::string & base);
void    base_to_stream(int nbr, std::string & base, std::stringstream & out);
int     check_neg(std::string & s, int mark = 0);
int     check_base(std::string & base, int n);
int     my_getnbr_base(std::string & str, std::string & base, int j = 0);

/* matrix.cpp */
void resize_matrix(MatrixXd & out, int words);
void matrix_initialisator(MatrixXd & matrix);
void user_input_to_matrix(MatrixXd & out, std::string & input, const char * lib);

#endif
