#ifndef NINJA_H
#define NINJA_H

#include "hero.h"
#include "personnage.h"

namespace personnages {

    class Ninja: public Hero
    {
        public:
            Ninja(std::string nom);
            void lancerPouvoir();

            // Getters & Setters
            Personnage* getCible() const;
            void setCible(Personnage* cible);

        private:
            Personnage* cible;
    };
}

#endif // NINJA_H
