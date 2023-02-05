#ifndef HEROS_H
#define HEROS_H

#include <string>
#include "personnage.h"

class Hero: public Personnage
{
    public:
        Hero(int vie, int defense, int degats, std::string arme, std::string nom);
        virtual void lancerPouvoir() = 0;

        // Getters & Setters
        int getTourDeRecharge() const;
        void decrementTourDeRecharge();
        void setTourDeRecharge(int toursDeRecharge);

    private:
        int toursDeRecharge;
};

#endif // HEROS_H
