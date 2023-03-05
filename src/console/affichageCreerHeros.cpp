#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "outilsAffichage.h"
#include "affichageCreerHeros.h"
#include "hero.h"

using namespace std;
using namespace personnages;

namespace console
{
    using namespace affichage;

    string demanderNomHero(vector<Hero*>& personnages, string informations)
    {
        afficherListeHeros(personnages);

        string nom;
        cout << "    " + informations << endl
             << "    Entrez le nom du héro : " << endl << "    ";
        cin >> nom;

        return nom;
    }

    string demanderClasseHero(vector<Hero*>& personnages, string nom, string informations)
    {
        afficherListeHeros(personnages);
        afficherMenuClasse();

        string classe;
        cout << "    " + informations << endl
             << "    Entrez la classe de "
             << nom << " : " << endl << "    ";
        cin >> classe;

        return classe;
    }

    bool demanderAnnulation(vector<Hero*>& personnages, Hero* hero)
    {
        afficherListeHeros(personnages);

        string annuler;
        cout << "    Voulez-vous supprimer " << hero->getNom()
             << " (" << hero->getClasse() << ")"
             << " de votre liste de héros ? (oui/non) " << endl << "    ";
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
        cout << "    Classes disponible :" << endl
             << "    1. Chevalier" << endl
             << "    2. Clerc" << endl
             << "    3. Ninja" << endl;
    }

    void afficherListeHeros(vector<Hero*>& heros)
    {
        string ligneNoms = "";
        string ligneClasse = "";

        for (auto hero : heros)
        {
            ligneNoms += "    " + hero->getNom() + "     ";
            ligneClasse += "   (" + hero->getClasse() + ")    ";
        }

        clearScreen();
        cout << "    Votre équipe :" << endl;
        cout << "    " + ligneNoms << endl;
        cout << "    " + ligneClasse << endl;
        cout << endl << "  " << setfill('=') << setw(75) << "  " << endl << setfill(' ') << endl;
    }

    void afficherAnnulation(Hero* personnage)
    {
        cout << "    Annulation du choix précédent.\n "
                << "    Au revoir " << personnage->getNom()
                << "     (" << personnage->getClasse() << ")" << endl;
    }
}
