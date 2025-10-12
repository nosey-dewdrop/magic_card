#include "Card.h"
#include <iostream>
using namespace std;

Card::Card(){
      name = "no name";
      power = 0;
      cout<< "\n⋆˚౨ৎ ⋆.˚" << endl;
      cout << "card created: " << name << " with power " << power << endl;

}

Card::Card(string newName, int newPower){
      name = newName;
      power = newPower;
      cout<< "\n⋆˚౨ৎ ⋆.˚" << endl;
      cout << "card created: " << name << " with power " << power << endl;

}

Card::~Card(){
      cout << "destructed card: " << name <<  endl;
      cout<< "⋆˚౨ৎ ⋆.˚\n" << endl;
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
    cout << "> name: " << name << " power: " << power << endl;
}
