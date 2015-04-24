#include "function_prototypes.h"
#include "utilitaires.h"

using namespace std;
using Eigen::MatrixXd;

// exercice de parsage : Ans pour avoir le résultat de l'opération précédente
int main () {
  cout << endl << "********************" << endl;
  cout << "** \033[1;31mEncode o matic\033[0;0m **" << endl;
  cout << "********************" << endl << endl;

  int user_choise;

  while (42) {
    cout << "Faites votre choix : " << endl;
    cout << "\033[1;36m-2\033[0;0m : afficher les infos" << endl;
    cout << "\033[1;36m-1\033[0;0m : quitter" << endl << endl;
    cout << "\033[1;36m1\033[0;0m : Césars" << endl;
    cout << "\033[1;36m2\033[0;0m : Vigenère" << endl;
    cout << "\033[1;36m3\033[0;0m : 102 ( matrice + base )" << endl;
    cout << "\033[1;36m4\033[0;0m : v102 ( ombinaison 102 et Vigenère )" << endl;
    user_choise = user_input();

    while (user_choise == 0 || user_choise < -2 || user_choise > 4) {
      cout << "le nombre saisi : '" << user_choise << "' ne correspond pas à un des choix du menu" << endl;
      user_choise = user_input();
    }

    cout << endl;

    switch (user_choise) {
      case -2 :
        display_info();
        break;
      case -1 :
        cout << endl << "Bye !" << endl << endl;
        return 0;
      case 1 :
        cesars_user_choises();
        break;
      case 2 :
        vigenere_user_choises();
        break;
      case 3 :
        E_102_user_choises();
        break;
      case 4 :
        V_102_user_choises();
        break;
      default :
        cout << "hum, c'est embarassant : le choix reçu est : \"" << user_choise << "\" celà n'aurait pas dut être possible" << endl;
        cout << "Fermeture du programme" << endl;
        return 0;
    }
  }
  return 0;
}
