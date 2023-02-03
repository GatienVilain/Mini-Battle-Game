#ifndef HEROS_H
#define HEROS_H

#include <string>
#include "Personnage.h"

class Hero: public Personnage
{
    public:
        Hero(int vie, int defense, int degats, std::string arme, std::string nom);
        virtual void lancerPouvoir();

        // Getters & Setters
        int GetTourDeRecharge() const;
        void DecrementTourDeRecharge();
        void SetTourDeRecharge(int toursDeRecharge);

    private:
        int toursDeRecharge;
};

#endif // HEROS_H
