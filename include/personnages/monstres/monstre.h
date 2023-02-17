#ifndef MONSTRE_H
#define MONSTRE_H

#include <string>
#include "personnage.h"

namespace personnages {

    class Monstre: public Personnage
    {
        public:
            // Création d’un monstre aléatoire.
            Monstre();
            // Création d’un monstre où on choisit ces informations.
            Monstre(int vie, int defense, int degats, std::string arme, std::string nom);

    };
}

#endif // MONSTRE_H
