#include <iostream>
#include <string>
#include <vector>

#include "creerHeros.h"
#include "hero.h"
#include "chevalier.h"
#include "clerc.h"
#include "ninja.h"

using namespace std;

namespace personnages
{

    void afficherMenuClasse()
    {
        cout << "Choisissez la classe du héro :" << endl;
        cout << "1. Chevalier" << endl;
        cout << "2. Clerc" << endl;
        cout << "3. Ninja" << endl;
    }

    void afficherListeHeros(vector<Hero*> heros)
    {
        cout << "Liste des héros :" << endl;
        for (auto hero : heros)
        {
            cout << " - " << hero->getNom() << " (" << hero->getClasse() << ")" <<endl;
        }
    }

    Hero* creerHero()
    {
        string nom;
        cout << "Entrez le nom du héro : ";
        cin >> nom;

        int choixClasse;
        afficherMenuClasse();
        // TODO: Exception si string entré
        cin >> choixClasse;

        Hero* personnage = nullptr;
        switch (choixClasse)
        {
            case 1:
                personnage = new Chevalier(nom);
                break;
            case 2:
                personnage = new Clerc(nom);
                break;
            case 3:
                personnage = new Ninja(nom);
                break;
            default:
                cout << "Classe inconnue." << endl;
                break;
        }
        return personnage;
    }

    vector<Hero*> creerHeros(int nombreHeros)
    {
        vector<Hero*> personnages;

        for (int i = 0; i < nombreHeros; i++)
        {
            cout << endl << "Hero n°" << i + 1 << endl;
            Hero* personnage = creerHero();
            personnages.push_back(personnage);

            afficherListeHeros(personnages);

            string annuler;
            cout << "Voulez-vous annuler le choix précédent ? (oui/non) ";
            cin >> annuler;
            if (annuler == "oui")
            {
                cout << "Annulation du choix précédent.\nAu revoir " << personnage->getNom() << " (" << personnage->getClasse() << ")" <<endl;
                personnages.pop_back();
                i--;
            }
        }

        return personnages;
    }

} // end namespace personnages
