#ifndef EXECUTERACTIONS_H
#define EXECUTERACTIONS_H

#include <vector>

#include "outils.h"
#include "hero.h"
#include "monstre.h"

namespace personnages
{
    // Exécute les actions demandées par l’utilisateur
    // Et affiche les messages correspondants
    void executerActionsHeros(std::vector<outils::Choix> actions, std::vector<personnages::Hero*>& heros, std::vector<personnages::Monstre*>& monstres);

    // Choisi aléatoirement une action et une cible pour chaque monstre
    // Et exécute les actions puis affiche les messages correspondants
    void executerActionsMonstres(std::vector<personnages::Monstre*>& monstres, std::vector<personnages::Hero*>& heros);

    // Exécute les actions de fin de tour pour chaque héros
    // Met à jour les tours de recharge des pouvoirs et restorer la défense
    void executerActionsFinTour(std::vector<personnages::Hero*>& heros, std::vector<personnages::Monstre*>& monstres);
}

#endif // EXECUTERACTIONS_H
