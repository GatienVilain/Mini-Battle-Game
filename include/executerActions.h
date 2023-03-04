#ifndef EXECUTERACTIONS_H
#define EXECUTERACTIONS_H

#include <vector>

#include "main.h"
#include "hero.h"
#include "monstre.h"
#include "personnage.h"

namespace outils
{
    // Exécute les actions demandées par l’utilisateur
    // Et affiche les messages correspondants
    void executerActionsHeros(std::vector<Choix> actions, std::vector<personnages::Hero*> heros, std::vector<personnages::Monstre*> monstres);
}

#endif // EXECUTERACTIONS_H
