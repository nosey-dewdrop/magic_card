
#ifndef MAGICCARD_H
#define MAGICCARD_H

#include <string>
#include "Player.h"
using namespace std;

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

        void setDrawPile();

        bool playerExists(int id); 
        

        //Q4: Why string is using &?
        void addPlayer(int id, const string& name); 
    
        // bunun id'li elemanı nereden sileceğimiz için bulmaya ihtiyacımız var.
        int playerIndex(int id);

        void removePlayer(int id); 
        
        void printPlayers() const; /// print id and names.     
         // if no player give a warning message. ascending order according to ids.
        // Q5: Why const?

        void printDrawPile();

        // void printDiscardPile();

        int findCardIndex(string card)
        void drawCardFromDeck(int id, string cardName);

        // void switchHands();
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