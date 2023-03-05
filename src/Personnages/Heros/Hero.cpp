#include "hero.h"

using namespace personnages;

Hero::Hero(int vie, int defense, int degats, std::string arme, std::string nom, std::string classe):
    Personnage(vie, defense, degats, arme, nom)
{
    this->setClasse(classe);
    this->setTourDeRecharge(0);
}

void Hero::finTour()
{
    this->decrementTourDeRecharge();
    this->reinitialiserDefense();
}

std::string Hero::getClasse() const
{
    return this->classe_;
}

void Hero::setClasse(std::string classe)
{
    this->classe_ = classe;
}

int Hero::getTourDeRecharge() const
{
    return this->toursDeRecharge_;
}

void Hero::decrementTourDeRecharge()
{
    if (this->getTourDeRecharge() > 0)
    {
        this->toursDeRecharge_--;
    }
}

void Hero::setTourDeRecharge(int toursDeRecharge)
{
    this->toursDeRecharge_ = toursDeRecharge;
}
