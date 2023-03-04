#include <iostream>
#include <cstdlib> // nécéssaire pour utiliser srand() et rand()
#include <ctime> // nécéssaire pour utiliser time()

#include "heros/clerc.h"

using namespace std;
using namespace personnages;

Clerc::Clerc(std::string nom) : Hero(0, 0, 6, "", nom, "Clerc")
{
    srand(time(0));

    // Pour obtenir un nombre aléatoire entre 40 et 60
    this->setVie(40 + rand() % 21);

    // Pour obtenir un nombre aléatoire entre 3 et 5
    this->setDefense(3 + rand() % 3);

    int choix = rand() % 2;
    if (choix == 0)
    {
        this->setArme("Hache");
    }
    else
    {
        this->setArme("Masse");
    }
}

// Pouvoir spécial du clerc : se soigne de 5 points de vie
// Utilisable toutes les 3 tours
void Clerc::lancerPouvoir()
{
    if (this->getTourDeRecharge() == 0)
    {
        this->setVie(this->getVie() + 5);
        this->setTourDeRecharge(3);
        cout << this->getNom() << " (Clerc) utilise son pouvoir spécial et se soigne de 5 points de vie !" << endl;
    }
}
