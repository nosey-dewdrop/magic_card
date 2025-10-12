#include "MagicCard.h"
#include <iostream>
using namespace std;

MagicCard::MagicCard() : Card() {
    effect = "no effect";
    cout << "magic card created (default)." << endl;
}

MagicCard::MagicCard(string newName, int newPower, string newEffect) : Card(newName, newPower) {
    effect = newEffect;
}


MagicCard::~MagicCard() {
    cout<<"magic card gone!: " << getName() << endl;
}

string MagicCard::getEffect() const {
    return effect;
}

void MagicCard::setEffect(string newEffect) {
    effect = newEffect;
}

void MagicCard::printCard() const {
    cout << "\n*name:" << getName() << "\n*power: " << getPower();
    cout << "\n*effect: " << effect << endl;
}