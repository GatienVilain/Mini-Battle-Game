#include <iostream>
#include <vector>
#include <cstdlib> // nécéssaire pour utiliser rand() et srand()
#include <ctime> // nécéssaire pour utiliser time()

#include "main.h"
#include "monstre.h"
#include "hero.h"
#include "ninja.h"
#include "creerHeros.h"
#include "gererMonstres.h"
#include "afficherScene.h"
#include "demanderChoix.h"
#include "executerActions.h"

using namespace personnages;

// Fonction principale d’une partie
void jouer()
{
    // ** Initialisation du jeu **
    // Initialisation du générateur de valeurs aléatoires
    srand(time(0));

    // Création des 4 personnages
    // Les noms des personnages sont saisies par l'utilisateur
    std::vector<Hero*> heros = creerHeros(2); // TODO: mettre 4 heros

    // Génération des 10 monstres aléatoires
    std::vector<Monstre*> monstres = creerMonstres(10);

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
    // Tant qu’il reste des héros ou des monstres en vie, on continue de combattre
    // S’il y a encore des monstres à combattre, on en sélectionne un nombre aléatoire
    // Et on les fait combattre jusqu’à ce qu’ils soient morts ou que les héros soient tous morts.
    // Puis on recommence avec les monstres restants.
    while (!heros.empty() or !monstres.empty())
    {
        // Fait combattre un nombre aléatoire de monstres (entre 1 et 4)
        // vector<Monstre*> monstresCombattant = monstres; // TODO: REMOVE
        std::vector<Monstre*> monstresCombattant = selectionnerMonstresCombattant(monstres, 1, 4);

        // * Boucle d’un tour en combat *
        // Tant qu’il y a des monstres en train de combattre et que les héros sont vivants, on refait un tour.
        while (!heros.empty() or !monstresCombattant.empty())
        {
            // * Tour des héros *

            std::vector<outils::Choix> actions;
            // Pour chaque héros, on demande au joueur ce qu’il veut faire
            for (long unsigned int i = 0; i < heros.size(); i++)
            {
                // TODO: affichage::afficherInfos(heros, monstresCombattant);
                affichage::afficherCombatants(heros, monstresCombattant); // TODO: REMOVE and call it inside afficherInfos

                // Lors du tour d’un héros, le joueur choisit entre:
                // - Attaquer un monstre = A/a
                // - Se Défendre (+75% pour le tour actuel) = D/d
                // - Utiliser le pouvoir spécial du héros = S/s
                unsigned int choix = console::demanderChoix(heros[i]);

                // Si le joueur souhaite annuler son choix précédent,
                // on revient au tour du héros précédent (s’il y en a un)
                if (choix == 4)
                {
                    if (i > 0) { i = i - 2; }
                    else { i--; }
                    actions.pop_back();
                    continue;
                }

                // Selon le choix de l’utilisateur, Il est nécessaire de demander à l’utilisateur de choisir une cible
                // On créé donc une action contenant le choix de l’utilisateur…
                // …et la cible (qui est null si le choix ne nécessite pas de cible)
                outils::Choix action {choix, nullptr};

                // Si l’utilisateur souhaite attaquer un monstre
                if (choix == 1)
                {
                    // On demande à l’utilisateur de choisir un monstre à attaquer parmi ceux combattant
                    Personnage* cible = console::demanderCible(monstresCombattant, heros[i], heros);
                    std::cout << "TEST: Cible: " << cible->getNom() << std::endl;
                    action.cible = cible;
                }
                // Ou si l’utilisateur utilise le pouvoir du Ninja
                else if(choix == 3 && heros[i]->getClasse() == "Ninja")
                {
                    // On défini la cible du Ninja
                    // Ninja* heroNinja = dynamic_cast<Ninja*>(heros[i]);
                    // heroNinja->setCible( console::demanderCible(monstresCombattant, heros[i], heros) );
                }

                actions.push_back(action);
            }

            // Exécute les choix du joueur pour ce tour et affiche le déroulement du combat (action, cible, dégâts, etc.)
            // Pour chaque message, on demande à l’utilisateur d’appuyer sur un bouton pour continuer, pour faciliter la lecture
            executerActionsHeros(actions, heros, monstresCombattant);

            std::cout << "TEST: DONE SUCCESSFULLY" << std::endl;
            std::cout << actions.size() << std::endl;
            return; // TODO: REMOVE

            // Retire les monstres morts de la liste des monstres combattants
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
        bool nouvellePartie = true;

        if (nouvellePartie)
        {
            jouer();
        }
        else
        {
            break;
        }
    }

    std::cout << "Merci d'avoir joué !" << std::endl;
    return 0;
}
