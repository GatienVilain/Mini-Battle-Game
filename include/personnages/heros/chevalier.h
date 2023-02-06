#ifndef CHEVALIER_H
#define CHEVALIER_H

#include "hero.h"

namespace personnages {

    class Chevalier: public Hero
    {
        public:
            Chevalier(std::string nom);
            void lancerPouvoir();
    };
}

#endif // CHEVALIER_H
