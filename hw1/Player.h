
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
using std::string;

class Player {
    private:
        string userName;
        int id; 
        string* cards;  // dynamically allocated array of strings
        int cardCount;
        
    public:
        Player();
        Player(int newId, const string& newName);           
        ~Player();

        void addCard(const string& newCard);
        int findCardIndex(const string& card);
        void removeCard(const string& newCard);

        string getUserName() const;    
        int getId() const;
        int getCardCount() const;
        string* getCardsArray() const;
        void printPlayerCards() const;
        void setUserName(const string& name);
        void setId(int newId);

};

#endif