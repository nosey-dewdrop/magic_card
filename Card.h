#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std;

class Card {

private:
    string name;
    int power;

public:
    Card();                      
    Card(string newName, int newPower);
    ~Card();

    string getName() const;
    int getPower() const;
    void setPower(int newPower);

    virtual void printCard() const; 
};

#endif

