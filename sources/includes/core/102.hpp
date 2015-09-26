#ifndef _102_HPP_
#define _102_HPP_

#include <string>
#include <Eigen/Dense>
#include "Brick.hpp"

using Eigen::MatrixXd;

class _102 : public Brick{
  public :
   enum Check_102_key {
      BAD_CARACTER = 1,
      NOT_ENOUGH_NUMBERS = 2,
      NO_0 = 3,
      INPUT_ERROR = 4,
      GOOD = 5
   };   
   enum Check_102_base {
      DUPLICATE = 1,
      NO_NEG = 2,
      BAD_CARAC = 3,
      NO_SPACE = 4,
      OK = 5
   };
  private :
   char bad_caracter;
   bool key_check;
   std::string base;
   MatrixXd key_matrix;
   MatrixXd text_matrix;
   
int key_validator_102_base(std::string key, const std::string lib);
int input_validator(std::string str, const std::string lib);

   int                 numbers_only(std::string & input);
   int                 fast_check(std::string & input);
int write_matrix(MatrixXd & out, std::string tmp);
int last_check(MatrixXd & out);
void matrix_input_102(MatrixXd & out);
   int                 write_matrix(std::string tmp);
   int                 last_check();
   void		       user_input_to_matrix_base(std::string & input);
   Check_102_key	key_input(std::string & input);
   Check_102_base	base_input(std::string & input);
   char			bad_carac();
   char			input_validator(std::string & input);
  public :
   std::string		dechiffre(std::string & input);
   std::string		chiffre(std::string & input);
   virtual void present();
   virtual void get_key();
   virtual Brick::identity who();
   _102();
   ~_102();
};

#endif /* !_102_HPP_ */