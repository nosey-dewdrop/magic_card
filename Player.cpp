#include "Player.h"
#include <iostream>
using namespace std;

      // private:

      //       int id;           
      //       string name;        
      //       string* hand;  
      //       int handSize;   

      // public:

      //       Player();                           
      //       Player(int newId, string newName);  

      //       ~Player();      

      //       int getId() const; 
      //       string getName() const;

      //       void addCard(const string& card);   
      //       void removeCard(int index);         
      //       void listCards() const;        

Player::Player() {
      id = 0;
      name = "Unnamed";
      hand = nullptr;
      handSize = 0;
      cout << "Player created (default)" << endl;
}

Player::~Player() {
    cout << "Destructor worked!" << endl;
}

int main() {
    cout << "you are now in player!!!!\n" << endl;
    Player player;
    return 0;
}

//  g++ Player.cpp -o main
// ./main