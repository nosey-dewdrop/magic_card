#include "MagicCard.h"
#include <iostream>
using namespace std;

MagicCard::MagicCard() {
    players = nullptr;
    playerCount = 0;

    drawPile = nullptr;
    discardPile = nullptr; // avoid garbage 

    drawCount = 0;
    discardCount = 0;

    cout << "the game starts!!!!"<< endl;
}

MagicCard::~MagicCard() {
    delete[] players;  // cards has a possibility to cause memory leak...      
    delete[] discardPile;   
    delete[] drawPile;

    cout << "MagicCard game destroyed!" << endl;
}


void MagicCard::addPlayer(int id, const string& name){

}

void MagicCard::printPlayers() const{

}

int main(){
    MagicCard game;
    game.addPlayer(10, "damla");
    game.printPlayers();
    return 0;

};
