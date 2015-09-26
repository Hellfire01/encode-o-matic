#include <iostream>
#include "term_prototypes.h"
#include "utilitaires.h"
#include "102.hpp"

using Eigen::MatrixXd;

int _102::numbers_only(std::string & tmp) {
  int i = 0;
  std::string base = "0123456789 ";
  
  while (tmp[i] != '\0') {
    if (my_isin<std::string &>(tmp[i], base) == -1) {
      std::cout << "Erreur : que des nombres svp" << std::endl;
      std::cout << "'" << tmp[i] << "' n'en est pas un" << std::endl;
      return (1);
    }
    i++;
  }
  return (0);
}

int _102::fast_check(std::string & tmp) {
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
    c_str((char*)"il faut au moins 4 nombres pour a matrice\n", 'r');
    return 1;
  }
  if (nbr > 4)
    c_str((char*)"Warning : les nombres suivant le 4ème sont ignorés\n", 'y');
  return 0;
}

int _102::write_matrix(MatrixXd & out, std::string tmp) {
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
        std::cout << "Wouah ! grosse erreur dans l'imput de la matrice" << std::endl;
        std::cout << "fonction write_matrix(), i = '" << i << "' ce qui aurait dut être impossible" << std::endl;
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

int _102::last_check(MatrixXd & out) {
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

void _102::matrix_input_102(MatrixXd &out) {
  std::string tmp;
  int ret = 1;
  int ret2 = 1;
  
  while (ret == 1 || ret2 == 1) {
    ret2 = 0;
    std::cout << "Veuillez écrire 4 nombres séparés par un espace svp" << std::endl;
    user_string(tmp);
    epur_str(tmp);
    ret = write_matrix(out, tmp);
    if (ret == 1)
      c_str((char*)"\nMatrix input error !!!\n", 'r');
    ret2 = last_check(out);
    if (ret2 == 1 && ret == 0) {
      std::cout << std::endl;
      c_str("Erreur : ", 'r');
      std::cout << "Ainsi qu'il a été précisé précédement, les nombres nulls ne sont pas acceptés" << std::endl;
      std::cout << "Un nombre null dans la matrice de chiffrement créerait des pertes de données" << std::endl << std::endl;
    }
  }
}
