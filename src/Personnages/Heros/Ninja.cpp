#include "heros/ninja.h"
#include <cstdlib> // nécéssaire pour utiliser srand() et rand()
#include <ctime> // nécéssaire pour utiliser time()


Ninja::Ninja(std::string nom) : Hero(0, 0, 5, "saï (petits tridents à la main)", nom)
{
    srand(time(0));

    // Pour obtenir un nombre aléatoire entre 30 et 40
    this->setVie(30 + rand() % 11);

    // Pour obtenir un nombre aléatoire entre 1 et 3
    this->setDefense(1 + rand() % 3);
}

// Pouvoir spécial du Ninja : Fait une deuxième attaque
// Utilisable toutes les 3 tours
void Ninja::lancerPouvoir(Personnage *cible)
{
    if (this->getTourDeRecharge() == 0)
    {
        this->attaquer(cible);
        this->setTourDeRecharge(3);
    }
}
