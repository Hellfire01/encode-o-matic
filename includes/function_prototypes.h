#ifndef FUNCTION_PROTOTYPES_H
#define FUNCTION_PROTOTYPES_H

#include <stdlib.h>
#include <string.h>

/* ici sont placés les prototypes de mes fonctions */

/* cesars.cpp */
int cesars_choises(int choise);
int cesars_user_choises();
void chiffre_cesars (char const * input, const char* lib, int lib_size, int key);
void dechiffre_cesars(char const * input, const char* lib, int lib_size, int key);

/* isin.cpp */
int my_isin(char c, const char* str);
int my_isin2(char c, const char* str);
int my_isin2(char c, char* str);

/* lib.cpp */
const char* lib_choise(int lib);

/* main.cpp */

/* user_input.cpp */
int user_input();
char* user_text();

/* vigenere.cpp */
void chiffre_vigenere(char * &input, char const * &lib, int lib_size, char * &key);
void dechiffre_vigenere(char * &input, char const * &lib, int lib_size, char * &key);
int key_check(char * &key, const char * &lib);
int vigenere_choises (int choise);
int vigenere_user_choises();

#endif
