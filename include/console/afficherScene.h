#ifndef AFFICHERSCENE_H
#define AFFICHERSCENE_H

#include <vector>
#include "hero.h"
#include "monstre.h"

namespace affichage {

    void afficherCombatants(std::vector<personnages::Hero*> heros, std::vector<personnages::Monstre*> monstres);
}

#endif // AFFICHERSCENE_H
