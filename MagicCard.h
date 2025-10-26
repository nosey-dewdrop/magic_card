
#ifndef MAGICCARD_H
#define MAGICCARD_H

#include <string>
#include "Player.h"
using namespace std;

class MagicCard{

    private:

        Player* players;   
        // bu players arrayini gösteren bir player pointerı. sürekli yeni şey oluşturacağız. o
        Player* currentPlayer;

        int playerCount;
        // sürekli eksiltip çıkaracağımız için counter tutalım.
        string* drawPile;   
        string* discardPile; 
        int drawCount, discardCount; // aynı anda birkaç decleration.

    public:

        MagicCard();
        ~MagicCard();
        // const because doN't change it by mistake.

        int getDrawCount() const;
        int getDiscardCount() const;
        string topDiscard() const;
        Player& getPlayerById(int id);


        void setDrawPile();

        void drawCardFromDeck(int id, int n);
        void drawCardFromDeck(int id, const string& cardName);

        void playCard(int id, const string& cardName);

        bool playerExists(int id); // must check if a player exists in the player list by id
        int playerIndex(int id);
        void addPlayer(int id, const string& name); // must add a player to the player list. but should check if it's unique.
        
        void removePlayer(int id); // must remove a player from the player list by id
        
        void printPlayers() const; /// print id and names.
        // if no player give a warning message. ascending order according to. ids.

        void printDrawPile();
        // void switchHands();

        /**
         * 
         * 
        drawCardFromTopForPlayer(int id)
		removeCardFromPlayer(int id, string card)
    	printCardsOfPlayer(int id)
		printDrawPile()
		printDiscardPile()
         */

};

#endif