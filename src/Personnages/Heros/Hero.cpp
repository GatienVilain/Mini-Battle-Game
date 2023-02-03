#include "Hero.h"

Hero::Hero(int vie, int defense, int degats, std::string arme, std::string nom): Personnage(vie, defense, degats, arme, nom)
{
    this->SetTourDeRecharge(0);
}

int Hero::GetTourDeRecharge() const
{
    return this->toursDeRecharge;
}

void Hero::DecrementTourDeRecharge()
{
    if (this->GetTourDeRecharge() > 0)
    {
        this->toursDeRecharge--;
    }
}

void Hero::SetTourDeRecharge(int toursDeRecharge)
{
    this->toursDeRecharge = toursDeRecharge;
}
