
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

    public:
        MagicCard();
        ~MagicCard();

        string getCardName() const;
        void setCardName(const string& name);

        void playerExists(); // must check if a player exists in the player list by id
        void addPlayer(); // must add a player to the player list. but should check if it's unique.
        void removePlayer(); // must remove a player from the player list by id
        void printPlayers(); /// print id and names.
        // if no player give a warning message. ascending order according to. ids.

}
#endif