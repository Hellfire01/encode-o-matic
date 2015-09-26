#include "utilitaires.h"

template void no_tabs<char *>(char * str);
template void no_tabs<std::string &>(std::string & str);

template int no_spaces_duplicates<char *>(char * str);
template int no_spaces_duplicates<std::string &>(std::string & str);

template void no_space_in_begining<char *>(char * str);
template void no_space_in_begining<std::string &>(std::string & str);

template void no_space_in_end<char *>(char * str);
template void no_space_in_end<std::string &>(std::string & str);

template void epur_str<char *>(char * str);
template void epur_str<std::string>(std::string str);
template void epur_str<std::string &>(std::string & str);

template <typename T>
void  no_tabs(T str) {
   int i = 0;
   
   while (str[i] != '\0') {
      if (str[i] == '\t') {
         str[i] = ' ';
      }
      i++;
   }
}

template <typename T>
int   no_spaces_duplicates(T str) {
   int i = 0;
   
   while (str[i + 1] != '\0') {
      if (str[i] == ' ' && str[i + 1] == ' ') {
         while (str[i] != '\0') {
            str[i] = str[i + 1];
            i++;
         }
         return (1);
      }
      i++;
   }
   return (0);
}

template <typename T>
void  no_space_in_begining(T str) {
   int i = 0;
   
   if (str[0] == ' ') {
      while (str[i] != '\0') {
         str[i] = str[i + 1];
         i++;
      }
   }
}

template <typename T>
void  no_space_in_end(T str) {
   int i = 0;
   
   while (str[i + 1] != '\0') {
      i++;
   }
   if (str[i] == ' ') {
      str[i] = '\0';
   }
}

template <typename T>
void  epur_str(T str) {
   int ret = 1;
   
   no_tabs(str);
   while (ret == 1) {
      ret = no_spaces_duplicates(str);
   }
   no_space_in_begining(str);
   no_space_in_end(str);
}
