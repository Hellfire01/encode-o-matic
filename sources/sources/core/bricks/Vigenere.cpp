#include <string.h>
#include "utilitaires.h"
#include "Vigenere.hpp"
#include <iostream>

Vigenere::Vigenere() {

}

Vigenere::~Vigenere() {

}

char Vigenere::error_c() {
    return _carac_error;
}

Brick::identity Vigenere::who() {
    return Brick::V;
}

void Vigenere::present() {
    std::cout << "Le Vigenere est une méthode de chiffrement se basant sur un décalage polyalphabétique" << std::endl;
    std::cout << "Toutes les lettres seront décalées de la valeur choisie ( lettre de clef ) dans l'alphabet choisit" << std::endl;
    std::cout << "Il s'agit plus ou moins d'un usage d'autant de Césars avec des valeurs différentes qu'il y a de" << std::endl;
    std::cout << "lettres dans la clef" << std::endl;
}

void Vigenere::get_key() {
    std::string key;
    Check_Vigenere ret;

    std::cout << "Clef pour le Vigenere ( des caractères présents dans l'alphabet choisit )" << std::endl;
    std::cout << "\033[1;33mNote\033[0;0m : le plus la clef sera longue et le plus elle comportera de caractères différents, le plus elle sera efficace" << std::endl;
    user_string(key);
    while ((ret = v_set_key(key)) != Vigenere::GOOD) {
      switch (ret) {
	case Vigenere::BAD_CARACTER :
	  c_str((char*)"Erreur : ", 'r');
	  std::cout << "le caractère '" << error_c() << "' ne fait pas partit de l'alphabet choisit" << std::endl;
	  break;
	case Vigenere::BAD_LENGTH :
	  c_str((char*)"Erreur : ", 'r');
	  std::cout << "la clef doit faire plus de 3 caractères différents" << std::endl;
	  break;
	case Vigenere::BAD_STRENGTH :
	  c_str((char*)"Erreur : ", 'r');
	  std::cout << "la clef doit avoir 3 caractères ou plus différents" << std::endl;	  
	  break;
	default :
	  c_str((char*)"Erreur : ", 'r');
	  std::cout << "le retour '" << ret << "' n'aurait pas dut être possible" << std::endl;
	  return ;
      }
      user_string(key);
      ret = v_set_key(key);
    }
    std::cout << std::endl;
}

Vigenere::Check_Vigenere Vigenere::v_set_key(std::string & key) {
    char carac1;
    char carac2 = '\0';
    char carac3 = '\0';
    int i = 0;
    int length = key.size();
    
    if (key[length] == '\0') {
	length -= 1;
    }
    if (key[length] == '\n') {
	length -= 1;
    }
    if (length <= 3) {
	return BAD_LENGTH;
    }
    // tous les caractères de la clef doivent faire partit de l'alphabet choisit
    while (i <= length) {
	if (my_isin(key[i], _lib) == -1) {
	    _carac_error = key[i];
	    return BAD_CARACTER;
	}
	i++;
    }
    i = 1;
    carac1 = key[0];
    if (key[1] != key[0]) {
	carac2 = key[1];
    } else {
	while (i < length) {
	    if (key[i] != carac1 && key[i] != '\0') {
		carac2 = key[i];
		break;
	    }
	    i++;
	}
	if (carac2 == '\0') {
	    return BAD_STRENGTH;
	}
    }
    i = 1;
    while (i < length) {
	if (key[i] != carac1 && key[i] != carac2 && key[i] != '\0') {
	    carac3 = key[i];
	    break;
	}
	i++;
    }
    if (carac3 == '\0') {
	return BAD_STRENGTH;
    }
    _key = key;
    return GOOD;
}

std::string Vigenere::chiffre(std::string & input) {  
  std::stringstream out;
  int	i_key = 0; // variable utilisée pour la clef
  int	i_text = 0; // variable utilisée pour le texte
  int	tmp = 0; // variable temporaire pour stocker le résultat d'un chiffrement ( et rendre les calculs lisibles )
  
  while (input[i_text] != '\0') { // on s'assure ici que tout le texte est chiffré
    if ((tmp = my_isin(input[i_text], _lib)) >= 0) { // chiffrement si le caractère est dans l'alphabet choisi
      tmp += my_isin(_key[i_key], _lib);
      tmp %= _lib_size;
      out << _lib[tmp];
    } else { // pas de chiffrement ici
      out << input[i_text];
      i_key -= 1;
    }
    i_text += 1;
    if (_key[i_key + 1] == '\0') {
      i_key = -1; // vient annuler l'addition qui suit
    }
    i_key += 1;
  }
  return out.str();
}

std::string Vigenere::dechiffre(std::string & input) {
  std::stringstream out;
  int i_key = 0;
  int i_text = 0;
  int tmp = 0;
  int tmpK = 0;
  
  while (input[i_text] != '\0') {
    tmp = my_isin(input[i_text], _lib);
    tmpK = my_isin(_key[i_key], _lib);
    if ((tmpK > tmp) && tmp >= 0) {
      tmp = _lib_size - tmpK + tmp;
      tmp %= _lib_size;
      out << _lib[tmp];
    } else if (tmp >= 0) {
      tmp -= tmpK;
      out << _lib[tmp];
    } else {
      out << input[i_text];
      i_key = i_key - 1;
    }
    if (_key[i_key +1] == '\0') {
      i_key = -1;
    }
    i_text = i_text + 1;
    i_key = i_key + 1;
  }
  return out.str();
}