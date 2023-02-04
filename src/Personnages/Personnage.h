#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <string>

class Personnage
{
    public:
        Personnage(int vie, int defense, int degats, std::string arme, std::string nom);
        void attaquer(Personnage *p);

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
};

#endif // PERSONNAGE_H
