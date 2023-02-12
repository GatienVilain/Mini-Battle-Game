#include "heros/chevalier.h"
#include <cstdlib> // nécéssaire pour utiliser srand() et rand()
#include <ctime> // nécéssaire pour utiliser time()

using namespace personnages;

Chevalier::Chevalier(std::string nom) : Hero(0, 0, 8, "", nom, "Chevalier")
{
    srand(time(0));

    // Pour obtenir un nombre aléatoire entre 50 et 70
    this->setVie(50 + rand() % 21);

    // Pour obtenir un nombre aléatoire entre 4 et 6
    this->setDefense(4 + rand() % 3);

    int choix = rand() % 2;
    if (choix == 0)
    {
        this->setArme("Hallebarde");
    }
    else
    {
        this->setArme("Epée longue");
    }
}

// Pouvoir spécial du chevalier : +5 de dégâts
// Utilisable toutes les 3 tours
void Chevalier::lancerPouvoir()
{
    if (this->getTourDeRecharge() == 0)
    {
        this->setDegats(this->getDegats() + 5);
        this->setTourDeRecharge(3);
    }
}
