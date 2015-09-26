#include <sstream>
#include "Brick.hpp"

enum Check_Cesars {
    BAD_VALUE = 1,
    BAD_MODULO = 2,
    GOOD = 3
};

class Cesars : public Brick {
  private :
    int _key;
  public :
    Cesars();
    ~Cesars();
    void present();
    void get_key();
    Brick::identity who();
    void get_lib(int lib);
    Check_Cesars key_check(int key);
    std::string chiffre(std::string & input);
    std::string dechiffre(std::string & input);
};