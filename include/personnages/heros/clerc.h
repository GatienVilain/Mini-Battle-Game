#ifndef CLERC_H
#define CLERC_H

#include "hero.h"

namespace personnages {

    class Clerc: public Hero
    {
        public:
            Clerc(std::string nom);
            void lancerPouvoir();
    };
}

#endif // CLERC_H
