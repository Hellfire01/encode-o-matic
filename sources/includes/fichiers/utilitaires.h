#ifndef UTILITAIRES_H
#define UTILITAIRES_H

#include <string>

/* epur_str.cpp */
template<typename T>
void  no_tabs(T str);
template<typename T>
int   no_spaces_duplicates(T str);
template<typename T>
void  no_space_in_begining(T str);
template<typename T>
void  no_space_in_end(T str);
template<typename T>
void  epur_str(T str);

/* isin.cpp */
template<typename T>
int my_isin(char c, T str);

/* lib.cpp */
const char* lib_choice(int lib);

/* user_input.cpp */
int user_input();
void user_string(std::string & in);

/* color_str.cpp */
template <typename T>
void	c_str(T str, char color, int thick = 0);

/* lib_check.cpp */
char lib_char_check(int lib, std::string const & input);
bool lib_bool_check(int lib, std::string const & input);

#endif
