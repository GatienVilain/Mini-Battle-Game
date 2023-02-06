#ifndef NINJA_H
#define NINJA_H

#include "hero.h"

namespace personnages {
    class Ninja: public Hero
    {
        public:
            Ninja(std::string nom);
            void lancerPouvoir(Personnage *cible);
    };
}

#endif // NINJA_H
