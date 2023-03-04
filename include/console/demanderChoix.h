#ifndef DEMANDERCHOIX_H
#define DEMANDERCHOIX_H

#include <iostream>
#include <vector>
#include <string>

#include "hero.h"
#include "monstre.h"
#include "personnage.h"

namespace affichage
{
    void afficherMenuChoix(std::string nomHero, bool pouvoirDisponible, std::string errText = "");
    void afficherCiblesPossibles(std::vector<personnages::Monstre*> ciblesPossibles, personnages::Hero* attaquant, std::vector<personnages::Hero*> heros, std::string errText = "");
}

namespace console
{
    // Demande à l'utilisateur de choisir une action
    // Et retourne le choix de l'utilisateur sous forme d'entierPersonnage
    // 1 : Attaquer
    // 2 : Se défendre
    // 3 : Utiliser son pouvoir spécial
    // 4 : Annuler (Revenir au personnage précédent)
    unsigned int demanderChoix(personnages::Hero* hero);

    // Demande à l'utilisateur de choisir une cible parmi les cibles possibles
    // Et retourne la cible choisie
    personnages::Personnage* demanderCible(std::vector<personnages::Monstre*> ciblesPossibles, personnages::Hero* attaquant, std::vector<personnages::Hero*> heros);
}

#endif // DEMANDERCHOIX_H

