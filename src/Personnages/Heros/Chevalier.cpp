#include "Chevalier.h"
#include <cstdlib> // nécéssaire pour utiliser srand() et rand()
#include <ctime> // nécéssaire pour utiliser time()


Chevalier::Chevalier(std::string nom) : Hero(0, 0, 8, "", nom)
{
    srand(time(0));

    // Pour obtenir un nombre aléatoire entre 50 et 70
    this->SetVie(50 + rand() % 21);

    // Pour obtenir un nombre aléatoire entre 4 et 6
    this->SetDefense(4 + rand() % 3);

    int choix = rand() % 2;
    if (choix == 0)
    {
        this->SetArme("Hallebarde");
    }
    else
    {
        this->SetArme("Epée longue");
    }
}

// Pouvoir spécial du chevalier : +5 de dégâts
// Utilisable toutes les 3 tours
void Chevalier::lancerPouvoir()
{
    if (this->GetTourDeRecharge() == 0)
    {
        this->SetDegats(this->GetDegats() + 5);
        this->SetTourDeRecharge(3);
    }
}
