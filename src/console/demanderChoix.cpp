#include <iostream>
#include <string>

#include "demanderChoix.h"
#include "hero.h"
#include "monstre.h"
#include "personnage.h"
#include "afficherScene.h"

using namespace std;
using namespace personnages;

namespace console
{
    using namespace affichage;

    unsigned int demanderChoix(Hero* hero)
    {
        string errText = "";
        while (true)
        {
            bool pouvoirDisponible = hero->getTourDeRecharge() == 0;
            afficherMenuChoix(hero->getNom(), pouvoirDisponible, errText);

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
                case '4':
                case 'r':
                case 'R':
                    return 4;
                case '3':
                case 's':
                case 'S':
                    if (pouvoirDisponible){ return 3; } // Si le pouvoir est disponible, on retourne le choix
                    // Sinon, C’est que le choix est invalide et donc on affiche un message d’erreur (voir default car pas de break)
                default:
                    errText = "Choix invalide. Entrer la lettre entre parenthèses correspondant à votre choix.";
            }
        }
    }

    Personnage* demanderCible(vector<Monstre*> ciblesPossibles, Hero* attaquant, vector<Hero*> heros)
    {
        string errText = "";
        while (true)
        {
            afficherCiblesPossibles(ciblesPossibles, attaquant, heros, errText);

            string choix;
            cin >> choix;

            try
            {
                // Convertir le choix en entier
                long unsigned int choixInt = stoi(choix);
                // Vérifier que le choix est valide
                if (choixInt > 0 && choixInt <= ciblesPossibles.size())
                {
                    return ciblesPossibles[choixInt - 1];   // -1 car le premier élément est à l'index 0 …
                                                            // …et que l’utilisateur répond un nombre qui commence à 1
                }
                else
                {
                    errText = "Choix invalide. Entrer le numéro correspondant à la cible.";
                }
            }
            // Si le choix n'est pas un entier
            catch (invalid_argument const& ex)
            {
                errText = "Entrée invalide. Entrer un nombre.";
            }
        }
    }

}

namespace affichage
{
    void afficherMenuChoix(string nomHero, bool pouvoirDisponible, string errText)
    {
        cout << errText << endl;
        cout << "Que doit faire " << nomHero << " ? " << endl
             << " - Attaquer (A/a)" << endl
             << " - Se Défendre (D/d)" << endl;

        if (pouvoirDisponible)
        {
            cout << " - Utiliser son pouvoir spécial (S/s)" << endl;
        }

        cout << "Annuler, revenir au personnage précédent (R/r)" << endl;
    }

    void afficherCiblesPossibles(vector<Monstre*> ciblesPossibles, Hero* attaquant, vector<Hero*> heros, string errText)
    {
        afficherCombatants(heros, ciblesPossibles, true);
        cout << errText << endl;
        cout << "Qui " << attaquant->getNom() << " doit attaquer ? " << endl;
        cout << "(Entrer le numéro correspondant à la cible)" << endl;
    }
}

