#include "Personnage.h"


Personnage::Personnage(int vie, int defense, int degats, std::string arme, std::string nom)
{
    this->SetVie(vie);
    this->SetDefense(defense);
    this->SetDegats(degats);
    this->SetArme(arme);
    this->SetNom(nom);
}

void Personnage::Attaquer(Personnage *p)
{
    if (p->GetDegats() < p->GetDefense())
    {
        int vie = p->GetVie();
        vie -= this->GetDegats() - p->GetDefense();
        p->SetVie(vie);
    }
}

// ======== Getters ========

int Personnage::GetVie() const
{
    return this->vie;
}

int Personnage::GetDefense() const
{
    return this->defense;
}

int Personnage::GetDegats() const
{
    return this->degats;
}

std::string Personnage::GetArme() const
{
    return this->arme;
}

std::string Personnage::GetNom() const
{
    return this->nom;
}

// ======== Setters ========

void Personnage::SetVie(int vie)
{
    this->vie = vie;
}

void Personnage::SetDefense(int defense)
{
    this->defense = defense;
}

void Personnage::SetDegats(int degats)
{
    this->degats = degats;
}

void Personnage::SetArme(std::string arme)
{
    this->arme = arme;
}

void Personnage::SetNom(std::string nom)
{
    this->nom = nom;
}

