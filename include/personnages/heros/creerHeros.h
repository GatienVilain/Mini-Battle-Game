#ifndef FONCTION_HEROS_H
#define FONCTION_HEROS_H

#include <string>
#include <vector>

#include "hero.h"

namespace personnages {

    // Gère la création des héros
    // Demande le nombre de héros à créer en argument
    // Retourne l’ensemble des héros créés
    std::vector<Hero*> creerHeros(int nombreHeros);

    // Crée un héro dont le nom et la classe sont choisi par l'utilisateur
    Hero* creerHero();

    void afficherMenuClasse();
}

#endif // FONCTION_HEROS_H
