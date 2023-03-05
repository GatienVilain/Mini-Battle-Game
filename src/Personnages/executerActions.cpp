#include <vector>
#include <algorithm>

#include "executerActions.h"
#include "outils.h"
#include "hero.h"
#include "monstre.h"
#include "afficherScene.h"
#include "outilsAffichage.h"

using namespace std;
using namespace outils;

namespace personnages
{
    void executerActionsHeros(vector<Choix> actions, vector<Hero*>& heros, vector<Monstre*>& monstres)
    {
        for (long unsigned int i = 0; i < heros.size(); i++)
        {
            affichage::afficherCombatants(heros, monstres);

            Choix action = actions[i];
            bool isDead = false;
            switch (action.choix)
            {
                // Le héros attaque
                case 1:
                    // Si le monstre est encore vivant
                    if (action.cible->estVivant())
                    {
                        isDead = heros[i]->attaquer(action.cible);
                        if (isDead)
                        {
                            // Supprime le monstre de la liste des monstres combattants
                            action.cible->tuer(); // Définit le monstre comme mort
                            monstres.erase(remove(monstres.begin(), monstres.end(), action.cible), monstres.end());
                        }
                    }
                    else { continue; } // Si le monstre est mort, pas besoin d’afficher l’information à l’utilisateur
                    break;
                // Le héros se défend
                case 2:
                    heros[i]->seDefendre();
                    break;
                // Le héros utilise son pouvoir
                case 3:
                    heros[i]->lancerPouvoir();
            }

            // Attend que l’utilisateur appuie sur Entrée pour passer à l’action suivante
            affichage::waitForUser();
        }
    }

    void executerActionsMonstres(vector<Monstre*>& monstres, vector<Hero*>& heros)
    {
        for (auto monstre : monstres)
        {
            affichage::afficherCombatants(heros, monstres);

            // Le monstre attaque un héros au hasard
            int indexCible = 1 + rand() % (heros.size());
            bool isDead = monstre->attaquer(heros[indexCible - 1]);
            if (isDead)
            {
                // Si le héros est mort, on le supprime de la liste des héros
                heros[indexCible - 1]->tuer(); // Définit le héros comme mort
                heros.erase(heros.begin() + (indexCible - 1));
            }

            // Attend que l’utilisateur appuie sur Entrée pour passer à l’action suivante
            affichage::waitForUser();
        }
    }

    void executerActionsFinTour(vector<Hero*>& heros, vector<Monstre*>& monstres)
    {
        for (auto hero : heros)
        {
            hero->finTour(); // Appelle la méthode dédiée pour chaque héros
        }
    }
}
