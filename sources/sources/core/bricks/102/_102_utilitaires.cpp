#include <iostream>
#include "term_prototypes.h"
#include "utilitaires.h"
#include "102.hpp"

int _102::key_validator_102_base(std::string key, const std::string lib) {
  int i = 0;
  int a;
  
  while (key[i] != '\0') {
    if (key[i] == ' ') {
      c_str((char*)"Erreur :\n", 'r');
      std::cout << "les espaces ne peuvent pas faire partit de la base" << std::endl;
      return (1);
    }
    if (key[i] == '-') {
      c_str((char*)"Erreur :\n", 'r');
      std::cout << "il ne peut y avoir de signe '-' ==> il est utilisé de base pour gérer les négatifs" << std::endl;
      return (1);
    }
    a = i;
    if (my_isin<const std::string &>(key[a], lib) == -1) {
      std::cout << "Tous les caractères doivent faire partit de la table ascii" << std::endl;
      std::cout << "'" << key[i] << "' n'en fait pas partit" << std::endl;
      return (1);
    }
    while (key[a + 1] != '\0') {
      if (key[i] == key[a + 1]) {
        std::cout << "Cette clef est invalide : il ne peut y avoir deux fois le même caractère" << std::endl;
        std::cout << "Ici, '" << key[i] << "' est présent deux fois" << std::endl;
        return (1);
      }
      a++;
    }
    i++;
  }
  return (0);
}

int _102::input_validator(std::string str, const std::string lib) {
  int i = 0;
  
  while (str[i] != '\0') {
    if (my_isin<const std::string &>(str[i], lib) == -1) {
      c_str((char*)"Erreur :\n", 'r');
      std::cout << "Vous ne pouvez pas utiliser le caractère suivant : '" << str[i] << "' car il ne fait pas partit de l'alphabet utilisé" << std::endl;
      return (1);
    }
    i++;
  }
  return (0);
}
