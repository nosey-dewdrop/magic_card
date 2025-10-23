#include "MagicCard.h"
#include <iostream>
using namespace std;

MagicCard::MagicCard() {
    players = nullptr;
    playerCount = 0;
}

MagicCard::~MagicCard() {
    delete[] players;
}

void MagicCard::addPlayer(int id, const string& name){
      
}

void MagicCard::printPlayers() const {

}

