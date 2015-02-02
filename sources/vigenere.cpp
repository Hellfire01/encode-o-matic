#include <stdio.h>
#include <string.h>
#include <iostream>
#include "function_prototypes.h"

/* ce fichier regroupe toutes les fonctions centrées autours du Césars */

using namespace std;

int vigenere_user_choises () { // il faut considérer passer cette fonction en void ( le retour est toujours le même )
  int user_choise;
  while (42) {
    cout << "Vous avez choisit d'utiliser le Vigenère" << endl;
    cout << "Souhaitez vous : " << endl;
    cout << "\033[1;36m-1\033[0;0m : retourner au menu précédent" << endl;
    cout << "\033[1;36m1\033[0;0m : chiffrer" << endl;
    cout << "\033[1;36m2\033[0;0m : déchiffrer" << endl;
    user_choise = user_input();
    while (user_choise == 0 || user_choise < -1 || user_choise > 2) {
      cout << "le nombre saisi : '" << user_choise << "' ne correspond pas à un des choix du menu" << endl;
      user_choise = user_input();
    }
    switch (user_choise) {
      case -1 :
        cout << "retour au menu précédent" << endl;
        return 0;
      case 1 :
        vigenere_choises(1);
        break;
      case 2 :
        vigenere_choises(2);
        break;
      default :
        cout << "hum, c'est embarassant : le choix reçu est : \"" << user_choise << "\" celà n'aurait pas dut être possible" << endl;
        cout << "retour au menu précédent" << endl;
        return 0;
    }
  }
  return 0;
}

int vigenere_choises (int choise) {
  int tmp;
  int lib_size;
  int user_choise2;
  char* key;
  const char* lib;
  char* input;
  while (42) { // l'utilisateur souhaite continuer à chiffrer en Vigenère
    cout << "Vous avez choisit d'utiliser Vigenère" << endl;
    if (choise == 1) {
      cout << "Veuiller choisir quels seront les caractères qui seront chiffrés ( dans tous les cas, l'espace est chiffré aussi ) :" << endl;
      cout << "\033[1;33mNote\033[0;0m : il faudra faire le même choix pour déchiffrer correctement" << endl;
      cout << "\033[1;33mNote\033[0;0m : chaque caractère de votre clef devra être présente dans cet alphabet" << endl;
    } else {
      cout << "Veuillez indiquer quelle est l'alphabet qui fut utilisé pour le chiffrement" << endl;
    }
    cout << "\033[1;36m-1\033[0;0m : retourner au menu précédent" << endl;
    cout << "\033[1;36m1\033[0;0m : alphabet minuscule"<< endl;
    cout << "\033[1;36m2\033[0;0m : alphabet minuscule et majuscule"<< endl;
    cout << "\033[1;36m3\033[0;0m : alphabet minuscule, majuscule et chiffres" << endl;
    cout << "\033[1;36m4\033[0;0m : la totale ( presque tout le clavier AZERTY )" << endl;
    if (choise == 1) {
      cout << "Si vous souhaitez utiliser le Vigenère classique ( sans espaces ), choisissez l'une des deux options suivantes :" << endl;
    } else {
      cout << "Dans le cas d'un chiffrement via un Vigenère classique ( pas d'espaces ), choisissez l'un de ces deux alphabets :" << endl;
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
      cout << "Veuillez choisir une clef de chiffrement ( des caractères présents dans l'alphabet choisit )" << endl;
      cout << "\033[1;33mNote\033[0;0m : le plus la clef sera longue et le plus elle comportera de caractères différents, le plus elle sera efficace" << endl;
    } else {
      cout << "Veuillez écrire la clef qui fut utilisée pour le chiffrement" << endl;
    }
    key = user_text();
    while (key_check(key, lib) == 1) {
      key = user_text();
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
        cout << endl << "Votre texte chiffré : " << endl;
        chiffre_vigenere(input, lib, lib_size, key);
      } else {
        cout << endl << "Votre texte déchiffré : " << endl;
        dechiffre_vigenere(input, lib, lib_size, key);
      }
      cout << endl << endl;
      cout << "Que souhaitez vous faire maintenant ?" << endl;
      cout << "\033[1;36m-1\033[0;0m : retourner au menu précédent" << endl;
      if (choise == 1) {
        cout << "\033[1;36m1\033[0;0m : chiffrer avec la même combinaison de clef / alphabet" << endl;
      } else {
        cout << "\033[1;36m1\033[0;0m : dechiffrer avec la même combinaison de clef / alphabet" << endl;
      }
      cout << "\033[1;36m2\033[0;0m : changer de clef" << endl;
      user_choise2 = user_input();
      while (user_choise2 < -1 || user_choise2 == 0 || user_choise2 > 2) {
        cout << "Ce choix n'est pas disponible" << endl;
        user_choise2 = user_input();
      }
      cout << endl;
      if (user_choise2 == -1) {
        delete[] input;
        delete[] key;
        return (0);
      } else if (user_choise2 == 1) {
        delete[] input; // l'utilisateur souhaite conserver la clef mais chiffrer autre chose
        // il n'y a rien dans ce if de façon à faire un tour de boucle supplémentaire
      } else if (user_choise2 == 2) {
        delete[] input; // l'utilisateur souhaite continuer à utiliser le Vigenère
        delete[] key;
        break; // sortie de la première boucle pour retourner dans le while 42 principal
      }
    }
  }
  delete[] input;
  delete[] key;
  return (0);
}

int key_check(char * &key, const char * &lib) { // cette fonction vient vérifier que la clef est correcte ( plus de 3 caractères différents )
  int i = 0;
  int length = strlen(key) - 1; // le but est de ne pas aussi prendre le '\n' qui est un caractère
  if (length <= 1) { // on prend ici en compte le -1 précédent
    cout << "erreur :" << endl;
    cout << "le clef est trop courte : elle doit comporter au moins 3 caractères ( différents )" << endl;
    return (1);
  }
  // tous les caractères de la clef doivent faire partit de l'alphabet choisit
  while (i <= length) {
    if (my_isin(key[i], lib) == 0) {
      cout << "erreur :" << endl;
      cout << "Cette clef n'est pas valide : '" << key[i] << "' ne fait pas partit de l'alphabet choisit" << endl;
      return (1);
    }
    i++;
  }
  return (0);
}

void chiffre_vigenere(char * &text, char const * &lib, int lib_size, char * &key) {  
  int	i_key = 0; // variable utilisée pour la clef
  int	i_text = 0; // variable utilisée pour le texte
  int	tmp = 0; // variable temporaire pour stoquer le résultat d'un chiffrement ( et rendre les calculs lisibles )
  while (text[i_text] != '\0') { // on s'assure ici que tout le texte est chiffré
    if ((tmp = my_isin2(text[i_text], lib)) >= 0) { // chiffrement si le caractère est dans l'alphabet choisi
      tmp += my_isin2(key[i_key], lib);
      tmp %= lib_size;
      cout << lib[tmp];
    } else { // pas de chiffrement ici
      cout << text[i_text];
      i_key -= 1;
    }
    i_text += 1;
    if (key[i_key + 1] == '\0') {
      i_key = -1; // vient annuler l'adition qui suit
    }
    i_key += 1;
  }
}

void dechiffre_vigenere(char * &text, char const * &lib, int lib_size, char * &key) {
  int i_key = 0;
  int i_text = 0;
  int tmp = 0;
  int tmpK = 0;
  while (text[i_text] != '\0') {
    tmp = my_isin2(text[i_text], lib);
    tmpK = my_isin2(key[i_key], lib);
    if ((tmpK > tmp) && tmp >= 0) {
      tmp = lib_size - tmpK + tmp;
      tmp %= lib_size;
      cout << lib[tmp];
    } else if (tmp >= 0) {
      tmp -= tmpK;
      cout << lib[tmp];
    } else {
      cout << text[i_text];
      i_key = i_key - 1;
    }
    if (key[i_key +1] == '\0') {
      i_key = -1;
    }
    i_text = i_text + 1;
    i_key = i_key + 1;
  }
}