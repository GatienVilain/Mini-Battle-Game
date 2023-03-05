#ifndef AFFICHAGECREERHEROS_H
#define AFFICHAGECREERHEROS_H

#include <vector>

#include "hero.h"

namespace affichage
{
    void afficherMenuClasse();
    void afficherListeHeros(std::vector< personnages::Hero*>& heros);
    void afficherAnnulation(personnages::Hero* personnage);
}

namespace console
{
    std::string demanderNomHero(
        std::vector<personnages::Hero*>& personnages,
        std::string informationsSupplementaires = ""
    );

    std::string demanderClasseHero(
        std::vector<personnages::Hero*>& personnages,
        std::string nomHero,
        std::string informationsSupplementaires = ""
    );

    bool demanderAnnulation(
        std::vector<personnages::Hero*>& personnages,
        personnages::Hero* HeroASupprimer
    );
}

#endif // AFFICHAGECREERHEROS_H
