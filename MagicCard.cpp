#include "MagicCard.h"
#include <iostream>
using namespace std;

MagicCard::MagicCard(){

      players = nullptr; // eğer yazmazsan rastgele bir yeri gösterecek. sonra gösterdiğ.i adresteki şeyi silemezsin. o adres benim değil.
      playerCount = 0;   

      drawPile = nullptr;       
      drawPileSize = 0;    

      discardPile = nullptr;    
      discardPileSize = 0; 
      
}

MagicCard::~MagicCard(){
      for (int i = 0; i < playerCount; i++) {
            delete[] players[i].cards;
      }

      delete[] players;
      delete[] drawPile;
      delete[] discardPile;
}

int MagicCard::findPlayerIndex(const int playerID) const {
    for (int i = 0; i < playerCount; i++) {
        if (players[i].id == playerID) {
            return i;  
        }
    }
    return -1;
}

void MagicCard::addPlayer(const int playerID, const string name){
      Player* newPlayers = new Player[static_cast<unsigned long>(playerCount + 1)];

      for(int i = 0; i < playerCount; i++){
            newPlayers[i] = players[i];
      }

      newPlayers[playerCount] = Player(playerID, name);

      delete[] players;
      players = newPlayers;
      playerCount++;
      cout << "Added player " << name << " with ID " << playerID << "." << endl;
}

void MagicCard::removePlayer(const int playerID){

      int index = findPlayerIndex(playerID);

      if (index == -1) {
            cout << "cannot remove player. there is no player with ID " << playerID << "." << endl;
            return;
      }

      Player* newPlayers = new Player[static_cast<unsigned long>(playerCount - 1)];
      for(int i = 0; i < index; i++){
            newPlayers[i] = players[i];
      }

      for(int j = index + 1; j < playerCount; j++){
            newPlayers[j-1]=players[j];
      }

      delete[] players[index].cards; 
      delete[] players;
      players = newPlayers;
      playerCount--;
      cout << "Removed player " << playerID << "." << endl;
}

void MagicCard::printPlayers() const {
    if (playerCount == 0) {
        cout << "Cannot print players. There is no player in the game." << endl;
        return;
    }

    Player* sortedPlayers = new Player[static_cast<unsigned long>(playerCount)];


    for (int i = 0; i < playerCount; i++) {
        sortedPlayers[i] = players[i];
    }

    for (int i = 0; i < playerCount - 1; i++) {
        for (int j = 0; j < playerCount - i - 1; j++) {
            if (sortedPlayers[j].id > sortedPlayers[j + 1].id) {
                Player temp = sortedPlayers[j];
                sortedPlayers[j] = sortedPlayers[j + 1];
                sortedPlayers[j + 1] = temp;
            }
        }
    }

    cout << "Players :" << endl; 
    for (int i = 0; i < playerCount; i++) {
      cout << "Player " << sortedPlayers[i].id << " : " << sortedPlayers[i].name << endl;
    }

    delete[] sortedPlayers;
}

void MagicCard::setDrawPile(const string drawPile[], const int size);

int main(){
      MagicCard game;
      game.addPlayer(10,"damla");
      game.addPlayer(11,"meltem");
      return 0;
}