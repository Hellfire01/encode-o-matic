#include <stdlib.h>
#include "Constructor.hpp"
#include "utilitaires.h"

Constructor::Constructor() {
   _status_keys = false;
   _status_lib = false;
}

Constructor::~Constructor() {
}


bool Constructor::add_to_list(Brick * brk) {
   if (_status_keys == true)  { // les clefs ont été rentrée, plus d'entrée autorisée
      return false;
   }
   if (_status_lib == true) { // la lib ne doit être choisie que quand toutes les briques dans la liste
      return false;
   }
   _list.push_back(brk);
   return true;
}

void Constructor::get_keys() {
   int i = 0;
   int size = _list.size();

   if (_list.size() != 0) {
      while (i < size) {
         _list[i]->get_key();
         i++;
      }
      _status_keys = true;
   }
}

std::string * Constructor::chiffre(std::string const & input, bool check) {
   std::string * buffer = new std::string(input);
   int i = 0;
   int size = _list.size();

   if (check == true) {
      if (_status_lib == false || _status_keys == false || lib_bool_check(_lib, input) == false) {
         buffer->clear();
         return buffer;
      }
   }
   while (i < size) {
      *buffer = _list[i]->chiffre(*buffer);
      i++;
   }
   return buffer;
}

std::string * Constructor::dechiffre(std::string const & input, bool check) {
   std::string * buffer = new std::string(input);
   int i = _list.size();
   
   if (check == true) {
      if (_status_lib == false || _status_keys == false || lib_bool_check(_lib, input) == false) {
         buffer->clear();
         return buffer;
      }
   }
   while (i > 0) {
      *buffer = _list[i - 1]->dechiffre(*buffer);
      i--;
   }
   return buffer;   
}

void Constructor::empty_list() {
   int i = 0;
   int size = _list.size();
   
   while (i < size) {
      delete _list[i];
      i++;
   }
   _list.empty();
   _status_keys = false;
   _status_lib = false;
}
