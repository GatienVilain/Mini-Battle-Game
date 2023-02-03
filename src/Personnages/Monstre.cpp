#include "Monstre.h"
#include <cstdlib> // nécéssaire pour utiliser srand() et rand()
#include <ctime> // nécéssaire pour utiliser time()


Monstre::Monstre() : Personnage(0, 0, 0, "", "")
{
    srand(time(0));

    int choix = rand() % 2;
    if (choix == 0)
        this->SetNom("Orc");
    else
        this->SetNom("Goblin");

    choix = rand() % 2;
    if (choix == 0)
    {
        this->SetArme("Hache");
        this->SetDegats(8);
    }
    else
    {
        this->SetArme("Gourdin");
        this->SetDegats(5);
    }

    // Pour obtenir un nombre aléatoire entre 10 et 20
    this->SetVie(10 + rand() % 11);

    if (this->GetNom() == "Orc")
    {   // Pour obtenir un nombre aléatoire entre 4 et 6
        this->SetDefense(4 + rand() % 3);
    }
    else
    {   // Pour obtenir un nombre aléatoire entre 2 et 4
        this->SetDefense(2 + rand() % 3);
    }
}
