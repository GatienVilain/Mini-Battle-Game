#include "heros/hero.h"

using namespace personnages;

Hero::Hero(int vie, int defense, int degats, std::string arme, std::string nom): Personnage(vie, defense, degats, arme, nom)
{
    this->setTourDeRecharge(0);
}

int Hero::getTourDeRecharge() const
{
    return this->toursDeRecharge;
}

void Hero::decrementTourDeRecharge()
{
    if (this->getTourDeRecharge() > 0)
    {
        this->toursDeRecharge--;
    }
}

void Hero::setTourDeRecharge(int toursDeRecharge)
{
    this->toursDeRecharge = toursDeRecharge;
}
