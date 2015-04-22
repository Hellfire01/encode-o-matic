#include "function_prototypes.h"
#include "utilitaires.h"

using namespace std;
using Eigen::MatrixXd;

int numbers_only(string tmp) {
  int i = 0;
  string base = "0123456789 ";
  
  while (tmp[i] != '\0') {
    if (my_isin(tmp[i], base) == -1) {
      cout << "Erreur : que des nombres svp" << endl;
      cout << "'" << tmp[i] << "' n'en est pas un" << endl;
      return (1);
    }
    i++;
  }
  return (0);
}

int fast_check(string tmp) {
  int i = 0;
  int nbr = 1; // il y a toujour un espace en moins par rapport à la quantité de nombres
  
  if (tmp.length() < 7 || numbers_only(tmp) == 1) // 4 chifres séparés par un espace ont une longueur de 7
    return 1;
  while (tmp[i] != '\0') {
    if (tmp[i] == ' ') { // grace au epur_str, il n(='y a plus qu'un seul espace comme séparateur)
      nbr++;
    }
    i++;
  }
  if (nbr < 4) {
    c_str("il faut au moins 4 nombres pour a matrice\n", 'r');
    return 1;
  }
  if (nbr > 4)
    c_str("Warning : les nombres suivant le 4ème sont ignorés\n", 'y');
  return 0;
}

int write_matrix(MatrixXd & out, string tmp) {
  int i = 0;
  int a = 0;
  
  if (fast_check(tmp) == 1)
    return 1;
  while(i < 4) {
    tmp = &tmp[a];
    a = 0;
    if (tmp[a] == '\0') {
      return 1;
    }
    switch (i) {
      case 0:
        out(0,0) = atoi(tmp.c_str());
        break;
      case 1:
        out(1,0) = atoi(tmp.c_str());
        break;
      case 2:
        out(0,1) = atoi(tmp.c_str());
        break;
      case 3:
        out(1,1) = atoi(tmp.c_str());
        break;
      default :
        cout << "Wouah ! grosse erreur dans l'imput de la matrice" << endl;
        cout << "fonction write_matrix(), i = '" << i << "' ce qui aurait dut être impossible" << endl;
        return 1;
    }
    while (tmp[a] != '\0' && tmp[a] != ' ')
      a++;
    if (tmp[a] != '\0')
      a++;
    i++;
  }

  return (0);
}

int last_check(MatrixXd & out) {
  if (out(0,0) == 0)
    return (1);
  if (out(1,0) == 0)
    return (1);
  if (out(0,1) == 0)
    return (1);
  if (out(1,1) == 0)
    return (1);
  return (0);
}

void matrix_input_102(MatrixXd &out) {
  string tmp;
  int ret = 1;
  int ret2 = 1;
  
  while (ret == 1 || ret2 == 1) {
    ret2 = 0;
    cout << "Veuillez écrire 4 nombres séparés par un espace svp" << endl;
    user_string(tmp);
    epur_str(tmp);
    ret = write_matrix(out, tmp);
    if (ret == 1)
      c_str("\nMatrix input error !!!\n", 'r');
    ret2 = last_check(out);
    if (ret2 == 1 && ret == 0) {
      cout << endl;
      c_str("Erreur : ", 'r');
      cout << "Ainsi qu'il a été précisé précédement, les nombres nulls ne sont pas acceptés" << endl;
      cout << "Un nombre null dans la matrice de chiffrement créerait des pertes de données" << endl << endl;
    }
  }
}
