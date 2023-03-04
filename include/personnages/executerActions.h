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
}

#endif // EXECUTERACTIONS_H
