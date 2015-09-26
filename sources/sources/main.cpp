/*!
 * \file main.c
 * \author Matthieu Raynaud de Fitte
 * \version 3.6
 * \date 10 janvier 2014
 *
 * Programme de chiffrement
 */

#include <iostream>
#include <functional>
#include "term_prototypes.h"
#include "sdl/sdl_prototypes.h"
#include "qt5/qt5_prototypes.h"
#include "instant_prototypes.h"
#include "utilitaires.h"
#include "Choice.hpp"

using Eigen::MatrixXd;

int main (int ac, char ** argv) {
  if (ac == 1) {
    return main_term();
  }
  std::string av(argv[1]);
  if (av == "-term") {
    return main_term();
  }
  if (av == "-instant") {
    std::cout << "en travaux" << std::endl;
    return main_instant(ac, argv);
  }
  if (av == "-qt5") {
    std::cout << "en travaux" << std::endl;
    return main_qt5(ac, argv);    
  }
  if (av == "-sdl") {
    std::cout << "en travaux" << std::endl;
    return main_sdl(ac, argv);
  }
  if (av == "-help") {
    std::cout << "encode-o-matic peut s'utiliser de différentes façon en fonction du flag :" << std::endl;
    std::cout << "-term ( méthode par défaut ) permet d'avoir un affichage en terminal" << std::endl;
    c_str("En travaux :\n", 'y');
    std::cout << "-instant permet de ne pas avoir d'affichage et de chiffrer / déchiffrer imédiatement avec les arguments" << std::endl;
    std::cout << "-qt5 lance l'interface graphique qt5" << std::endl;
    std::cout << "-sdl lance l'interface graphique sdl" << std::endl;
  }
  std::cout << "error : could not find argument ";
  c_str<std::string &>(av, 'r');
  std::cout << std::endl << "./encode-o-matic -help for help" << std::endl;
  return (-1);
}
