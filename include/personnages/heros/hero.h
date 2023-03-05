#ifndef HEROS_H
#define HEROS_H

#include <string>
#include "personnage.h"

namespace personnages {

    class Hero: public Personnage
    {
        public:
            Hero(int vie, int defense, int degats, std::string arme, std::string nom, std::string classe);
            virtual void lancerPouvoir() = 0;
            void finTour();

            // Getters & Setters
            std::string getClasse() const;
            void setClasse(std::string classe);
            int getTourDeRecharge() const;
            void decrementTourDeRecharge();
            void setTourDeRecharge(int toursDeRecharge);

        private:
            std::string classe;
            int toursDeRecharge;
    };
}

#endif // HEROS_H
