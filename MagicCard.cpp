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
    // MagicCard bir player listemiz var. oraya bir player ekleyeceğiz.

    if(!playerExists(id)){
        Player newPlayer(id, name);
        Player* newPlayers = new Player[playerCount + 1];

        for(int i = 0; i < playerCount; i++){
            newPlayers[i] = players[i];
        }

        newPlayers[playerCount] = newPlayer;

        delete[] players; // delete the list which the pointer points to.
        players = newPlayers; // let it point new one. and newPlayer pointer will be deleted automatically.
        playerCount++;
    }
    else{
        cout << "already exists!" << endl;
        return;
    }
}

void MagicCard::printPlayers() const{

    if(playerCount != 0){
        cout << "players: " << endl;
        for(int i = 0; i < playerCount; i++){
            cout << "- player " << players[i].getId()
<< " : " << players[i].getUserName() << endl;
        }
    }

    else{
        cout << "empty..." << endl;
        return;
    }
}

bool MagicCard::playerExists(int id){

    for(int i = 0; i < playerCount; i++){
        if(id == players[i].getId()){
            return true;
        }
    }
    
    return false;
}

int main(){
    MagicCard game;
    game.addPlayer(10, "damla");
    game.printPlayers();

    game.addPlayer(15, "meltem");
    game.printPlayers();

    game.addPlayer(10,"hahahaha");

    return 0;

};

/**
 
cd "/Users/damummyphus/magic_card/"
g++ -std=c++11 -Wall -Werror MagicCard.cpp Player.cpp -o main
./main

 */