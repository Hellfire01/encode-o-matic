#ifndef UTILITAIRES_H
#define UTILITAIRES_H

#include "function_prototypes.h"

using namespace std;

/* epur_str.cpp */
void  no_tabs(char * str);
int   no_spaces_duplicates(char * str);
void  no_space_in_begining(char * str);
void  no_space_in_end(char * str);
void  epur_str(char * str);

/* epur_string.cpp */
void  no_tabs(string & str);
int   no_spaces_duplicates(string & str);
void  no_space_in_begining(string & str);
void  no_space_in_end(string & str);
void  epur_str(string & str);

/* isin.cpp */
int my_isin(char c, char * str);
int my_isin(char c, const char * str);
int my_isin(char c, string & str);
int my_isin(char c, const string & str);

/* lib.cpp */
const char* lib_choise(int lib);

/* user_input.cpp */
int user_input();
char* user_text();
void user_string(string & in);

/* color_str.cpp */
void	c_str(string & str, char color, int thick = 0);
void	c_str(char * str, char color, int thick = 0);
void	c_str(const char * str, char color, int thick = 0);

#endif
