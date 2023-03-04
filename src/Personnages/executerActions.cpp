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
                    isDead = heros[i]->attaquer(action.cible);
                    if (isDead)
                    {
                        // Supprime le monstre de la liste des monstres combattants
                        monstres.erase(remove(monstres.begin(), monstres.end(), action.cible), monstres.end());
                    }
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
}
