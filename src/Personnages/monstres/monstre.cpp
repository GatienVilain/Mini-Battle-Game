#include "monstre.h"
#include <cstdlib> // nécéssaire pour utiliser srand() et rand()
#include <ctime> // nécéssaire pour utiliser time()

using namespace personnages;

// Constructeur d’un monstre où on choisit ces informations.
Monstre::Monstre(int vie, int defense, int degats, std::string arme, std::string nom) :
    Personnage(vie, defense, degats, arme, nom){}

// Constructeur d’un monstre aléatoire.
Monstre::Monstre() : Personnage(0, 0, 0, "", "")
{
    int choix = rand() % 2;
    if (choix == 0)
    {
        this->setNom("un orc");
    }
    else
    {
        this->setNom("un goblin");
    }

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
        this->setDefenseInitial(4 + rand() % 3);
    }
    else
    {   // Pour obtenir un nombre aléatoire entre 2 et 4
        this->setDefenseInitial(2 + rand() % 3);
    }
}

