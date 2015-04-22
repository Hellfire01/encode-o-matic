#include "function_prototypes.h"
#include "utilitaires.h"

using namespace::std;

void info_C_and_V() {
   cout << "Les Chiffrements de Césars et de Vigenère utilisés se basent sur les méthodes existantes" << endl;
   cout << "La grosse différence est que l'aphabet utilisé est une variable : cela vous permet de déterminer quels sont les caractères qui seront chiffrés" << endl;
   cout << "Le César à en plus pour différence de vous permettre de faire varier le décalage" << endl;
   cout << "Les deux méthodes sont donc compatibles avec les originales à condition de choisir le bon alphabet" << endl;
   cout << endl;
}

void info_102() {
   cout << "Le 102 est une méthode de chiffrement peu sécurisée qui est utilisée par EPITECH pour enseigner aux élèves l'udage des matrices" << endl;
   cout << "La méthode consiste à mettre le texte dans une première matrice ( chaque lettre prend la valeur de sa place dans l'alphabet )" << endl;
   cout << "Cette matrice est ensuite multipliée par une seconde de 2 * 2 faisant office de clef" << endl;
   cout << "La matrice obtenue est ensuite lue et les nombres écrits dans la base choisie par l'utilisateur" << endl;
   cout << endl;
}

void info_alpha() {
   cout << "La plupart des méthodes de chiffrement utilisées font usage d'alphabets comme étant des variables" << endl;
   cout << "Ces alphabets permettent de déterminer quels seront les caractères du texte ciblé qui seront chiffrés" << endl;
   cout << "Les alhabets sont au nombre de 6 :" << endl;
   c_str("alphabet minuscule\n", 'y');
   cout << "\033[1;31m\"\033[0;0mabcdefghijklmnopqrstuvwxyz \033[1;31m\"\033[0;0m" << endl;
   c_str("alphabet minuscule et majuscule\n", 'y');
   cout << "\033[1;31m\"\033[0;0mabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ \033[1;31m\"\033[0;0m" << endl;
   c_str("alphabet minuscule, majuscule et chiffres\n", 'y');
   cout << "\033[1;31m\"\033[0;0mabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 \033[1;31m\"\033[0;0m" << endl;
   c_str("cet alphabet fait usage de tous les caractères ASCII qui ne sont pas interprétés par le bash\n", 'y');
   cout << "\033[1;31m\"\033[0;0mabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 !\"#$%&'()*+,-./[\\]^_`{<|=}>~?\033[1;31m\"\033[0;0m" << endl;
   cout << endl;
   cout << "Les deux derniers alphabets ne chiffrent pas les espaces de façon à être compatibles avec les méthodes originales" << endl;
   c_str("alphabet minuscule ( sans espace )\n", 'y');
   cout << "\033[1;31m\"\033[0;0mabcdefghijklmnopqrstuvwxyz\033[1;31m\"\033[0;0m" << endl;
   c_str("alphabet minuscule et majuscule ( sans espace )\n", 'y');
   cout << "\033[1;31m\"\033[0;0mabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ\033[1;31m\"\033[0;0m" << endl;
   cout << endl;
}

void display_info() {
   cout << endl << endl;
   cout << "Merci d'utiliser \033[1;31mencode-o-matic\033[0;0m" << endl;
   cout << "Ce programme a pour vocation de permettre à son utilisateur de chiffrer avec la méthode de son choix" << endl << endl;
   cout << "Ultérieurement, l'utilisateur pourra : " << endl;
   cout << "- chiffrer des fichiers" << endl;
   cout << "- communiquer de façon sécurisée avec un autre utilisateur" << endl;
   cout << "- faire usage de méthodes de chiffrement uniques et fortes" << endl << endl;
   cout << "Ce programme a été conçu par :" << endl << endl;
   cout << "Chef de projet :" << endl;
   c_str("Matthieu Raynaud de Fitte\n", 'y');
   // ajouter ici tous les membres de l'équipe
   cout << endl << endl << endl << endl;

   int user_choise;

   while (42) {
      cout << "Faites votre choix : " << endl;
      cout << "\033[1;36m-1\033[0;0m : menu principal" << endl << endl;
      cout << "\033[1;36m1\033[0;0m : infos sur le Césars et le Vigenère" << endl;
      cout << "\033[1;36m2\033[0;0m : infos sur le 102" << endl;
      cout << "\033[1;36m3\033[0;0m : infos sur les alphabets" << endl;
      user_choise = user_input();
      while (user_choise == 0 || user_choise < -1 || user_choise > 3) {
         cout << "le nombre saisi : '" << user_choise << "' ne correspond pas à un des choix du menu" << endl;
         user_choise = user_input();
      }
      cout << endl;
      switch (user_choise) {
      case -1 :
         return ;
      case 1 :
         info_C_and_V();
         break;
      case 2 :
         info_102();
         break;
      case 3 :
         info_alpha();
         break;
      default :
         cout << "hum, c'est embarassant : le choix reçu est : \"" << user_choise << "\" celà n'aurait pas dut être possible" << endl;
         cout << "retour au menu principal" << endl;
         return ;
      }
   }
}
