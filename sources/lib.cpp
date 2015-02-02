#include <iostream>

const char* lib_choise(int lib) {
  switch (lib) {
//    case 1:
//
//      return ("abcdefghijklmnopqrstuvwxyz abcdefghijklmnopqrstuvwxyz ");
//    case 2:
//      return ("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ");
//    case 3:
//      return ("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ");
//    case 4:
//      return ("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.+-*/!:;,§/.?*µ%$^£¨=)àç_è-('\"é&¹#{[|`\\^]}<>² abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.+-*/!:;,§/.?*µ%$^£¨=)àç_è-('\"é&¹#{[|`\\^]}<>² ");
//    case 5:
//      return ("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");
//    case 6:
//      return ("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    case 1:
      return ("abcdefghijklmnopqrstuvwxyz ");
    case 2:
      return ("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ");
    case 3:
      return ("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ");
    case 4:
      return ("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.+-*/!:;,§/.?*µ%$^£¨=)àç_è-('\"é&¹#{[|`\\^]}<>² ");
    case 5:
      return ("abcdefghijklmnopqrstuvwxyz");
    case 6:
      return ("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    default :
      return (NULL);
  }
  return (NULL);
}