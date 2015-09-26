/*
** color_str.c for header in /home/raynau_a/rendu/GETNEXT-MAKEFILE-LIB/my_lib
** 
** Made by matthieu raynaud de fitte
** Login   <raynau_a@epitech.net>
** 
** Started on  Sat Feb 22 18:49:16 2014 matthieu raynaud de fitte
** Last update Thu Aug 14 22:09:51 2014 mat
*/

#include <iostream>
#include "utilitaires.h"

template void c_str<std::string &>(std::string & str, char color, int thick);
template void c_str<char *>(char * str, char color, int thick);
template void c_str<const char *>(const char * str, char color, int thick);

template <typename T>
void	c_str(T str, char color, int thick) {
  int tmp = my_isin(color, "rgybpcew") + 1;
  
  if (tmp > 0 && tmp < 9) {
    std::cout << "\033[" << thick << ";3" << tmp << "m" << str << "\033[0;0m";
  } else {
    std::cout << str;
  }
}
