
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Player {
    private:
        string userName;
        int id; // must be unique.

        string* cards;  // dynamically allocated array of strings
        int cardCount;
        
    public:
        Player();
        ~Player();

        string getUserName();
        void setUserName();
        int getId();
        void setId();

};

#endif