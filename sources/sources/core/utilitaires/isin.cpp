#include "utilitaires.h"

/*
** my_isin renvoie la position du caractère dans la chaine qui lui
**    a été passé en argument et retourne ( -1 ) s'il se trouve que le
**    caractère n'est pas dans la chaîne.
*/

template int my_isin<char *>(char c, char * str);
template int my_isin<const char *>(char c, const char * str);
template int my_isin<std::string &>(char c, std::string & str);
template int my_isin<const std::string &>(char c, const std::string & str);

template <typename T>
int my_isin(char c, T str) {
  int i = 0;

  while (str[i]) {
    if (str[i] == c)
      return (i);
    i = i + 1;
  }
  return (-1);
}
