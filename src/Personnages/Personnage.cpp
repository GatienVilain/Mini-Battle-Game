#include <iostream>

#include "personnage.h"

using namespace std;
using namespace personnages;

Personnage::Personnage(int vie, int defense, int degats, std::string arme, std::string nom)
{
    this->setVie(vie);
    this->setDefenseInitial(defense);
    this->setDegats(degats);
    this->setArme(arme);
    this->setNom(nom);
}


bool Personnage::attaquer(Personnage *p)
{
    // Réduit les points de vie de la cible p selon la formule suivante :
    // p->vie -= this->attaque - p->defense
    int degatsCauses = this->getDegats() - p->getDefense();
    if ( degatsCauses > 0 )
    {
        // Si l’attaque ne cause pas la mort de la cible
        if ( p->getVie() - degatsCauses > 0 )
        {
            p->setVie( p->getVie() - degatsCauses );
            cout << "   " << this->getNom() << " attaque " << p->getNom()
                << " et lui inflige " << degatsCauses << " points de dégâts." << endl;
            return false;
        }
        else
        {
            p->setVie(0);
            cout << "   " << this->getNom() << " attaque " << p->getNom()
                << " et lui inflige " << degatsCauses << " points de dégâts." << endl;
            cout << "   " << p->getNom() << " est mort." << endl;
            return true;
        }
    }
    else
    {
        cout << "   " << this->getNom() << " attaque " << p->getNom()
             << " mais son attaque est bloquée." << endl;
        return false;
    }
}

void Personnage::seDefendre()
{
    this->seDefend_ = true;
    this->setDefense(this->getDefense() + this->getDefense() * 0.75);
    cout << "   " << this->getNom() << " se défend." << endl;
}

void Personnage::reinitialiserDefense()
{
    if (this->seDefend_)
    {
        this->setDefense(this->getDefenseInitial());
        this->seDefend_ = false;
    }
}

// ======== Getters ========

int Personnage::getVie() const
{
    return this->vie_;
}

int Personnage::getDefense() const
{
    return this->defense_;
}

int Personnage::getDefenseInitial() const
{
    return this->defenseInitial_;
}

int Personnage::getDegats() const
{
    return this->degats_;
}

std::string Personnage::getArme() const
{
    return this->arme_;
}

std::string Personnage::getNom() const
{
    return this->nom_;
}

// ======== Setters ========

void Personnage::setVie(int vie)
{
    this->vie_ = vie;
}

void Personnage::setDefense(int defense)
{
    this->defense_ = defense;
}

void Personnage::setDefenseInitial(int defenseInitial)
{
    this->defenseInitial_ = defenseInitial;
    this->setDefense(defenseInitial);
}

void Personnage::setDegats(int degats)
{
    this->degats_ = degats;
}

void Personnage::setArme(std::string arme)
{
    this->arme_ = arme;
}

void Personnage::setNom(std::string nom)
{
    this->nom_ = nom;
}

