#include "MagicCard.h"
#include <iostream>
using namespace std;

MagicCard::MagicCard() {
    players = nullptr;
    currentPlayer = nullptr;
    playerCount = 0;

    drawPile = nullptr;
    discardPile = nullptr; // avoid garbage 

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
    // MagicCard bir player listemiz var. oraya bir player ekleyeceğiz.

    if(!playerExists(id)){
        Player newPlayer(id, name);
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
    
    else{
        cout << "Cannot add player. ID " << id << " already exists." << endl;
        return;
    }
}

void MagicCard::removePlayer(int id){

    if(playerExists(id)){
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

    else{
        
        cout << "Cannot remove player. There is no player with ID "<< id << endl;
    }
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
buralardan sonra biraz karışık.
mesela adamın hem id hem ismi var. ama indexini sadece proıgramcı biliyor kullanıcı değil.
programın bazen ihtiyacı var bu veriye.

ama düşünmek lazım belki eklemeler olabilir.
*/
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

/*
hangi id sahip kullanıcı hangi indexli kartı çekecek. 
ama kullanıcı sadece kart string ismini biliyor.*/
void MagicCard::drawCardFromDeck(int id, int n){
    /*
    şu anda id biliyorum. index bulurum. */ 

    if(!playerExists(id)){
        cout << "Cannot draw card. Player does not exist." << endl;
        return;
    }

    if(n > drawCount){
        cout << "Cannot draw card. The input index is not valid." << endl;
        return;
    }
    
    else{
        string name = players[playerIndex(id)].getUserName();
        int index = n-1;
        string card = drawPile[index];
        cout << name << " drew card " << card << " from the draw pile." << endl;

        players[playerIndex(id)].addCard(drawPile[index]);
        /*
        5. kartı çekiyorum diyprsa 4. index sil.
        yeni arraye 
        0-1-2-3 koy. 
        - 4. index silindi.
        4-5-6 indexe yenilerini koy. eski 5-6-7 yani. 
        dinamik array olacak. */

        string* newDrawPile = new string[drawCount-1];

        for(int i = 0; i < index; i ++){
            newDrawPile[i] = drawPile[i];
        }

        for(int j = index; j < drawCount; j++){
            newDrawPile[j] = drawPile[j+1];
        }

        drawCount--;
        delete[] drawPile;
        drawPile = newDrawPile;

    }

}

// overload olduğu için tekrardan .h yazmadık.

void MagicCard::drawCardFromDeck(int id, string& cardName){
    if(!playerExists(id)){
        cout << "Cannot draw card. Player does not exist." << endl;
        return;
    }
    

}
// void MagicCard:: switchHands(int id1, int id2){
//     if(!playerExists(id1) || !playerExists(id2)){
//         cout << "Cannot switch hands. One or both players do not exist."<< endl;
//     }
// }

void MagicCard::printDrawPile(){
    for(int i = 0; i < drawCount; i++){
        cout << "[" << drawPile[i] << "]";
    }
}


int MagicCard::getDrawCount() const {
    return drawCount;
}

int MagicCard::getDiscardCount() const {
    return discardCount;
}

string MagicCard::topDiscard() const {
    if(discardCount > 0)
        return discardPile[discardCount-1];
    return "";
}

Player& MagicCard::getPlayerById(int id) {
    return players[playerIndex(id)];
}

/*

g++ MagicCard.cpp Player.cpp -o MagicCard

./main

*/