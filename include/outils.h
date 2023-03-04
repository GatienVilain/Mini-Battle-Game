#ifndef OUTILS_H
#define OUTILS_H

#include "personnage.h"

namespace outils
{
    struct Choix
    {
        unsigned int choix;
        personnages::Personnage* cible;
    };
}


#endif // OUTILS_H

