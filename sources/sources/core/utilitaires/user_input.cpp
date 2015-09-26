#include "term_prototypes.h"
#include "utilitaires.h"

#include <iostream>

int user_input() {
  std::string tmp;
  int i;
  int a;
  bool lock = false;
  
  while (42) {
    a = 0;
    user_string(tmp);
    epur_str(tmp);
    while (tmp[a] != '\0') {
      if (my_isin(tmp[a], "-0123456789") == -1) {
        c_str((char*)"Que des nombres svp\n", 'r');
        lock = true;
        break ;
      }
      a++;
    }
    if (lock == false) {
      i = stoi(tmp);
      return (i);
    }
    lock = false;
  }
}

void user_string(std::string & in) {
  std::cout << std::endl << "\033[1;34m";
  getline(std::cin, in);
  std::cout << "\033[0;0m";
}
