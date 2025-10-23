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

      cout<<"\nplayer created!" << endl <<
            "id:" << id << endl <<
            "username: " << userName 
            << endl;

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

      delete[] cards;
      
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

int Player::getId() const {
       return id; 
}

string Player::getUserName() const { 
      return userName; 
}

int Player::getCardCount() const{
      return cardCount;
}

void Player::getCards() const{
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


