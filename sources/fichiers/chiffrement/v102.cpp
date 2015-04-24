#include <sstream>
#include <string.h>
#include "utilitaires.h"
#include "my_maths.h"

using namespace std;
using Eigen::MatrixXd;

int  V_102_user_choises() {
   int user_choise;
  
   while (42) {
      cout << "Vous avez choisit d'utiliser la méthode de chiffrement \"v102\"" << endl;
      cout << "Note : il s'agit d'une combinaison du 102 et du Vigenère ( dans le même ordre )" << endl;
      cout << "Souhaitez vous : " << endl;
      cout << "\033[1;36m-1\033[0;0m : retourner au menu précédent" << endl << endl;
      cout << "\033[1;36m1\033[0;0m : chiffrer" << endl;
      cout << "\033[1;36m2\033[0;0m : déchiffrer" << endl;
      user_choise = user_input();
      while (user_choise == 0 || user_choise < -1 || user_choise > 2) {
         cout << "le nombre saisi : '" << user_choise << "' ne correspond pas à un des choix du menu" << endl;
         user_choise = user_input();
      }
      cout << endl;
      switch (user_choise) {
         case -1 :
            cout << "retour au menu précédent" << endl;
            return 0;
         case 1 :
            V_102_choises(1);
            break;
         case 2 :
            V_102_choises(2);
            break;
         default :
            cout << "hum, c'est embarassant : le choix reçu est : \"" << user_choise << "\" celà n'aurait pas dut être possible" << endl;
            cout << "retour au menu précédent" << endl;
            return 0;
      }
   }
  return 0;
}

void  V_102_choises(int choise) {
   const char * lib = lib_choise(7);
   string input;
   string key_base;
   string key_vigenere;
   string buffer;
   int user_choise2;
   int ret = 1;
   int lib_size = strlen(lib);
   MatrixXd key_matrix(2,2);
   MatrixXd text_matrix;
   MatrixXd output;

   matrix_initialisator(key_matrix);
   while (42) {
      cout << "Vous avez choisit d'utiliser le v102" << endl;
      if (choise == 1) {
         cout << "Ici, c'est l'alphabet le plus complet qui est utilisé ( le n°4 ) par défaut" << endl;
      }
      if (choise == 1) {
         cout << "Le v102 chiffrement utilise un total de 3 clefs, une pour la matrice, une seconde pour la base et" << endl;
         cout << "une troisième pour le vigenère" << endl;
         c_str("Note : ", 'y');
         cout << "Il est évident qu'avoir 4 nombres différents pour la matrice garantit une meilleure sécurité" << endl;
         c_str("Note : ", 'y');
         cout << "Les nombres négatifs ou nulls ne sont pas acceptés" << endl;
         c_str("Note : ", 'y');
         cout << "Plus la clef pour le vigenère sera longue et variée ( beaucoup de caractères différents )" << endl;
         cout << "et plus le niveau de sécurité sera élevé ( le mieux étant une clef de la longueur du texte )" << endl;
      } else {
         cout << "Veuillez écrire la clef utilisée pour la matrice ( la première clef )" << endl;
      }
      cout << endl;
      matrix_input_102(key_matrix);
      cout << endl;
      if (choise == 1) {
         cout << "La seconde clef ( la base ) nécéssite que les caractères choisis ( min 2 ) soient tous différents" << endl;
      } else {
         cout << "Veuillez écrire la clef utilisée pour la base ( la première clef )" << endl;
      }
      user_string(key_base);
      while (key_validator_102_base(key_base, lib) == 1) {
         user_string(key_base);
      }
      cout << endl;
      if (choise == 1) {
         cout << "La troisième clef ( pour le Vigenère ) ne doit que comprter les caractères compris dans le 4ème alphabet" << endl;
      }
      else {
         cout << "Veuillez écrire la 3ème clef ( celle du vigenère )" << endl;
      }
      user_string(key_vigenere);
      while (key_check(key_vigenere, lib) == 1) {
         user_string(key_vigenere);
      }
      while (42) {
         if (choise == 1) {
            cout << "Veuillez écrire le texte que vous souhaitez chiffrer" << endl;
         } else {
            cout << "Veuillez écrire le texte que vous souhaitez déchiffrer" << endl;
         }
         ret = 1;
         while (ret == 1) {
            user_string(input);
            ret = input_validator(input, lib);
         }
         if (choise == 1) {
            user_input_to_matrix(text_matrix, input, lib);
            buffer = chiffre_102(text_matrix, key_matrix, key_base);
            buffer = chiffre_vigenere(buffer, lib, lib_size, key_vigenere);
            cout << "Votre texte chiffré : \033[1;35m" << endl;
            cout << buffer << "\033[0;0m" << endl << endl;
         } else {
            buffer = dechiffre_vigenere(input, lib, lib_size, key_vigenere);
            user_input_to_matrix_base(text_matrix, buffer, key_base);
            buffer = dechiffre_102(text_matrix, key_matrix, lib);
            cout << "Votre texte dechiffré : \033[1;35m" << endl;
            cout << buffer << "\033[0;0m" << endl << endl;
         }
         cout << "Que souhaitez vous faire maintenant ?" << endl;
         cout << "\033[1;36m-1\033[0;0m : retourner au menu précédent" << endl << endl;
         if (choise == 1) {
            cout << "\033[1;36m1\033[0;0m : chiffrer avec la même combinaison de clef / alphabet" << endl;
         } else {
            cout << "\033[1;36m1\033[0;0m : dechiffrer avec la même combinaison de clef / alphabet" << endl;
         }
         cout << "\033[1;36m2\033[0;0m : changer de combinaison" << endl;
         user_choise2 = user_input();
         while (user_choise2 < -1 || user_choise2 == 0 || user_choise2 > 2) {
            cout << "Ce choix n'est pas disponible" << endl;
            user_choise2 = user_input();
         }
         cout << endl;
         if (user_choise2 == -1) {
            return ;
         } else if (user_choise2 == 1) {
            // il n'y a rien dans ce if de façon à faire un tour de boucle supplémentaire
         } else if (user_choise2 == 2) {
            break; // sortie de la première boucle pour retourner dans la boucle de la fonction
         }
      }
   }
   return ;
}