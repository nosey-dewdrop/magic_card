#include "Card.h"
#include <iostream>
using namespace std;

Card::Card(){
      name = "no name";
      power = 0;
      cout<< ">card created: " << name << endl;
}

Card::Card(string newName, int newPower){
      name = newName;
      power = newPower;
      cout<< ">card created: " << name << "\n* power: " << power << endl;

}

Card::~Card(){
      cout<< ">card destructed: " << name << endl;

}

string Card::getName() const{
      return name;
}

int Card::getPower() const{
      return power;
}

void Card::setPower(int newPower) {
    power = newPower;
}

void Card::printCard() const {
    cout << "\n* name:" << getName() << "\n*power: " << getPower() << endl;
}
