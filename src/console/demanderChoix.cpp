#include <iostream>
#include <string>

#include "demanderChoix.h"
#include "hero.h"

using namespace std;
using namespace personnages;

namespace console
{
    using namespace affichage;


    unsigned int demanderChoix(Hero* hero)
    {
        while (true)
        {
            afficherMenuChoix(hero->getNom(), hero->getTourDeRecharge() == 0);

            string choix;
            cin >> choix;

            switch (choix[0])
            {
                case '1':
                case 'a':
                case 'A':
                    return 1;
                case '2':
                case 'd':
                case 'D':
                    return 2;
                case '3':
                case 's':
                case 'S':
                    return 3;
                case '4':
                case 'r':
                case 'R':
                    return 4;
                default:
                    cout << "Choix invalide. Entrer la lettre entre parenthèses correspondant à votre choix." << endl;
            }
        }
    }

}

namespace affichage
{
    void afficherMenuChoix(string nomHero, bool pouvoirDisponible)
    {
        cout << "Que doit faire " << nomHero << " ? " << endl
             << " - Attaquer (A/a)" << endl
             << " - Se Défendre (D/d)" << endl;

        if (pouvoirDisponible)
        {
            cout << " - Utiliser son pouvoir spécial (S/s)" << endl;
        }

        cout << "Annuler, revenir au personnage précédent (R/r)" << endl;
    }
}

