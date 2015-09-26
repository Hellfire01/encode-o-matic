#include <iostream>

const char* lib_choice(int lib) {

   switch (lib) {
      case 1:
         return ("abcdefghijklmnopqrstuvwxyz ");
      case 2:
         return ("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ");
      case 3:
         return ("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ");
      case 4:
         return ("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 !\"#$%&'()*+,-./[\\]^_`{<|=}>~?");
      case 5:
         return ("abcdefghijklmnopqrstuvwxyz");
      case 6:
         return ("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
      case 7:
         // alpha de debug ==> utilisé dans une soucis de compatibilité avec d'autres méthodes ( où ' ' = 0 )
         // il poosède un espace au début 
         return (" abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");
      default :
         return (NULL);
  }
  return (NULL);
}
