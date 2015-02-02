using namespace std;

int	my_isin(char c, const char* str) {
  int	i = 0;
  while (str[i]) {
    if(str[i] == c)
      return (1);
    i = i + 1;
  }
  return (0);
}

/*
** my_isin2 renvoie la position du caractère dans la chaine qui lui
**    a été passé en argument et retourne ( -1 ) s'il se trouve que le
**    caractère n'est pas dans la chaîne.
*/

int my_isin2(char c, const char* str) {
  int i = 0;
  while (str[i]) {
    if (str[i] == c)
      return (i);
    i = i + 1;
  }
  return (-1);
}

int my_isin2(char c, char* str) {
  int i = 0;
  while (str[i]) {
    if (str[i] == c)
      return (i);
    i = i + 1;
  }
  return (-1);
}