#ifndef TERM_PROTOTYPES_H
#define TERM_PROTOTYPES_H

#include <string>

/* includes des librairies utilisées */
#include <Eigen/Dense>

using Eigen::MatrixXd;


/* ici sont placés les prototypes de mes fonctions */

/* main_term.cpp */
int main_term();

/* 102.cpp */
int E_102_user_choices ();
int E_102_choices (int choice);

/* v102.cpp */
int  V_102_user_choices();
void  V_102_choices(int choice);

/* cesars.cpp */
int cesars_choices(int choice);
int cesars_user_choices();

/* info.cpp */
void info_C_and_V();
void info_102();
void info_v102();
void info_alpha();
void display_info();

/* vigenere.cpp */
int vigenere_choices (int choice);
int vigenere_user_choices();

#endif
