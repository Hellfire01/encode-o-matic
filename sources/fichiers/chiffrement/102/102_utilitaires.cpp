#include "function_prototypes.h"
#include "utilitaires.h"

using namespace::std;

int key_validator_102_base(string key, const string lib) {
  int i = 0;
  int a;
  
  while (key[i] != '\0') {
    if (key[i] == ' ') {
      c_str("Erreur :\n", 'r');
      cout << "les espaces ne peuvent pas faire partit de la base" << endl;
      return (1);
    }
    if (key[i] == '-') {
      c_str("Erreur :\n", 'r');
      cout << "il ne peut y avoir de signe '-' ==> il est utilisé de base pour gérer les négatifs" << endl;
      return (1);
    }
    a = i;
    if (my_isin(key[a], lib) == -1) {
      cout << "Tous les caractères doivent faire partit de la table ascii" << endl;
      cout << "'" << key[i] << "' n'en fait pas partit" << endl;
      return (1);
    }
    while (key[a + 1] != '\0') {
      if (key[i] == key[a + 1]) {
        cout << "Cette clef est invalide : il ne peut y avoir deux fois le même caractère" << endl;
        cout << "Ici, '" << key[i] << "' est présent deux fois" << endl;
        return (1);
      }
      a++;
    }
    i++;
  }
  return (0);
}

int input_validator(string str, const string lib) {
  int i = 0;
  
  while (str[i] != '\0') {
    if (my_isin(str[i], lib) == -1) {
      c_str("Erreur :\n", 'r');
      cout << "Vous ne pouvez pas utiliser le caractère suivant : '" << str[i] << "' car il ne fait pas partit de l'alphabet utilisé" << endl;
      return (1);
    }
    i++;
  }
  return (0);
}
