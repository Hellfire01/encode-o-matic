#include "function_prototypes.h"

using namespace std;

int     my_put_nbr_base(int nbr, const char * base) {
  int   nbrc;
  int   basemax;

  basemax = strlen(base);
  nbrc = 1;
  if (nbr < 0) {
    cout << "-";
    nbr = nbr *(-1);
  }
  if (nbr == 0) {
    cout << base[0];
    return (nbr);
  }
  while (nbrc < nbr)
    nbrc = nbrc * basemax;
  if (nbrc > nbr)
    nbrc = nbrc / basemax;
  while (nbrc >= 1) {
    cout << (base[(nbr / nbrc) % basemax]);
    nbrc = nbrc / basemax;
  }
  return (nbr);
}

/* fonctions pour getnbrbase à partir d'ici */

int     check_neg(const char * s) {
  int   i;
  int   cpt;

  i = 0;
  cpt = 0;
  while (s[i] && (s[i] < '0' || s[i] > '9')) {
    if (s[i] == '-') {
      cpt = cpt + 1;
    }
    i = i + 1;
  }
  if (cpt % 2 == 0) {
    return (1);
  }
  return (-1);
}

int     check_base(const char * base, int n) {
  int   i;

  n = 0;
  while (base[n]) {
    i = 0;
    while (base[i]) {
      if (i != n) {
        if (base[n] == base[i]) {
          return (-1);
        }
      }
      i = i + 1;
    }
    n = n + 1;
  }
  return (0);
}

int     my_getnbr_base(const char * str, const char * base) {
  int   nbr;
  int   len;
  int   j;
  int   k;
  int   i;

  len = strlen(base);
  nbr = 0;
  j = 0;
  i = check_neg(str);
  if (check_base(base, 0) == -1) {
    return (0);
  }
  while (str[j] && str[j] != ' ') {
    k = 0;
    while (k < len && base[k] != str[j])
      k = k + 1;
    if (base[k] == str[j])
      nbr = nbr * len + k;
    else
      if ((str[j] != '-' && str[j] != '+'))
        return (0);
    j = j + 1;
  }
  return (nbr * i);
}