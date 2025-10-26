
#ifndef MAGICCARD_H
#define MAGICCARD_H

#include <string>
#include "Player.h"
using namespace std;

class MagicCard{

    private:

        Player* players;   
        // bu players arrayini gösteren bir player pointerı. sürekli yeni şey oluşturacağız. o
        int playerCount;
        // sürekli eksiltip çıkaracağımız için counter tutalım.

        string* drawPile;   
        string* discardPile; 
        int drawCount, discardCount; // aynı anda birkaç decleration.

    public:

        MagicCard();
        ~MagicCard();
        // const because doN't change it by mistake.

        bool playerExists(int id); // must check if a player exists in the player list by id
        void addPlayer(int id, const string& name); // must add a player to the player list. but should check if it's unique.
        
        // void removePlayer(); // must remove a player from the player list by id
        
        void printPlayers() const; /// print id and names.
        // if no player give a warning message. ascending order according to. ids.

        /**
        drawCardFromTopForPlayer(int id)
		removeCardFromPlayer(int id, string card)
    	printCardsOfPlayer(int id)
		printDrawPile()
		printDiscardPile()
         */

};

#endif