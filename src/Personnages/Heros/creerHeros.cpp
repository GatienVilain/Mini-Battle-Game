#include <iostream>
#include <string>
#include <vector>

#include "creerHeros.h"
#include "affichageCreerHeros.h"
#include "hero.h"
#include "chevalier.h"
#include "clerc.h"
#include "ninja.h"

using namespace std;

namespace personnages
{
    Hero* creerHero(vector<Hero*>& personnages, string informations)
    {
        string nom = console::demanderNomHero(personnages, informations);

        // Tant que la classe est incorrecte, on redemande la classe
        informations = "";
        while (true)
        {
            string choixClasse = console::demanderClasseHero(personnages, nom, informations);

            switch (choixClasse[0])
            {
                case '1':
                    return new Chevalier(nom);

                case '2':
                    return new Clerc(nom);

                case '3':
                    return new Ninja(nom);

                default:
                    informations = "Classe inconnue.";
            }
        }
    }

    vector<Hero*> creerHeros(unsigned int nombreHeros)
    {
        vector<Hero*> personnages;
        int i = 1;

        while (personnages.size() < nombreHeros)
        {
            if ( !personnages.empty() )
            {
                affichage::afficherListeHeros(personnages);

                if ( console::demanderAnnulation(personnages, personnages.back()) )
                {
                    personnages.pop_back();
                    i--;
                    continue;
                }
            }

            affichage::afficherListeHeros(personnages);

            Hero* personnage = creerHero(personnages, "Hero n°" + to_string(i));
            personnages.push_back(personnage);
            i++;

            // Pour pouvoir annuler une dernière fois les héros créés précédemment
            if ( personnages.size() == nombreHeros )
            {
                affichage::afficherListeHeros(personnages);

                if ( console::demanderAnnulation(personnages, personnages.back()) )
                {
                    personnages.pop_back();
                    i--;
                }
            }
        }

        return personnages;
    }
}
