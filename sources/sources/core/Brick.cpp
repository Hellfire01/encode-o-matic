#include <string.h>
#include "Brick.hpp"
#include "utilitaires.h"

Brick::Brick() {

}

Brick::~Brick() {
   
}

void Brick::get_lib(int lib) {
    _lib = lib_choice(lib);
    _lib_size = strlen(_lib);
}
