
#ifndef MAGICCARD_H
#define MAGICCARD_H

#include <iostream>
#include <string>
#include "Player.h"
using std::string;

class MagicCard{

    private:

        Player* players;   
        int playerCount; 
              
        string* drawPile;   
        int drawCount;

        string* discardPile; 
        int discardCount; 

    public:

        MagicCard();

        ~MagicCard();
        //  Q1: What does it really do, so we don't need to delete the cards dynamic array from each player?

        void setDrawPile(const string drawPile[], const int size); 

        bool playerExists(int id); 
        

        //Q4: Why string is using &?
        void addPlayer(int id, const string& name); 
    
        // bunun id'li elemanı nereden sileceğimiz için bulmaya ihtiyacımız var.
        int playerIndex(int id);

        void removePlayer(int id); 
        
        void printPlayers() const; /// print id and names.     
         // if no player give a warning message. ascending order according to ids.
        // Q5: Why const?

        void listDrawPile() const;

        void listDiscardPile() const;

        int findCardIndex(string card);
        void drawCardFromDeck(int id, int n);

        void listCardsOfPlayer(int id) const;

        bool inGame(int id);

        void switchHands(const int player1ID, const int player2ID);

        void play(const int playerID, const string card);
        
        /*
        you can do it. hands of th eplayers are just pointer arrays.
        */

        /**
        
        drawCardFromTopForPlayer(int id)

		removeCardFromPlayer(int id, string card)

    	printCardsOfPlayer(int id)

		printDiscardPile()

        int getDrawCount() const;

        int getDiscardCount() const;

        string topDiscard() const;


        
        Player getPlayerById(int id); 

        Player getPlayerByName(string userName); 
        // Q2: Why it was a & referance actually? I deleted it.


        //Q10: Why need it when it is played by other place?
        void playCard(int id, const string& cardName);


         */

};

#endif