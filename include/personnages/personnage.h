#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <string>

namespace personnages {

    class Personnage
    {
        public:
            Personnage(int vie, int defense, int degats, std::string arme, std::string nom);
            // Réduit les points de vie du personnage passé en argument …
            // …en fonction des dégâts du personnage attaquant …
            // …et de la défense du personnage attaqué
            void attaquer(Personnage *p);
            // Augmente la défense de 75% pour le tour actuel
            void seDefendre();

            // Getters & Setters
            int getVie() const;
            int getDefense() const;
            int getDegats() const;
            std::string getArme() const;
            std::string getNom() const;
            void setVie(int vie);
            void setDefense(int defense);
            void setDegats(int degats);
            void setArme(std::string arme);
            void setNom(std::string nom);

        private:
            int vie;
            int defense;
            int degats;
            std::string arme;
            std::string nom;
            bool seDefend;
    };
}

#endif // PERSONNAGE_H
