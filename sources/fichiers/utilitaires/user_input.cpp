#include "function_prototypes.h"
#include "utilitaires.h"

using namespace std;

int user_input() {
  char * tmp;
  int i;
  int a;
  int lock = 0;
  
  while (42) {
    a = 0;
    tmp = user_text();
    epur_str(tmp);
    while (tmp[a] != '\0') {
      if (my_isin(tmp[a], "-0123456789") == -1) {
        c_str("Que des nombres svp\n", 'r');
        delete [] tmp;
        lock = 1;
        break ;
      }
      a++;
    }
    if (lock == 0) {
      i = atoi(tmp);
      delete [] tmp;
      return (i);
    }
    lock = 0;
  }
}

char* user_text() {
  string * line = new string;
  
  cout << endl << "\033[1;34m";
  getline(cin, (*line));
  cout << "\033[0;0m";
  char * out = new char[(*line).length() + 1];
  strcpy(out, (*line).c_str());
  delete line;
  return (out);
}

void user_string(string & in) {
  cout << endl << "\033[1;34m";
  getline(cin, in);
  cout << "\033[0;0m";
}