#ifndef CLERC_H
#define CLERC_H

#include "hero.h"

namespace personnages {

    class Clerc: public Hero
    {
        public:
            Clerc(std::string nom);
            void lancerPouvoir();

            // Getters & setters
            int getVieMax() const;
            void setVieMax(int vieMax);

        private:
            int vieMax_;
    };
}

#endif // CLERC_H
