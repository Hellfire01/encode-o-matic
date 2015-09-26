#include <iostream>
#include "Constructor.hpp"

bool Constructor::status(bool verbose) {
   if (_list.empty() == true) {
	if (verbose == true) {
	   std::cout << "list of bricks is empty" << std::endl;
	}
      return false;
   }
   if (_status_lib == false) {
	if (verbose == true) {
	   std::cout << "the lib is not set" << std::endl;
	}
	return false;
   }
   if (_status_keys == false) {
	if (verbose == true) {
	   std::cout << "the keys are not set" << std::endl;
	}
	return false;
   }
   if (verbose == true) {
	std::cout << "ready to go" << std::endl;
   }
   return true;
}
