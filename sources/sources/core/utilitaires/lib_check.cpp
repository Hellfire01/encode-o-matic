#include "utilitaires.h"

char lib_char_check(int libi, std::string const & input) {
   int i = 0;
   int size = input.size();
   const char * lib = lib_choice(libi);

   while ( i < size) {
	if (my_isin(input[i], lib) == -1) {
	   return input[i];
	}
	i++;
   }
   return '\0';
}

bool lib_bool_check(int libi, std::string const & input) {
   int i = 0;
   int size = input.size();
   const char * lib = lib_choice(libi);

   while ( i < size) {
	if (my_isin(input[i], lib) == -1) {
	   return false;
	}
	i++;
   }
   return true;
}