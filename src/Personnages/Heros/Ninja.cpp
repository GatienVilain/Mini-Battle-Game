#include <iostream>
#include <cstdlib> // nécéssaire pour utiliser srand() et rand()
#include <ctime> // nécéssaire pour utiliser time()

#include "heros/ninja.h"

using namespace std;
using namespace personnages;

Ninja::Ninja(std::string nom) : Hero(0, 0, 5, "saï (petits tridents à la main)", nom, "Ninja")
{
    srand(time(0));

    // Pour obtenir un nombre aléatoire entre 30 et 40
    this->setVie(30 + rand() % 11);

    // Pour obtenir un nombre aléatoire entre 1 et 3
    this->setDefenseInitial(1 + rand() % 3);
}

// Pouvoir spécial du Ninja : Fait une deuxième attaque
// Utilisable toutes les 3 tours
void Ninja::lancerPouvoir()
{
    if (this->getTourDeRecharge() == 0)
    {
        this->attaquer(this->getCible());
        cout << "   " << this->getNom()
             << " (Ninja) utilise son pouvoir spécial et attaque une deuxième fois !" << endl;
        this->attaquer(this->getCible());
        this->setTourDeRecharge(3);
    }
}

// Getters & Setters

Personnage* Ninja::getCible() const
{
    return this->cible_;
}

void Ninja::setCible(Personnage* cible)
{
    this->cible_ = cible;
}
