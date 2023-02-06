#include "personnage.h"

using namespace personnages;

Personnage::Personnage(int vie, int defense, int degats, std::string arme, std::string nom)
{
    this->setVie(vie);
    this->setDefense(defense);
    this->setDegats(degats);
    this->setArme(arme);
    this->setNom(nom);
}

void Personnage::attaquer(Personnage *p)
{
    if (p->getDegats() < p->getDefense())
    {
        int vie = p->getVie();
        vie -= this->getDegats() - p->getDefense();
        p->setVie(vie);
    }
}

// ======== Getters ========

int Personnage::getVie() const
{
    return this->vie;
}

int Personnage::getDefense() const
{
    return this->defense;
}

int Personnage::getDegats() const
{
    return this->degats;
}

std::string Personnage::getArme() const
{
    return this->arme;
}

std::string Personnage::getNom() const
{
    return this->nom;
}

// ======== Setters ========

void Personnage::setVie(int vie)
{
    this->vie = vie;
}

void Personnage::setDefense(int defense)
{
    this->defense = defense;
}

void Personnage::setDegats(int degats)
{
    this->degats = degats;
}

void Personnage::setArme(std::string arme)
{
    this->arme = arme;
}

void Personnage::setNom(std::string nom)
{
    this->nom = nom;
}

