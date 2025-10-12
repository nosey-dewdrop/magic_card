#ifndef MAGICCARD_H
#define MAGICCARD_H

#include "Card.h"
#include <string>
using namespace std;

class MagicCard : public Card {
    private:
        string effect; // unique magic effect

    public:
        MagicCard();  
        MagicCard(string newName, int newPower, string newEffect);
        ~MagicCard();

        string getEffect() const;
        void setEffect(string newEffect);
        void printCard() const override;
};

 #endif