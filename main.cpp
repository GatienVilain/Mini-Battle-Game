#include <iostream>
#include <string>

#include "personnage.h"
#include "monstre.h"
#include "heros/Hero.h"
#include "heros/Chevalier.h"
#include "heros/Clerc.h"
#include "heros/Ninja.h"

using namespace personnages;

int main()
{
    Monstre test = Monstre();
    std::cout << "Hello " << test.getNom() << std::endl;
    std::cout << "vie: " << test.getVie() << ", points de défense:" << test.getDefense() << std::endl;
    std::cout << "arme: " << test.getArme() << " (" << test.getDegats() << " points de dégats)" << std::endl;

    // ** Initialisation du jeu **
    // Création des 4 personnages
    // Les noms des personnages sont saisies par l'utilisateur


    // Génération des 10 monstres aléatoires


    // ** Boucle de combat **
    // Tant que les 4 personnages sont vivants
    // Les héros attaquent dans l’ordre de leur liste
    // Puis, les monstres attaquent dans l’ordre de leur liste
    // Et ainsi de suite jusqu’à la mort soit de tous les héros ou tous les monstres.

        // * Lors du tour d’un héros, le joueur choisit entre: *
        // - Attaquer un monstre = A/a
        // - Se Défendre (+75% pour le tour actuel) = D/d
        // - Utiliser le pouvoir spécial du héros = S/s


        // * Afficher le déroulement du combat *
        // Affiche un message d’attaque/défense/pouvoir spécial
        // Attaquant, cible, dégâts infligés

        // Exemple d’affichage:
        // Équipe du joueur:
        // Gatien - Chevalier

        // On demande à l’utilisateur d’appuyer sur un bouton pour continuer

    return 0;
}
