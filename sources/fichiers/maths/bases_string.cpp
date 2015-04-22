#include "function_prototypes.h"

using namespace std;

int     my_put_nbr_base(int nbr, string & base) {
  int   nbrc;
  int   basemax;

  basemax = base.size();
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

int     check_neg(string & s, int mark) {
  int   i = mark;
  int   cpt = 0;

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

int     check_base(string & base, int n) {
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

int     my_getnbr_base(string & str, string & base, int mark) {
  int   nbr = 0;
  int   len = base.size();
  int   k;
  int   i = check_neg(str, mark);
  int   j = mark;

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