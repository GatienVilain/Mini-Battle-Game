#ifndef MAIN_H
#define MAIN_H

#include "personnage.h"

namespace outils
{
    struct Choix
    {
        unsigned int choix;
        personnages::Personnage* cible;
    };
}


#endif // MAIN_H

