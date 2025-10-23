#include "Player.h"

Player::Player(){
      userName = "";
      id = 0;
      cards = nullptr;
      cardCount = 0;
}

Player::Player(int newId, const string& newName){
      id = newId;
      userName = newName;
      cards = nullptr;
      cardCount = 0;
}


int Player::getId() const {
       return id; 
}

string Player::getName() const { 
      return name; 
}
