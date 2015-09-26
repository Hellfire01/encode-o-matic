#ifndef VIGENERE_HPP_
#define VIGENERE_HPP_

#include <string>
#include <sstream>

#include "Brick.hpp"

class Vigenere : public Brick {
public :
   enum Check_Vigenere {
      BAD_CARACTER = 1,
      BAD_LENGTH = 2,
      BAD_STRENGTH = 3,
      GOOD = 4
   };
 private :
      std::string _key;
      char _carac_error;
 public :
      Vigenere();
      ~Vigenere();
      void present();
      void get_key();
      char error_c();
      Brick::identity who();
      Check_Vigenere v_set_key(std::string & key);
      std::string chiffre(std::string & input);
      std::string dechiffre(std::string & input);
};

#endif /* !VIGENERE_HPP_ */