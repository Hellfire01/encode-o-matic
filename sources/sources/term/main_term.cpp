#include <iostream>
#include "term_prototypes.h"
#include "Choice.hpp"

int main_term() {
  int user_choice;
  Choice choice;

  std::cout << std::endl << "********************" << std::endl;
  std::cout << "** \033[1;31mEncode o matic\033[0;0m **" << std::endl;
  std::cout << "********************" << std::endl << std::endl;
  while (42) {
    std::cout << "Faites votre choix : " << std::endl;
    std::cout << "\033[1;36m-2\033[0;0m : afficher les infos" << std::endl;
    std::cout << "\033[1;36m-1\033[0;0m : quitter" << std::endl << std::endl;
    std::cout << "\033[1;36m1\033[0;0m : Césars" << std::endl;
    std::cout << "\033[1;36m2\033[0;0m : Vigenère" << std::endl;
    std::cout << "\033[1;36m3\033[0;0m : 102 ( matrice + base )" << std::endl;
    std::cout << "\033[1;36m4\033[0;0m : 102V ( ombinaison 102 et Vigenère )" << std::endl;
    user_choice = choice.menu_choice(-2, 4);
    switch (user_choice) {
      case -2 :
        display_info();
        break;
      case -1 :
        std::cout << std::endl << "Bye !" << std::endl << std::endl;
        return 0;
      case 1 :
        cesars_user_choices();
        break;
      case 2 :
        vigenere_user_choices();
        break;
      case 3 :
        E_102_user_choices();
        break;
      case 4 :
        V_102_user_choices();
        break;
      default :
        std::cout << "hum, c'est embarassant : le choix reçu est : \"" << user_choice << "\" celà n'aurait pas dut être possible" << std::endl;
        std::cout << "Fermeture du programme" << std::endl;
        return 0;
    }
  }
  return 0;
}