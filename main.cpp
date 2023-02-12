#include <iostream>
#include <vector>
#include <cstdlib> // nécéssaire pour utiliser rand() et srand()
#include <ctime> // nécéssaire pour utiliser time()

#include "monstre.h"
#include "hero.h"
#include "creerHeros.h"
#include "afficherScene.h"

using namespace std;
using namespace personnages;

// Fonction principale d’une partie
void nouvellePartie()
{
    // ** Initialisation du jeu **
    // Initialisation du générateur de valeurs aléatoires
    srand(time(0));

    // Création des 4 personnages
    // Les noms des personnages sont saisies par l'utilisateur
    vector<Hero*> heros = creerHeros(1); // TODO: mettre 4 heros

    // Génération des 10 monstres aléatoires
    vector<Monstre*> monstres;
    // TODO: vector<Monstre*> monstres = creerMonstres(10);
    // TODO: REMOVE
    for (int i = 0; i < 10; i++)
    {
        Monstre* monstre = new Monstre();
        monstres.push_back(monstre);
    }

    // TODO: REMOVE
    // for (auto test : monstres)
    // {
    //     std::cout << "Hello " << test->getNom() << std::endl;
    //     std::cout << "vie: " << test->getVie() << ", points de défense:" << test->getDefense() << std::endl;
    //     std::cout << "arme: " << test->getArme() << " (" << test->getDegats() << " points de dégâts)" << std::endl;
    // }
    // std::cout << "------------------------------------" << std::endl;
    // for (auto test : heros)
    // {
    //     std::cout << "Hello " << test->getNom() << " (" << test->getClasse() << ")" << endl;
    //     std::cout << "vie: " << test->getVie() << ", points de défense:" << test->getDefense() << std::endl;
    //     std::cout << "arme: " << test->getArme() << " (" << test->getDegats() << " points de dégâts)" << std::endl;
    // }

    // ** Boucle de combat **
    // Tant qu’il reste des héros et des monstres, on continue le combat
    while (!heros.empty() or !monstres.empty())
    {
        // Fait combattre un nombre aléatoire de monstres (entre 1 et 4)
        vector<Monstre*> monstresCombattant = monstres; // TODO: REMOVE
        // TODO: monstresCombattant = selectionMonstresCombattant(monstres, 1, 4);

        // TODO: affichage::afficherInfos(heros, monstresCombattant);
        affichage::afficherCombatants(heros[-1], monstres[-1]); // TODO: REMOVE

        // Pour chaque héros, on demande au joueur ce qu’il veut faire
        for (auto hero : heros) //TODO: changer pour des int pour faire i-- si annulation du choix
        {
            // * Lors du tour d’un héros, le joueur choisit entre: *
            // - Attaquer un monstre = A/a
            // - Se Défendre (+75% pour le tour actuel) = D/d
            // - Utiliser le pouvoir spécial du héros = S/s
            // TODO: char choix = recupereChoix(hero);

            // switch (choix)
            // {
            //     case 'A'|'a':
            //         struct Choix {
            //             int choix = 1,
            //             affichage::getMonstreCible(monstres)
            //         };
            //         choixTour.push_back(choix);
            // }
        }

        for (auto hero : heros)
        {
            // Exécute les choix du joueur pour ce tour et affiche le déroulement du combat (action, cible, dégâts, etc.)
            // Pour chaque message, on demande à l’utilisateur d’appuyer sur un bouton pour continuer, pour faciliter la lecture
            // TODO: hero->executerAction();

            // for (auto choix : choixTour)
            // {
            //     switch (choix.choix)
            //     {
            //         case 1:
            //             hero->attaquer(choix.cible);
            //             break;
            //         case 2:
            //             // TODO: hero->defendre();
            //             break;
            //         case 3:
            //             hero->lancerPouvoir();
            //             break;
            //     }
            // }
        }

        // Retire les monstres morts de la liste des monstres combattants et affiche les monstres restants
        // TODO: monstresCombattant = retirerMonstreMorts(monstresCombattant);

        // Choisis aléatoirement une cible pour chaque monstre combattant et les fait attaquer
        for (auto monstre : monstresCombattant)
        {
            int indexCible = rand() % (monstres.size() - 1);
            monstre->attaquer(heros[indexCible]);
        }

        // À la fin de chaque tour, réinitialise les états temporaires des heros
        // TODO: réinitialiserEtatsHeros(heros);
    }

    // TODO: affichage::afficherFinCombat(heros, monstres);
}

// Point d’entrée du programme
int main()
{
    while (true)
    {
        // TODO: affichage::MenuPrincipal();

        // Après chaque partie, on lui demande s’il veut relancer une nouvelle partie
        // TODO: bool nouvellePartie = demanderNouvellePartie();

        if (nouvellePartie)
        {
            nouvellePartie();
        }
        else
        {
            break;
        }
    }

    cout << "Merci d'avoir joué !" << endl;
    return 0;
}
