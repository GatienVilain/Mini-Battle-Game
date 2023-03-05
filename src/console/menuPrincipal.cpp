#include <iostream>
#include <string>

#include "outilsAffichage.h"

using namespace std;

namespace affichage
{
    void afficherMenuPrincipal()
    {
        clearScreen();
        cout << "  ========================================================================" << endl;
        cout << " |                                                                         |" << endl;
        cout << " |                                                                         |" << endl;
        cout << " |                      Bienvenue dans MiniBattleGame!                     |" << endl;
        cout << " |                                                                         |" << endl;
        cout << " |                        1. Nouvelle partie                               |" << endl;
        cout << " |                        2. Quitter                                       |" << endl;
        cout << " |                                                                         |" << endl;
        cout << " |                                                                         |" << endl;
        cout << "  ========================================================================" << endl << endl;
    }
}

namespace console
{
    bool demanderNouvellePartie()
    {
        string choix;
        do
        {
            cout << "    Entrée le numéro de votre choix:" << endl << "    ";
            cin >> choix;
        }
        while (choix[0] != '1' and choix[0] != '2');

        return choix[0] == '1';
    }
}
