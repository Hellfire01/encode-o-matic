#ifndef CONSTRUCTOR_HPP_
#define CONSTRUCTOR_HPP_

#include <vector>
#include "Brick.hpp"

/*
 * Warning !
 * if ever the 102 or 10X are used, lib will be set to 4 autonaticaly
 * once the lib is set, you cannot add anymore Bricks
 * you can reset the lib if you empty the list ( empty_list() )
 *
 * How to use the constructor :
 * 1) set the bricks in the wanted order ( add_to_list() )
 * 2 - 3) set the keys ( get_keys() ) and the lib ( get_lib() )
 * Warning !!!
 * doing step 2/3 will will prevent you from adding any more Bricks
 * 4) chiffe() / dechiffre()
 * Note :
 * the input is always checked unless false is sent
 * Warning !!!
 * Only use it when sure all the caracters are in the lib else the
 * outcome will be unpredictable
 */

class Constructor {
  private :
    int _lib;
    bool _status_lib;
    bool _status_keys;
    std::vector<Brick *> _list;
    bool confirm_lib();
    void set_lib();
  public :
   void empty_list();
   bool add_to_list(Brick * brk);
   void get_keys();
   void present();
   bool get_lib(int lib);
   bool status(bool verbose = false);
   std::string * chiffre(std::string const & input, bool check = true);
   std::string * dechiffre(std::string const & input, bool check = true);
   Constructor();
   ~Constructor();
};

#endif