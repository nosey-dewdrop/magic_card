#include <iostream>
#include <string>
#include "MagicCard.h"

using namespace std;

int main(){

    MagicCard game;
    int playerCount = game.getPlayerCount();

    int choice = 0;
    while(playerCount > 0){
        cout << "enter choice" << endl;
        cin >> choice;

        if(choice == 1){
            int id;
            game.addPlayer(id, name);
        }

        else if (choice == 2){

        }
    }

    cout << "game over!!"<< endl;

    return 0;
}

/**
 * 

g++ MagicCard.cpp Player.cpp main.cpp -o main
./main
 */