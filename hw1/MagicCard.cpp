#include "MagicCard.h"
#include <iostream>
using namespace std;

MagicCard::MagicCard() {

    players = nullptr;
    // When it is goin on turns.
    playerCount = 0;

    drawPile = nullptr;
    discardPile = nullptr; // avoid garbage 
    // Q8: What is garbage and why it is important?

    drawCount = 0;
    discardCount = 0;    

    setDrawPile();
}

MagicCard::~MagicCard() {

    delete[] players;  // cards has a possibility to cause memory leak...      
    delete[] discardPile;   
    delete[] drawPile;
}

void MagicCard::setDrawPile(){

    string fullDeck[40] = {
        "R1","R2","R3","R4","R5","R6","R7","R8","R9","R10",
        "Y1","Y2","Y3","Y4","Y5","Y6","Y7","Y8","Y9","Y10",
        "G1","G2","G3","G4","G5","G6","G7","G8","G9","G10",
        "B1","B2","B3","B4","B5","B6","B7","B8","B9","B10"
    };

    drawCount = 40;
    drawPile = new string[drawCount];

    for(int i = 0; i < drawCount; i++){
        drawPile[i] = fullDeck[i];
    }

    cout << "– Draw pile has been initialized." << endl;
}

void MagicCard::addPlayer(int id, const string& name){

    if(playerExists(id)) {
        cout << "Cannot add player. ID " << id << " already exists." << endl;
        return;
    }

    Player newPlayer(id, name); 
    //Q9: Is it true to use the initializor like this? Sho the new object has all the attributes, right?

    Player* newPlayers = new Player[playerCount + 1];

    for(int i = 0; i < playerCount; i++){
        newPlayers[i] = players[i];
    }

    newPlayers[playerCount] = newPlayer;
    cout<< "Added player "<< name << " with ID " << id << "." << endl;

    delete[] players; // delete the list which the pointer points to.
    players = newPlayers; // let it point new one. and newPlayer pointer will be deleted automatically.
    playerCount++;

}

int MagicCard::playerIndex(int id){
    
    if(playerExists(id)){
        for(int i = 0; i < playerCount; i++){
            if(players[i].getId() == id){
                return i;
            }
        }
    }
    return -1;
}

void MagicCard::removePlayer(int id){

    if(!playerExists(id)){
        cout << "Cannot remove player. There is no player with ID "<< id << endl;
        return;
    }

    int index = playerIndex(id);
    Player* newPlayers = new Player[playerCount-1];

    for(int i = 0; i < index; i++ ){
        newPlayers[i] = players[i];
    }

    for(int j = index; j < playerCount; j++){
        newPlayers[j-1] = players[j];
    }

    cout << "Removed player " << id << "." << endl;
    delete[] players;
    players = newPlayers;
    playerCount--;

}

void MagicCard::printPlayers() const{

    if(playerCount != 0){
        cout << "– Players :" << endl;
        for(int i = 0; i < playerCount; i++){
            cout << "Player " << players[i].getId() << ": " << players[i].getUserName() << endl;
        }
    }

    else{
        cout << "Cannot print players. There is no player in the game." << endl;
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


/*
hangi elemanda işlem yaptığımızı onun id vererek göstermiştik. isim değil id unique olmalıydı.
*/

// kartın ismini giriyorum, index veriyor. ama hangi deste üzerinden gideceğimi bilmediğim içn şu anda drawPileCount kadar yaptım.
int MagicCard::findCardIndex(string card){
    for(int i = 0; i < drawCount; i++){
        if(card == drawPile[i]){
            return i;
        }
    }
    return -1;
}

void MagicCard::drawCardFromDeck(int id, string cardName){

    int index = findCardIndex(cardName);

    if(!playerExists(id)){
        cout << "Cannot draw card. Player does not exist." << endl;
        return;
    }

    if( index > drawCount || index == -1){
        cout << "Cannot draw card. The input index is not valid." << endl;
        return;
    }
         
    cout << players[playerIndex(id)].getUserName() << " drew card " << cardName << " from the draw pile." << endl;
    players[playerIndex(id)].addCard(cardName);

    string* newCards = new string[drawCount-1];

    for(int i = 0; i < index; i++){
        newCards[i] = drawPile[i];
    }

    for(int j = index; j < drawCount; j++){
        newCards[j] = drawPile[j+1];
    }

    delete[] drawPile;
    drawPile = newCards;
    drawCount--;
}

void MagicCard:: printCardsOfPlayer(int id){
    players[playerIndex(id)].printPlayerCards();
}


void MagicCard::printDrawPile(){

    if(drawCount == 0){
        return;
    }

    for(int i = 0; i < drawCount; i++){
        cout << "[" << drawPile[i] << "]";
    }
}

void MagicCard::printDiscardPile(){

    if(drawCount == 0){
        return;
    }

    for(int i = 0; i < discardCount; i++){
        cout << "[" << discardPile[i] << "]";
    }
}



// overload olduğu için tekrardan .h yazmadık.

// void MagicCard:: switchHands(int id1, int id2){
//     if(!playerExists(id1) || !playerExists(id2)){
//         cout << "Cannot switch hands. One or both players do not exist."<< endl;
//     }

//     string* temp = 
// }


// int MagicCard::geDrawCount() const {
//     return drawCount;
// }

// int MagicCard::getDiscardCount() const {
//     return discardCount;
// }

// string MagicCard::topDiscard() const {
//     if(discardCount > 0)
//         return discardPile[discardCount-1];
//     return "";
// }

// Player& MagicCard::getPlayerById(int id) {
//     return players[playerIndex(id)];
// }

/*

g++ MagicCard.cpp Player.cpp -o MagicCard

./main

*/