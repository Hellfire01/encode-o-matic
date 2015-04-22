#include <math.h>
#include "function_prototypes.h"
#include "my_maths.h"
#include "utilitaires.h"

/* ce fichier regroupe toutes les fonctions centrées autours du Césars */

using namespace std;
using Eigen::MatrixXd;

int E_102_user_choises () {
  int user_choise;
  
  while (42) {
    cout << "Vous avez choisit d'utiliser la méthode de chiffrement \"102\"" << endl;
    cout << "Note : il sagit d'un chiffrement avec une mutiplication matricielle suivie d'un changement de base" << endl;
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
        E_102_choises(1);
        break;
      case 2 :
        E_102_choises(2);
        break;
      default :
        cout << "hum, c'est embarassant : le choix reçu est : \"" << user_choise << "\" celà n'aurait pas dut être possible" << endl;
        cout << "retour au menu précédent" << endl;
        return 0;
    }
  }
  return 0;
}

int E_102_choises (int choise) {
  const char * lib;
  string input;
  string key_base;
  int user_choise2;
  int ret = 1;
  MatrixXd key_matrix(2,2);
  MatrixXd text_matrix;
  MatrixXd output;

  matrix_initialisator(key_matrix);
  while (42) { // l'utilisateur souhaite continuer à chiffrer en Césars
    cout << "Vous avez choisit d'utiliser le 102" << endl;
    if (choise == 1) {
      cout << "Ici, c'est l'alphabet le plus complet qui est utilisé ( le n°4 ) par défaut" << endl;
    }
    lib = lib_choise(7);
    if (choise == 1) {
      cout << "Le 102 chiffrement utilise un total de 2 clefs, une pour la matrice et une seconde pour la base" << endl;
      c_str("Note : ", 'y');
      cout << "Il est évident qu'avoir 4 nombres différents garantit une meilleur sécurité" << endl;
      c_str("Note : ", 'y');
      cout << "Les nombres négatifs ou nulls ne sont pas acceptés" << endl;
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
    while (42) {
      if (choise == 1) {
        cout << "Veuillez écrire le texte que vous souhaitez chiffrer" << endl;
      } else {
        cout << "Veuillez écrire le texte que vous souhaitez déchiffrer" << endl;
      }
      while (ret == 1) {
        user_string(input);
        ret = input_validator(input, lib);
      }
      if (choise == 1) {
        user_input_to_matrix(text_matrix, input, lib);
        chiffre_102(text_matrix, key_matrix, key_base);
      } else {
        user_input_to_matrix_base(text_matrix, input, key_base);
        dechiffre_102(text_matrix, key_matrix, lib);
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
        return (0);
      } else if (user_choise2 == 1) {
        // il n'y a rien dans ce if de façon à faire un tour de boucle supplémentaire
      } else if (user_choise2 == 2) {
        break; // sortie de la première boucle pour retourner dans la boucle de la fonction
      }
    }
  }
  return (0);
}

void  user_input_to_matrix_base(MatrixXd & text_matrix, string & input, string & base) {
  int a = 0;
  int b;
  int i = 0;
  int words = 0;
  
  while (input[i] != '\0') {
    if (input[i] == ' ') {
      words++;
    }
    i++;
  }
  i = 0;
  resize_matrix(text_matrix, words);
  matrix_initialisator(text_matrix);
  while (a < text_matrix.cols()) {
    b = 0;
    while (b < text_matrix.rows()) {
      text_matrix(b,a) = my_getnbr_base(input, base, i);
      while (input[i] != ' ' && input[i] != '\0') {
        i++;
      }
      if (input[i] != '\0') {
        i++;
      }
      b++;
    }
    a++;
  }
}

void  dechiffre_102(MatrixXd & text_matrix, MatrixXd & key_matrix, const char * lib) {
  MatrixXd tmp = key_matrix.inverse() * text_matrix;
  int a = 0;
  int b;

  c_str("\nVotre texte déchiffré :\n", 'b');
  cout << "\033[1;31m" << endl;
  while (a < tmp.cols()) {
    b = 0;
    while (b < tmp.rows()) {
      cout << lib[(int)round(tmp(b,a))]; // la fonction round() est utilisée avant le cast pour éviter les pertes de données liées à celui-ci
      b++;
    }
    a++;
  }
  cout << "\033[0;0m" << endl << endl;
}

void  chiffre_102(MatrixXd & text_matrix, MatrixXd & key_matrix, string & base) {
  MatrixXd output;
  int a = 0;
  int b;
  int space = 1;
  
  c_str("\nVotre texte chiffré :\n", 'b');
  cout << "\033[1;31m" << endl;
  output = key_matrix * text_matrix;
  while (a < output.cols()) {
    b = 0;
    while (b < output.rows()) {
      if (space == 1) {
        space = 0;
      } else {
        cout << " ";
      }
      my_put_nbr_base(output(b,a), base);        
      b++;
    }
    a++;
  }
  cout << "\033[0;0m" << endl << endl;
}
