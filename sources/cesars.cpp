#include <stdio.h>
#include <string.h>
#include <iostream>
#include "function_prototypes.h"

/* ce fichier regroupe toutes les fonctions centrées autours du Césars */

using namespace std;

int cesars_user_choises () {
  int user_choise;
  while (42) {
    cout << "Vous avez choisit d'utiliser le Césars" << endl;
    cout << "Souhaitez vous : " << endl;
    cout << "\033[1;36m-1\033[0;0m : retourner au menu précédent" << endl;
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
        cesars_choises(1);
        break;
      case 2 :
        cesars_choises(2);
        break;
      default :
        cout << "hum, c'est embarassant : le choix reçu est : \"" << user_choise << "\" celà n'aurait pas dut être possible" << endl;
        cout << "retour au menu précédent" << endl;
        return 0;
    }
  }
  return 0;
}

int cesars_choises (int choise) {
  int key;
  int tmp;
  int lib_size;
  int user_choise2;
  const char* lib;
  char* input;
  while (42) { // l'utilisateur souhaite continuer à chiffrer en Césars
    cout << "Vous avez choisit d'utiliser le Césars" << endl;
    if (choise == 1) {
      cout << "Veuiller choisir quels seront les caractères qui seront chiffrés ( dans tous les cas, l'espace est chiffré aussi ) :" << endl;
      cout << "\033[1;33mNote\033[0;0m : il faudra faire le même choix pour déchiffrer correctement" << endl;
    } else {
      cout << "Veuillez indiquer quelle est l'alphabet qui fut utilisé pour le chiffrement" << endl;
    }
    cout << "\033[1;36m-1\033[0;0m : retourner au menu précédent" << endl;
    cout << "\033[1;36m1\033[0;0m : alphabet minuscule"<< endl;
    cout << "\033[1;36m2\033[0;0m : alphabet minuscule et majuscule"<< endl;
    cout << "\033[1;36m3\033[0;0m : alphabet minuscule, majuscule et chiffres" << endl;
    cout << "\033[1;36m4\033[0;0m : la totale ( presque tout le clavier AZERTY )" << endl;
    if (choise == 1) {
      cout << "Si vous souhaitez utiliser le Césars classique ( sans espaces ), choisissez l'une des deux options suivantes :" << endl;
    } else {
      cout << "Dans le cas d'un chiffrement via un Césars classique ( pas d'espaces ), choisissez l'un de ces deux alphabets :" << endl;
    }
    cout << "\033[1;36m5\033[0;0m : alphabet minuscule" << endl;
    cout << "\033[1;36m6\033[0;0m : alphabet majuscule" << endl;
    tmp = user_input();
    while (tmp < -1 || tmp == 0 || tmp > 6) {
      cout << "Ce choix n'est pas disponible" << endl;
      tmp = user_input();
    }
    cout << endl;
    if (tmp == -1) {
      return (0);
    }
    lib = lib_choise(tmp);
    lib_size = strlen(lib);
    if (choise == 1) {
      cout << "Veuillez choisir une clef de chiffrement ( un nombre différent de 0 )" << endl;
    } else {
      cout << "Veuillez écrire la clef utilisée pour le chiffrement" << endl;
    }
    key = user_input();
    while (key <= 0 || key % (lib_size / 2) == 0) {
      if (key < 0) {
        cout << "pas de clefs négatives svp ( le césars ne s'utilise qu'avec des nombres entiers positifs )" << endl;
      } else {
        cout << "la valeur de la clef est de : " << key << " % (" << lib_size << " / 2) = 0" << endl;
        if (choise == 1) {
          cout << "Le choix d'une clef en 0 est inutile car cela revient à ne rien chiffrer du tout" << endl;
          cout << "Veuillez choisir une clef valide ( ou utilisez votre texte en clair )" << endl;
        } else {
          cout << "Cette clef n'a pas put être utilisée pour le chiffrement car le texte serait alors en clair" << endl;
          cout << "( et dans quel cas il n'y a pas besoin de passer par ce programme pour le déchiffrer )" << endl;
        }
      }
      key = user_input();
    }
    cout << endl;
    while (42) {
      if (choise == 1) {
        cout << "Veuillez écrire le texte que vous souhaitez chiffrer" << endl;
      } else {
        cout << "Veuillez écrire le texte que vous souhaitez déchiffrer" << endl;
      }
      input = user_text();
      if (choise == 1) {
        chiffre_cesars(input, lib, lib_size, key);
      } else {
        dechiffre_cesars(input, lib, lib_size, key);
      }
      cout << "Que souhaitez vous faire maintenant ?" << endl;
      cout << "\033[1;36m-1\033[0;0m : retourner au menu précédent" << endl;
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
        delete[] input;
        return (0);
      } else if (user_choise2 == 1) {
        delete[] input;
        // il n'y a rien dans ce if de façon à faire un tour de boucle supplémentaire
      } else if (user_choise2 == 2) {
        delete[] input;
        break; // sortie de la première boucle pour retourner dans la boucle de la fonction
      }
    }
  }
  delete[] input;
  return (0);
}

void chiffre_cesars (char const * input, const char* lib, int lib_size, int key) {
  int tmp = 0;
  int i = 0;
  int input_size = strlen(input);
  cout << endl << "Votre texte chiffré :\033[1;35m" << endl;
  while (i <= input_size) {
    if ((tmp = my_isin2(input[i], lib)) >= 0) {
      tmp += (key % lib_size);
      tmp %= lib_size;
      cout << lib[tmp];
    } else {
      cout << input[i];
    }
    i++;
  }
  cout << "\033[0;0m" << endl << endl << endl;
}

void dechiffre_cesars (char const * input, const char* lib, int lib_size, int key) {
  int tmp = 0;
  int i = 0;
  int input_size = strlen(input);
  cout << endl << "votre texte clair ( si vous avez fait la bonne combinaison ) :\033[1;35m" << endl;
  while (i <= input_size) {
    if ((tmp = my_isin2(input[i], lib)) >= 0) {
      tmp += lib_size - key % lib_size;
      tmp %= lib_size;
      cout << lib[tmp];
    } else {
      cout << input[i];
    }
    i++;
  }
  cout << "\033[0;0m" << endl << endl << endl;
}