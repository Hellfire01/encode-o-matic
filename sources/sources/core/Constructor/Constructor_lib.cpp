#include <stdlib.h>
#include "Constructor.hpp"
#include "utilitaires.h"

bool Constructor::confirm_lib() {
   int i = 0;
   int size = _list.size();
   Brick::identity tmp;

   while (i < size) {
      tmp = _list[i]->who();
      if (tmp == Brick::_102 || tmp == Brick::_10X) {
         return false;
      }
      i++;
   }
   return true;
}

bool Constructor::get_lib(int lib) {
   _lib = lib;
   if (confirm_lib() == false) {
	_lib = 4;
        set_lib();
        _status_lib = true;
	return false;
   }
   set_lib();
   _status_lib = true;
   return true;
}

void Constructor::set_lib() {
   int i = 0;
   int size = _list.size();
   
   while (i < size) {
      _list[i]->get_lib(_lib);
      i++;
   }
}
