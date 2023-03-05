#include <vector>

#include "monstre.h"

using namespace std;

namespace personnages
{
    vector<Monstre*> creerMonstres(unsigned int nombreMonstres)
    {
        vector<Monstre*> monstres;

        for (unsigned int i = 0; i < nombreMonstres; i++)
        {
            Monstre* monstre = new Monstre();
            monstres.push_back(monstre);
        }

        return monstres;
    }

    vector<Monstre*> selectionnerMonstresCombattant(vector<Monstre*>& monstres, unsigned int nombreMinimunDeMonstres, unsigned int nombreMaximumDeMonstres)
    {
        // Pour obtenir un nombre aléatoire entre nombreMinimunDeMonstres et nombreMaximumDeMonstres
        unsigned int nombreMonstres = nombreMinimunDeMonstres + rand() % nombreMaximumDeMonstres;

        // Si le nombre aléatoire de monstre est supérieur au nombre de monstres restants,
        // on prend le nombre de monstres restants pour ne pas dépasser le nombre de monstres restants
        if (nombreMonstres > monstres.size())
        {
            nombreMonstres = monstres.size();
        }

        // Récupère le nombre désigné de monstres au début du vecteur de monstres donné
        vector<Monstre*> monstresCombattant(monstres.begin(), monstres.begin() + nombreMonstres);

        // Supprime les monstres sélectionnés du vecteur de monstres donné
        monstres.erase(monstres.begin(), monstres.begin() + nombreMonstres);

        return monstresCombattant;
    }
}
