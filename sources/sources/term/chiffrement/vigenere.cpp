#include <iostream>
#include <sstream>
#include "term_prototypes.h"
#include "utilitaires.h"
#include "Choice.hpp"
#include "Vigenere.hpp"
#include "Constructor.hpp"
#include "Brick.hpp"

/* ce fichier regroupe toutes les fonctions centrées autours du Césars */

int vigenere_user_choices () { // il faut considérer passer cette fonction en void ( le retour est toujours le même )
  int user_choice;
  Choice choice;
  
  while (42) {
    std::cout << "Vous avez choisit d'utiliser le Vigenère" << std::endl;
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
        vigenere_choices(1);
        break;
      case 2 :
        vigenere_choices(2);
        break;
      default :
        std::cout << "hum, c'est embarassant : le choix reçu est : \"" << user_choice << "\" celà n'aurait pas dut être possible" << std::endl;
        std::cout << "retour au menu précédent" << std::endl;
        return 0;
    }
  }
  return 0;
}

int vigenere_choices (int choice) {
  int tmp;
  int user_choice2;
  std::string input;
  std::string * buffer;
  Choice choice_class;
  Constructor crypt;
  Brick * vi = new Vigenere();
  crypt.add_to_list(vi);
  
  while (42) { // l'utilisateur souhaite continuer à chiffrer en Vigenère
    std::cout << "Vous avez choisit d'utiliser Vigenère" << std::endl;
    if (choice == 1) {
      std::cout << "Veuiller choisir quels seront les caractères qui seront chiffrés ( dans tous les cas, l'espace est chiffré aussi ) :" << std::endl;
      std::cout << "\033[1;33mNote\033[0;0m : il faudra faire le même choix pour déchiffrer correctement" << std::endl;
      std::cout << "\033[1;33mNote\033[0;0m : chaque caractère de votre clef devra être présente dans cet alphabet" << std::endl;
    } 
    else {
      std::cout << "Veuillez indiquer quelle est l'alphabet qui fut utilisé pour le chiffrement" << std::endl;
    }
    std::cout << "\033[1;36m-1\033[0;0m : retourner au menu précédent" << std::endl << std::endl;
    std::cout << "\033[1;36m1\033[0;0m : alphabet minuscule"<< std::endl;
    std::cout << "\033[1;36m2\033[0;0m : alphabet minuscule et majuscule"<< std::endl;
    std::cout << "\033[1;36m3\033[0;0m : alphabet minuscule, majuscule et chiffres" << std::endl;
    std::cout << "\033[1;36m4\033[0;0m : la totale ( presque tout le clavier AZERTY )" << std::endl;
    std::cout << "\033[1;36m5\033[0;0m : alphabet minuscule ( pas d'espace )" << std::endl;
    std::cout << "\033[1;36m6\033[0;0m : alphabet minuscule et majuscule ( pas d'espace )" << std::endl;
    tmp = choice_class.menu_choice(-1, 6);
    if (tmp == -1) {
      return (0);
    }
    crypt.get_lib(tmp);
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
      }
      std::cout << std::endl << std::endl;
      std::cout << "Que souhaitez vous faire maintenant ?" << std::endl;
      std::cout << "\033[1;36m-1\033[0;0m : retourner au menu précédent" << std::endl << std::endl;
      std::cout << "\033[1;36m1\033[0;0m :" << ((choice == 1) ? "chiffrer" : "déchiffrer") << "avec la même combinaison de clef / alphabet" << std::endl;
      std::cout << "\033[1;36m2\033[0;0m : changer de clef" << std::endl;
      user_choice2 = choice_class.menu_choice(-1, 2);
      if (user_choice2 == -1) {
        return (0);
      }
      else if (user_choice2 == 1) {
        // il n'y a rien dans ce if de façon à faire un tour de boucle supplémentaire
      }
      else if (user_choice2 == 2) {
        break; // sortie de la première boucle pour retourner dans le while 42 principal
      }
    }
  }
  return (0);
}
