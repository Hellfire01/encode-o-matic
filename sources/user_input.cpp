#include <string>
#include <iostream>
#include <sstream>
#include "function_prototypes.h"

using namespace std;

int user_input() {
  string line;
  int i;
  cout << "\033[1;34m";
  while (getline(cin, line)) {
    stringstream ss(line);
    if (ss >> i) {
      if (ss.eof()) {   // Success
          break;
      }
    }
    cout << "\033[0;0mincorrect input : numbers only please\033[1;34m" << endl;
  }
  cout << "\033[0;0m";
  return (i);
}

char* user_text() {
  string *line = new string;
  cout << "\033[1;34m";
  getline(cin, (*line));
  cout << "\033[0;0m";
  char * out = new char[(*line).length() + 1];
  strcpy(out, (*line).c_str());
  delete line;
  return (out);
}
