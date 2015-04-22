#include "function_prototypes.h"

using namespace std;

/*
** my_isin2 renvoie la position du caractère dans la chaine qui lui
**    a été passé en argument et retourne ( -1 ) s'il se trouve que le
**    caractère n'est pas dans la chaîne.
*/

int my_isin(char c, char * str) {

  int i = 0;

  while (str[i]) {
    if (str[i] == c)
      return (i);
    i = i + 1;
  }
  return (-1);
}

int my_isin(char c, const char * str) {

  int i = 0;

  while (str[i]) {
    if (str[i] == c)
      return (i);
    i = i + 1;
  }
  return (-1);
}

int my_isin(char c, string & str) {

  int i = 0;

  while (str[i]) {
    if (str[i] == c)
      return (i);
    i = i + 1;
  }
  return (-1);
}

int my_isin(char c, const string & str) {

  int i = 0;

  while (str[i]) {
    if (str[i] == c)
      return (i);
    i = i + 1;
  }
  return (-1);
}