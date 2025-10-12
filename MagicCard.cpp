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

/** @param playerID is a constant because I don't want it to be changed.
*/
int MagicCard::findPlayerIndex(const int playerID) const {
    for (int i = 0; i < playerCount; i++) {
        if (players[i].id == playerID) {
            return i;  
        }
    }
    return -1;
}

bool MagicCard::playerExists(const int playerID) const{
      for (int i = 0; i < playerCount; i++) {
            if (players[i].id == playerID) {
            return true;  
            }
      }
      return false;
}

bool MagicCard::playerHasCard(const int playerIndex, const string card) const{
      
      const Player& player = players[playerIndex];
      for (int i = 0; i < player.cardCount; i++) {
            if (player.cards[i] == card) {
                  return true;
            }
      }
      return false;
}

/** @param playerID and playername. 
 * STEP 1: Create a new array which has a size +1 than the initial.
 * STEP 2: Copy the initial array to the new array.
 * STEP 3: Add the new player to the ending slot.
 * STEP 4: Delete the old array itself. 
 * STEP 5: Let pointer point to the new array.
 * STEP 6: Update count!
 */
void MagicCard::addPlayer(const int playerID, const string name){
      if(playerExists(playerID)){
          return;  
      }

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

/** Copies the input deck into the game's own draw pile.
 * Deletes any existing draw pile if the method is called before to avoid memory leaks.
 * 
 * @param drawPileInput - array of card names
 * @param size - number of cards in the array
 */
void MagicCard::setDrawPile(const string drawPileIn[], const int size){
      
      delete[] drawPile;
      drawPile = new string[size]; 
      drawPileSize = size;

      for(int i = 0; i < drawPileSize; i++){
            drawPile[i] = drawPileIn[i];
      }

      cout << "Draw pile set with " << size << " cards." << endl;
}

void MagicCard::drawCardFromDeck(const int playerID, const int n){
      
      int index = findPlayerIndex(playerID);

      if (index == -1 || drawPileSize == 0 || n <= 0 || n > drawPileSize) {
            return;
      }

      Player& player = players[index];
      int take = n;

      string* newHand = new string[player.cardCount + take];

      for(int i = 0; i < player.cardCount; i++){
            newHand[i] = player.cards[i];
      }

      for(int j = 0; j < take ; j++ ){
            newHand[player.cardCount + j] = drawPile[drawPileSize - 1 - j];
      }

      drawPileSize -= take;
      delete[] player.cards;
      player.cards = newHand;
      player.cardCount += take;
      cout << "> player " << player.name << " drew " << take << " card(s)." << endl;

}

void MagicCard::listCardsOfPlayer(const int playerID) const {

      int index = findPlayerIndex(playerID);

      if (index == -1) {
            cout << "> cannot list cards. there is no player with ID " << playerID << "." << endl;
            return;
      }

      const Player& player = players[index];

      if (player.cardCount == 0) {
            cout << "> " << player.name << " has no cards." << endl;
            return;
      }

      cout << "> " << player.name << "'s hand: " << endl;

      for (int i = 0; i < player.cardCount; i++) {
            cout << i << ". " << player.cards[i] << endl;
      }

      cout << endl;
}

void MagicCard::play(const int playerID, const string card){
      if(!playerExists(playerID) || !playerHasCard(card)){ 
            return;
      }

      if(discardPileSize == 0) { // oyna
            string* newDiscard = new string[1];
            newDiscard[0] = card;
            
            delete[] discardPile;

      }
      else{
            // renk / numara kontrolü burada olacak
      }

}


int main(){
      MagicCard game;
      game.addPlayer(10,"damla");

      string deck[] = {"Fireball", "Healing Light", "Shield", "Storm"};
      game.setDrawPile(deck, 4);

      game.drawCardFromDeck(10, 2); 
      game.listCardsOfPlayer(10);

      // cout << game.playerExists(12) << endl;

      return 0;
}