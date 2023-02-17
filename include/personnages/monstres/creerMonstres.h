#ifndef CREERMONSTRES_H
#define CREERMONSTRES_H

#include <string>
#include <vector>

#include "monstre.h"

namespace personnages
{
    // Crée un vecteur de monstres aléatoires à partir d'un nombre donné
    std::vector<Monstre*> creerMonstres(unsigned int nombreMonstres);
}

#endif // CREERMONSTRES_H
