#ifndef BRICK_HPP_
#define BRICK_HPP_

#include <string>

class Brick {
  protected :
    const char * _lib;
    int _lib_size;
  public :
   enum identity {
	C,
	V,
	V3D,
	_102,
	_10X,
	D,
	SD
   };
   void get_lib(int lib);
   virtual void present() = 0;
   virtual void get_key() = 0;
   virtual identity who() = 0;
   virtual std::string chiffre(std::string & input) = 0;
   virtual std::string dechiffre(std::string & input) = 0;
   Brick();
   virtual ~Brick();
};

#endif