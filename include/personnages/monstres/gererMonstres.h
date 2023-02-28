#ifndef GERERMONSTRES_H
#define GERERMONSTRES_H

#include <string>
#include <vector>

#include "monstre.h"

namespace personnages
{
    // Crée un vecteur de monstres aléatoires à partir d'un nombre donné
    std::vector<Monstre*> creerMonstres(unsigned int nombreMonstres);

    // Retourne un vecteur de monstres parmi un vecteur de monstres donné
    // dont le nombre de monstres est compris entre un minimum et un maximum.
    // Les monstres sélectionnés sont supprimés du vecteur de monstres donné.
    std::vector<Monstre*> selectionnerMonstresCombattant(std::vector<Monstre*>& monstres, unsigned int nombreMinimunDeMonstres, unsigned int nombreMaximumDeMonstres);
}

#endif // GERERMONSTRES_H
