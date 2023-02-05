#include "monstre.h"
#include <cstdlib> // nécéssaire pour utiliser srand() et rand()
#include <ctime> // nécéssaire pour utiliser time()


Monstre::Monstre() : Personnage(0, 0, 0, "", "")
{
    srand(time(0));

    int choix = rand() % 2;
    if (choix == 0)
        this->setNom("Orc");
    else
        this->setNom("Goblin");

    choix = rand() % 2;
    if (choix == 0)
    {
        this->setArme("Hache");
        this->setDegats(8);
    }
    else
    {
        this->setArme("Gourdin");
        this->setDegats(5);
    }

    // Pour obtenir un nombre aléatoire entre 10 et 20
    this->setVie(10 + rand() % 11);

    if (this->getNom() == "Orc")
    {   // Pour obtenir un nombre aléatoire entre 4 et 6
        this->setDefense(4 + rand() % 3);
    }
    else
    {   // Pour obtenir un nombre aléatoire entre 2 et 4
        this->setDefense(2 + rand() % 3);
    }
}
