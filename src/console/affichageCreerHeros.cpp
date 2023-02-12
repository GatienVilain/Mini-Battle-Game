#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "affichageCreerHeros.h"
#include "hero.h"

using namespace std;
using namespace personnages;

namespace console
{
    using namespace affichage;

    string demanderNomHero(string informations)
    {
        string nom;
        cout << informations << endl
             << "Entrez le nom du héro : ";
        cin >> nom;

        return nom;
    }

    string demanderClasseHero(string nom, string informations)
    {
        afficherMenuClasse();

        string classe;
        cout << informations << endl
             << "Entrez la classe de "
             << nom << " : ";
        cin >> classe;

        return classe;
    }

    bool demanderAnnulation(Hero* hero)
    {
        string annuler;
        cout << "Voulez-vous supprimer " << hero->getNom()
             << " (" << hero->getClasse() << ")"
             << " de votre liste de héros ? (oui/non) ";
        cin >> annuler;

        switch (annuler[0])
        {
            case 'o':
            case 'O':
                return true;
            default:
                return false;
        }
    }
}

namespace affichage
{
    void afficherMenuClasse()
    {
        cout << "Choisissez la classe du héro :\n"
             << "1. Chevalier\n"
             << "2. Clerc\n"
             << "3. Ninja" << endl;
    }

    void afficherListeHeros(vector<Hero*> heros)
    {
        cout << "Liste des héros :" << endl;
        for (auto hero : heros)
        {
            cout << " - " << hero->getNom()
                 << " (" << hero->getClasse() << ")" << endl;
        }
    }

    void afficherAnnulation(Hero* personnage)
    {
        cout << "Annulation du choix précédent.\n "
                << "Au revoir " << personnage->getNom()
                << " (" << personnage->getClasse() << ")" << endl;
    }
}
