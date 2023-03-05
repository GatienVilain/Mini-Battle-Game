#ifndef CREERHEROS_H
#define CREERHEROS_H

#include <string>
#include <vector>

#include "hero.h"

namespace personnages
{
    // Crée un héro dont le nom et la classe sont choisi par l'utilisateur
    // Il est possible donner plus d’information à propos du héro qui va être créé
    Hero* creerHero(std::vector<Hero*>& personnages, std::string informations = "");

    // Gère la création des héros
    // Demande le nombre de héros à créer en argument
    // Retourne l’ensemble des héros créés
    std::vector<Hero*> creerHeros(unsigned int nombreHeros);
}

#endif // FONCTION_HEROS_H
