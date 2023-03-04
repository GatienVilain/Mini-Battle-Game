#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

namespace affichage
{
    void waitForUser()
    {
        cout << right << setw(80) << "Appuyez sur Entrée pour continuer..." << endl;
        cin.ignore(); // vide le buffer d’entrée
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // attend que l’utilisateur appuie sur Entrée
    }
}
