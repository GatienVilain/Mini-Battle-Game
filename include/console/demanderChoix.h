#ifndef DEMANDERCHOIX_H
#define DEMANDERCHOIX_H

#include <iostream>
#include <string>

#include "hero.h"

namespace affichage
{
    void afficherMenuChoix(std::string nomHero, bool pouvoirDisponible);
}

namespace console
{
    // Demande à l'utilisateur de choisir une action
    // Et retourne le choix de l'utilisateur sous forme d'entier
    // 1 : Attaquer
    // 2 : Se défendre
    // 3 : Utiliser son pouvoir spécial
    // 4 : Annuler (Revenir au personnage précédent)
    unsigned int demanderChoix(personnages::Hero* hero);
}

#endif // DEMANDERCHOIX_H

