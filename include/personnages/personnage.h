#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <string>

namespace personnages {

    class Personnage
    {
        public:
            Personnage(int vie, int defense, int degats, std::string arme, std::string nom);
            // Réduit les points de vie du personnage passé en argument …
            // Retourne l’état de la cible (vivant: false ou mort: true)
            bool attaquer(Personnage *p);
            // Augmente la défense de 75% pour le tour actuel
            void seDefendre();
            // Réinitialise la défense à sa valeur initiale
            void reinitialiserDefense();
            // Retourne l’état de santé du personnage (vivant: true ou mort: false)
            bool estVivant();
            // Défini le personnage comme mort
            void tuer();

            // Getters & Setters
            int getVie() const;
            int getDefense() const;
            int getDefenseInitial() const;
            int getDegats() const;
            std::string getArme() const;
            std::string getNom() const;
            bool getSeDefend() const;
            bool getEtatSante() const;
            void setVie(int vie);
            void setDefense(int defense);
            void setDefenseInitial(int defenseInitial);
            void setDegats(int degats);
            void setArme(std::string arme);
            void setNom(std::string nom);
            void setSeDefend(bool seDefend);
            void setEtatSante(bool etatSante);

        private:
            int vie_;
            int defense_;
            int defenseInitial_;
            int degats_;
            std::string arme_;
            std::string nom_;
            bool seDefend_;
            bool etatSante_; // true: vivant, false: mort
    };
}

#endif // PERSONNAGE_H
