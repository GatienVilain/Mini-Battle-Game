#ifndef NINJA_H
#define NINJA_H

#include "Hero.h"

class Ninja: public Hero
{
    public:
        Ninja(std::string nom);
        void lancerPouvoir(Personnage *cible);
};

#endif // NINJA_H
