#include "Player.h"
#include <iostream>
using namespace std;        

Player::Player() {
      id = 0;
      name = "unnamed";
      hand = nullptr;
      handSize = 0;
      cout<< "\n⋆˚౨ৎ ⋆.˚" << endl;
      cout << "player created without name!!!" << endl;
}

Player::Player(int newId, string newName) {
    id = newId;          
    name = newName;      
    hand = nullptr;      
    handSize = 0;  
    cout<< "\n⋆˚౨ৎ ⋆.˚" << endl;   
    cout << "player created: " << name << " (ID: " << id << ")\n" << endl;
}

Player::~Player() {
    cout << "destructed! " << name <<  endl;
    cout<< "⋆˚౨ৎ ⋆.˚\n" << endl;
}

int Player::getId() const {
    return id;
}

string Player::getName() const {
    return name;
}

/*parametre olarak ard stringini alıyor.
bunu & ile gösteriyoruz çünkü direkt string alıp bellekte ek veri oluşturmayacağız.
sadece stringin kendisini alıyoruz, referansını alıyoruz. ıkopyasını almıyoruz.
const çünkü edğiştirilmemesi lazım.

hand pointerı bir string array'i gösteriyor.

handSize ise sınıfın içinde var o yüzden girmemize gerek yok.
bu methodun amacı kartı eski desteye eklemek. - heap

eski destemizi yeni desteye koyacağız sona da yeni kartı koyacağız. böylece yeni bir array elde edeceğiz.,
mevcut değiştirilemeyen pointerımız, adres tutucumuz ise yeni array'i tutacak.

memory leak olmaması için de eski array'i sileceğiz. - heap'te oluşturmuştuk.*/

void Player::addCard(const string& card){

      //STEP 1: create a new array exactly one more than the old array.
      string* newHand = new string[handSize + 1];

      //STEP 2: copy the old elements of the array into the new arrayl. leaving the last slot empty.
      for (int i = 0; i < handSize; i++){
            newHand[i] = hand[i];
      }

      //STEP 3: add the new card to the last slot.
      newHand[handSize] = card;

      delete[] hand;
      hand = newHand;

      handSize++;
}

void Player::removeCard(int index){
      if (handSize < index || index <= 0) {
            cout << "> no cards in index " << index << endl;
            return;
      }

      cout<< "> you want to remove: " << hand[index] << endl;
      string* newHand = new string[handSize - 1];

      for (int i = 0; i < index; i++){
            newHand[i] = hand[i];
      }

      for (int j = index + 1; j < handSize; j++){
            newHand[j-1] = hand[j];
      }

      delete[] hand;
      hand = newHand;
      handSize--;
}

void Player::listCards() const {
    if (handSize == 0) {
        cout << name << " has no cards." << endl;
        return;
    }

    cout << name << "'s hand: \n";
    for (int i = 0; i < handSize; i++) {
        cout << i <<"." << hand[i] << endl;
    }

    cout << endl;
}
