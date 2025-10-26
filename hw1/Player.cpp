#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(){
      /**
       * private things. all players should have different names, etc.
       */
      userName = "nameless";
      id = 0;
      cards = nullptr;
      cardCount = 0;

      // cout<<"\nplayer created!" << endl <<
      //       "id:" << id << endl <<
      //       "username: " << userName 
      //       << endl;

}

Player::Player(int newId, const string& newName){
      id = newId;
      userName = newName;
      cards = nullptr;
      cardCount = 0;
}

Player::~Player(){
      // cout<<"\ndeleted: " << getUserName() << endl;
      // i am not sure man... delete[] cards; 
      // cards array is a dynamic array.

      /**
       * really deleted. 
       * 
       * since it was created on the stack, you don't need to write delete --; 
       * delete is only for the objects created in the heap and dynamic.
       * Player* p = new Player(1, "Damla");
       * delete p;
       * 
       */

      //Q6: Why we do not delete the cards array from the heap?
      //delete[] cards;
      
}

void Player::addCard(const string& newCard) {

    string* newArr = new string[cardCount + 1];

    for (int i = 0; i < cardCount; ++i) {
        newArr[i] = cards[i];
    }

    newArr[cardCount] = newCard;

    delete[] cards;
    cards = newArr;
    cardCount++;

    cout << "\n" <<newCard << " eklendi!!!" << endl;
    cout << "card count is:" << cardCount << endl;

}

int Player::findCardIndex(const string& card){
      for(int i = 0; i < cardCount; i++){
            if(cards[i] == card){
                  return i;
            }
      }
      return -1;
}

void Player::removeCard(const string& card){
      // ek fonksiyon yazmışsın ama tek tek loop yapmaktan daha az run timelı. çok iyi.

      int index = findCardIndex(card);
      if(index == -1){
            cout << "Card not found." << endl;
            return;
      }

      else{
            string* newArr = new string[cardCount - 1];

            for(int i = 0; i < index; i++){
                  newArr[i] = cards[i];
            }

            for(int j = index+1; j < cardCount; j++){
                  newArr[j-1] = cards[j];
            }

            cardCount--;
            delete[] cards;
            cards = newArr;

            cout << "\n" << card << " deleted!!!" << endl;
            cout << "card count is:" << cardCount << endl;
      }
}

int Player::getId() const {
       return id; 
}

string Player::getUserName() const { 
      return userName; 
}

int Player::getCardCount() const{
      return cardCount;
}

void Player::printCards() const{
      if(cardCount != 0){
            cout << "\ncards: " << endl;
            for (int i = 0; i < cardCount; i++){
                  cout << "["<< cards[i] <<"]" << endl;
            }
      }
      else{
            cout << "no cards!!" << endl;
            return;
      }
}

string* Player::getCardsArray() const {
    return cards;
    // Gives the array only. Not tne array elements.
}

void Player:: setUserName(const string& name){
      userName = name;
}

void Player:: setId(int newId){
      id = newId;
}