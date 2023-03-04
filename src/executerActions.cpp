#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>

#include "executerActions.h"
#include "main.h"
#include "hero.h"
#include "monstre.h"
#include "personnage.h"
#include "afficherScene.h"

using namespace std;
using namespace personnages;

namespace outils
{
    void executerActionsHeros(vector<Choix> actions, vector<Hero*> heros, vector<Monstre*> monstres)
    {
        for (long unsigned int i = 0; i < heros.size(); i++)
        {
            affichage::afficherCombatants(heros, monstres);

            Choix action = actions[i];
            switch (action.choix)
            {
                // Le héros attaque
                case 1:
                    std::cout << heros[i]->getNom() << " attaque " << action.cible->getNom() << "." << std::endl;
                    heros[i]->attaquer(action.cible);
                    break;
                // Le héros se défend
                case 2:
                    std::cout << heros[i]->getNom() << " se défend." << std::endl;
                    heros[i]->seDefendre();
                    break;
                // Le héros utilise son pouvoir
                case 3:
                    std::cout << heros[i]->getNom() << " utilise son pouvoir." << std::endl;
                    heros[i]->lancerPouvoir();
            }

            // Attend que l’utilisateur appuie sur Entrée pour passer à l’action suivante
            std::cout << "Appuyez sur Entrée pour continuer." << std::endl;
            // TODO: std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}
