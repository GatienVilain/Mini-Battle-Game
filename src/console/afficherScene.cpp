#include <iostream>
#include <iomanip>

#include "outilsAffichage.h"
#include "afficherScene.h"
#include "hero.h"
#include "monstre.h"

using namespace std;
using namespace personnages;

namespace affichage
{
    void afficherCombatants(vector<Hero*> heros, vector<Monstre*> monstres, bool afficherNumeroCibles)
    {
        clearScreen();

        // Récupère le nombre maximum de personnages entre les héros et les monstres
        unsigned int nbHeros = heros.size();
        unsigned int nbMonstres = monstres.size();
        unsigned int nbMaxPersonnages = nbHeros > nbMonstres ? nbHeros : nbMonstres;

        // Initialise les variables qui vont contenir l’affichage par personnage et par ligne
        // Le nombre à la fin de la variable correspond à la ligne
        string infoHero1, infoHero2, infoHero3, infoHero4;
        string infoMonstre1, infoMonstre2, infoMonstre3, infoMonstre4;

        // Affiche les informations de tous les personnages
        // Héros à gauche, monstres à droite
        for (unsigned int i = 0; i < nbMaxPersonnages; i++)
        {
            // S’il y a un héro à l’index i, on récupère ses informations et on prépare l’affichage
            if (i < nbHeros)
            {
                infoHero1 = heros[i]->getNom() + " (" + heros[i]->getClasse() + ")";
                infoHero2 = "[ " + to_string(heros[i]->getVie()) + " PV ] [ " +
                            to_string(heros[i]->getDefense()) + " DEF ]";
                infoHero3 = heros[i]->getArme() + " [ " + to_string(heros[i]->getDegats()) + " DMG ]";

                int tourDeRecharge = heros[i]->getTourDeRecharge();
                if (tourDeRecharge == 0)
                {
                    infoHero4 = "Pouvoir disponible";
                }
                else {
                    infoHero4 = "Pouvoir disponible dans " + to_string(tourDeRecharge) + " tours";
                }
            }
            else// Sinon, on initialise les variables à des valeurs vides
            {   // pour éviter que s’il n’y a pas de héro à l’index i,
                // les informations du héro précédent soient réutilisées
                infoHero1 = "";
                infoHero2 = "";
                infoHero3 = "";
                infoHero4 = "";
            }

            // Pareil pour les monstres
            if (i < nbMonstres)
            {
                if (afficherNumeroCibles)
                {
                    infoMonstre2 = to_string(i + 1) + ". ";
                }
                else { infoMonstre2 = "";}

                infoMonstre1 = monstres[i]->getNom();
                infoMonstre2 += "[ " + to_string(monstres[i]->getVie()) + " PV ] [ " +
                                to_string(monstres[i]->getDefense()) + " DEF ]";
                infoMonstre3 = monstres[i]->getArme() + " [ " + to_string(monstres[i]->getDegats()) + " DMG ]";
            }
            else
            {
                infoMonstre1 = "";
                infoMonstre2 = "";
                infoMonstre3 = "";
            }

            // Affiche les informations collectées pour les personnages à l’index i
            cout << left << setw(50) << "  " + infoHero1 << right << setw(30) << infoMonstre1 + "  " << endl;
            cout << left << setw(50) << "  " + infoHero2 << right << setw(30) << infoMonstre2 + "  " << endl;
            cout << left << setw(50) << "  " + infoHero3 << right << setw(30) << infoMonstre3 + "  " << endl;
            cout << left << setw(50) << "  " + infoHero4 << endl << endl;
        }

        cout << " " << setfill('=') << setw(75) << "  " << endl << setfill(' ');

    }

    void afficherFinCombat(vector<Hero*>& heros, vector<Monstre*>& monstres)
    {
        clearScreen();

        if (heros.size() == 0)
        {
            cout << "  ========================================================================" << endl;
            cout << " |                                                                         |" << endl;
            cout << " |                                                                         |" << endl;
            cout << " |                             FIN DU COMBAT                               |" << endl;
            cout << " |                                                                         |" << endl;
            cout << " |                     Vous avez malheureusement perdu.                    |" << endl;
            cout << " |                     Tous vos héros sont morts.                          |" << endl;
            cout << " |                                                                         |" << endl;
            cout << " |                                                                         |" << endl;
            cout << "  ========================================================================" << endl;
        }
        else
        {
            cout << "  ========================================================================" << endl;
            cout << " |                                                                         |" << endl;
            cout << " |                                                                         |" << endl;
            cout << " |                             FIN DU COMBAT                               |" << endl;
            cout << " |                                                                         |" << endl;
            cout << " |                     Vous avez gagné le combat !                         |" << endl;
            cout << " |                     Tous les monstres sont morts.                       |" << endl;
            cout << " |                                                                         |" << endl;
            cout << " |                                                                         |" << endl;
            cout << "  ========================================================================" << endl;
        }

        waitForUser();
    }


} // namespace affichage
