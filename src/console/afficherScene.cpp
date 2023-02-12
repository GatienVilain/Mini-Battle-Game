#include <iostream>
#include <iomanip>

#include "afficherScene.h"
#include "hero.h"
#include "monstre.h"

using namespace std;
using namespace personnages;

namespace affichage
{
    void afficherCombatants(Hero* hero, Monstre* monstre)
    {
        // cout << hero->getNom() << 2 * " "
        cout << left << setw(100) << hero->getNom() << right << setw(50) << monstre->getNom() << endl;
        cout << left << setw(100) << hero->getNom() << right << setw(50) << monstre->getNom() << endl;
        cout << left << setw(100) << hero->getNom() << right << setw(50) << monstre->getNom() << endl;
        cout << left << setw(100) << hero->getNom() << right << setw(50) << monstre->getNom() << endl;
    }
} // namespace affichage
