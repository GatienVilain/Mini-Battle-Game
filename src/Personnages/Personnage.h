#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <string>

class Personnage
{
    public:
        Personnage(int vie, int defense, int degats, std::string arme, std::string nom);
        void Attaquer(Personnage *p);

        // Getters & Setters
        int GetVie() const;
        int GetDefense() const;
        int GetDegats() const;
        std::string GetArme() const;
        std::string GetNom() const;
        void SetVie(int vie);
        void SetDefense(int defense);
        void SetDegats(int degats);
        void SetArme(std::string arme);
        void SetNom(std::string nom);

    private:
        int vie;
        int defense;
        int degats;
        std::string arme;
        std::string nom;
};

#endif // PERSONNAGE_H
