#ifndef CHEVALIER_H
#define CHEVALIER_H

#include "hero.h"

class Chevalier: public Hero
{
    public:
        Chevalier(std::string nom);
        void lancerPouvoir();
};

#endif // CHEVALIER_H
