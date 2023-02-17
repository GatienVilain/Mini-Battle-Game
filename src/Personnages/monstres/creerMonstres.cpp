#include <vector>

#include "monstre.h"

using namespace std;

namespace personnages
{
    vector<Monstre*> creerMonstres(unsigned int nombreMonstres)
    {
        vector<Monstre*> monstres;

        for (int i = 0; i < 10; i++)
        {
            Monstre* monstre = new Monstre();
            monstres.push_back(monstre);
        }

        return monstres;
    }
}
