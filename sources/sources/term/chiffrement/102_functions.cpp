#include <sstream>
#include <iostream>
#include <math.h>
#include "term_prototypes.h"
#include "my_maths.h"
#include "utilitaires.h"
#include "Choice.hpp"
#include "102.hpp"
#include "Brick.hpp"
#include "Constructor.hpp"

using Eigen::MatrixXd;

int E_102_user_choices () {
  Choice choice;
  int user_choice;

  while (42) {
    std::cout << "Vous avez choisit d'utiliser la méthode de chiffrement \"102\"" << std::endl;
    c_str("Note :", 'y');
    std::cout << " il sagit d'un chiffrement avec une mutiplication matricielle suivie d'un changement de base" << std::endl;
    std::cout << "Souhaitez vous : " << std::endl;
    std::cout << "\033[1;36m-1\033[0;0m : retourner au menu précédent" << std::endl << std::endl;
    std::cout << "\033[1;36m1\033[0;0m : chiffrer" << std::endl;
    std::cout << "\033[1;36m2\033[0;0m : déchiffrer" << std::endl;
    user_choice = choice.menu_choice(-1, 2);
    switch (user_choice) {
      case -1 :
        std::cout << "retour au menu précédent" << std::endl;
        return 0;
      case 1 :
        E_102_choices(1);
        break;
      case 2 :
        E_102_choices(2);
        break;
      default :
        std::cout << "hum, c'est embarassant : le choix reçu est : \"" << user_choice << "\" celà n'aurait pas dut être possible" << std::endl;
        std::cout << "retour au menu précédent" << std::endl;
        return 0;
    }
  }
  return 0;
}

int E_102_choices (int choice) {
    std::string input;
    std::string * buffer;
    int user_choice2;
    Brick * c_102 = new _102();
    Choice choice_class;
    Constructor crypt;
  
  crypt.add_to_list(c_102);
  while (42) {
    std::cout << "Vous avez choisit d'utiliser le 102" << std::endl;
    if (choice == 1) {
      std::cout << "Ici, c'est l'alphabet le plus complet qui est utilisé ( le n°4 ) par défaut" << std::endl;
    }
    if (choice == 1) {
      std::cout << "Le 102 chiffrement utilise un total de 2 clefs, une pour la matrice et une seconde pour la base" << std::endl;
      c_str((char*)"Note : ", 'y');
      std::cout << "Il est évident qu'avoir 4 nombres différents garantit une meilleure sécurité" << std::endl;
      c_str((char*)"Note : ", 'y');
      std::cout << "Les nombres négatifs ou nulls ne sont pas acceptés" << std::endl;
    }

    crypt.get_lib(4);
    crypt.get_keys();

    while (42) {
      std::cout << "Veuillez écrire le texte que vous souhaitez " << ((choice == 1) ? "chiffrer" : "déchiffrer") << std::endl;
      user_string(input);

      if (choice == 1) {
        std::cout << std::endl << "votre texte chiffré :" << std::endl;
	c_str((char*)"\"", 'g');
        std::cout << "\033[1;35m" << *(buffer = crypt.chiffre(input)) << "\033[0;0m";
	c_str((char*)"\"", 'g');
        delete buffer;
        std::cout << std::endl << std::endl << std::endl;
      } else {
        std::cout << std::endl << "votre texte clair ( si vous avez la bonne clef ) :" << std::endl;
	c_str((char*)"\"", 'r');
        std::cout << "\033[1;35m" << *(buffer = crypt.dechiffre(input)) << "\033[0;0m";
	c_str((char*)"\"", 'r');
        delete buffer;
        std::cout << std::endl << std::endl << std::endl;
      }     std::cout << "Que souhaitez vous faire maintenant ?" << std::endl;
      std::cout << "\033[1;36m-1\033[0;0m : retourner au menu précédent" << std::endl << std::endl;
      std::cout << "\033[1;36m1\033[0;0m :" << ((choice == 1) ? "chiffrer" : "déchiffrer") << " avec la même combinaison de clef / alphabet" << std::endl;
      std::cout << "\033[1;36m2\033[0;0m : changer de combinaison" << std::endl;
      user_choice2 = choice_class.menu_choice(-1, 2);
      if (user_choice2 == -1) {
        return (0);
      } else if (user_choice2 == 1) {
        // il n'y a rien dans ce if de façon à faire un tour de boucle supplémentaire
      } else if (user_choice2 == 2) {
        break; // sortie de la première boucle pour retourner dans la boucle de la fonction
      }
    }
  }
  return (0);
}
