#include "term_prototypes.h"
#include "utilitaires.h"
#include "Choice.hpp"

#include <iostream>

void info_C_and_V() {
   std::cout << "Les Chiffrements de Césars et de Vigenère utilisés se basent sur les méthodes existantes" << std::endl;
   std::cout << "La grosse différence est que l'aphabet utilisé est une variable : cela vous permet de déterminer quels sont les caractères qui seront chiffrés" << std::endl;
   std::cout << "Le César à en plus pour différence de vous permettre de faire varier le décalage" << std::endl;
   std::cout << "Les deux méthodes sont donc compatibles avec les originales à condition de choisir le bon alphabet" << std::endl;
   std::cout << std::endl;
}

void info_102() {
   std::cout << "Le 102 est une méthode de chiffrement peu sécurisée qui est utilisée par EPITECH pour enseigner aux élèves l'udage des matrices" << std::endl;
   std::cout << "La méthode consiste à mettre le texte dans une première matrice ( chaque lettre prend la valeur de sa place dans l'alphabet )" << std::endl;
   std::cout << "Cette matrice est ensuite multipliée par une seconde de 2 * 2 faisant office de clef" << std::endl;
   std::cout << "La matrice obtenue est ensuite lue et les nombres écrits dans la base choisie par l'utilisateur" << std::endl;
   std::cout << std::endl;
}

void info_v102() {
   std::cout << "Le V102 est une méthode qui utilise le 102 et le Vigenère" << std::endl;
   std::cout << "Le 102 est utilisé en premier et le Vigenère ensuite pour camoufler les bases du 102" << std::endl;
   std::cout << "( et faire de cette faiblaisse une force )" << std::endl;
   std::cout << std::endl;
}

void info_alpha() {
   std::cout << "La plupart des méthodes de chiffrement utilisées font usage d'alphabets comme étant des variables" << std::endl;
   std::cout << "Ces alphabets permettent de déterminer quels seront les caractères du texte ciblé qui seront chiffrés" << std::endl;
   std::cout << "Les alhabets sont au nombre de 6 :" << std::endl;
   c_str((char*)"alphabet minuscule\n", 'y');
   c_str((const char*)lib_choice(1), 'r');
   c_str((char*)"\nalphabet minuscule et majuscule\n", 'y');
   c_str((const char*)lib_choice(2), 'r');
   c_str((char*)"\nalphabet minuscule, majuscule et chiffres\n", 'y');
   c_str((const char*)lib_choice(3), 'r');
   c_str((char*)"\ncet alphabet fait usage de tous les caractères ASCII qui ne sont pas interprétés par le bash\n", 'y');
   c_str(lib_choice(4), 'r');
   std::cout << std::endl;
   std::cout << "\nLes deux derniers alphabets ne chiffrent pas les espaces de façon à être compatibles avec les méthodes originales" << std::endl;
   c_str("alphabet minuscule ( sans espace )\n", 'y');
   c_str(lib_choice(5), 'r');
   c_str("\nalphabet minuscule et majuscule ( sans espace )\n", 'y');
   c_str(lib_choice(6), 'r');
   std::cout << std::endl << std::endl;
}

void display_info() {
   std::cout << std::endl << std::endl;
   std::cout << "Merci d'utiliser \033[1;31mencode-o-matic\033[0;0m" << std::endl;
   std::cout << "Ce programme a pour vocation de permettre à son utilisateur de chiffrer avec la méthode de son choix" << std::endl << std::endl;
   std::cout << "Ultérieurement, l'utilisateur pourra : " << std::endl;
   std::cout << "- chiffrer des fichiers" << std::endl;
   std::cout << "- communiquer de façon sécurisée avec un autre utilisateur" << std::endl;
   std::cout << "- faire usage de méthodes de chiffrement uniques et fortes" << std::endl << std::endl;
   std::cout << "Ce programme a été conçu par :" << std::endl << std::endl;
   std::cout << "Chef de projet :" << std::endl;
   c_str("Matthieu Raynaud de Fitte\n", 'y');
   std::cout << "Bras droit :" << std::endl;
   c_str("Jordan Bauwens\n", 'y');
   // ajouter ici tous les membres de l'équipe
   std::cout << std::endl << std::endl << std::endl << std::endl;

   int user_choice;

   while (42) {
      Choice choice;
      
      std::cout << "Faites votre choix : " << std::endl;
      std::cout << "\033[1;36m-1\033[0;0m : menu principal" << std::endl << std::endl;
      std::cout << "\033[1;36m1\033[0;0m : infos sur le Césars et le Vigenère" << std::endl;
      std::cout << "\033[1;36m2\033[0;0m : infos sur le 102" << std::endl;
      std::cout << "\033[1;36m3\033[0;0m : infos sur le v102" << std::endl;
      std::cout << "\033[1;36m4\033[0;0m : infos sur les alphabets" << std::endl;
      user_choice = choice.menu_choice(-1, 4);
      switch (user_choice) {
      case -1 :
         return ;
      case 1 :
         info_C_and_V();
         break;
      case 2 :
         info_102();
         break;
      case 3 :
         info_v102();
         break;
      case 4 :
         info_alpha();
         break;
      default :
         std::cout << "hum, c'est embarassant : le choix reçu est : \"" << user_choice << "\" celà n'aurait pas dut être possible" << std::endl;
         std::cout << "retour au menu principal" << std::endl;
         return ;
      }
   }
}
