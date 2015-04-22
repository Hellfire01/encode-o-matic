#include "function_prototypes.h"

void  no_tabs(char * str) {
   int i = 0;
   
   while (str[i] != '\0') {
      if (str[i] == '\t') {
         str[i] = ' ';
      }
      i++;
   }
}

int   no_spaces_duplicates(char * str) {
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

void  no_space_in_begining(char * str) {
   int i = 0;
   
   if (str[0] == ' ') {
      while (str[i] != '\0') {
         str[i] = str[i + 1];
         i++;
      }
   }
}

void  no_space_in_end(char * str) {
   int i = 0;
   
   while (str[i + 1] != '\0') {
      i++;
   }
   if (str[i] == ' ') {
      str[i] = '\0';
   }
}

void  epur_str(char * str) {
   int ret = 1;
   
   no_tabs(str);
   while (ret == 1) {
      ret = no_spaces_duplicates(str);
   }
   no_space_in_begining(str);
   no_space_in_end(str);
}