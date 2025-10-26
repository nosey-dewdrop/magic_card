#include <iostream>
#include <string>
#include "MagicCard.h"

using namespace std;

int main() {
    MagicCard game;

    int a = -1;
    while(a != 0) {

        cout << "\n==============================" << endl;
        cout << " MAGIC CARD TEST MENU" << endl;
        cout << "==============================\n" << endl;

        cout << "1 - Game operations (players)" << endl;
        cout << "2 - Player operations (hands)" << endl;
        cout << "0 - Exit" << endl;

        cout << "\nChoice: ";
        cin >> a;

        if(a == 1) {

            int choice = -1;
            while(choice != 0) {
                cout << "\n-- Game Operations --" << endl;
                cout << "1 - Add Player" << endl;
                cout << "2 - Remove Player" << endl;
                cout << "3 - Print Players" << endl;
                cout << "4 - Print Draw Pile" << endl;
                cout << "5 - Print Discard Pile" << endl;
                cout << "0 - Back" << endl;

                cout << "\nChoice: ";
                cin >> choice;

                if(choice == 1) {
                    int id;
                    string name;
                    cout << "Enter id: ";
                    cin >> id;
                    cout << "Enter name: ";
                    cin >> name;
                    game.addPlayer(id, name);
                }

                else if(choice == 2) {
                    int id;
                    cout << "Enter id: ";
                    cin >> id;
                    game.removePlayer(id);
                }

                else if(choice == 3) {
                    game.printPlayers();
                }

                else if(choice == 4) {
                    game.printDrawPile();
                }

                else if(choice == 5) {
                    game.printDiscardPile();
                }
            }
        }

        else if(a == 2) {
            int id;
            cout << "Target player ID: ";
            cin >> id;

            if(!game.playerExists(id)) {
                cout << "NO SUCH PLAYER.\n";
                continue;
            }

            int b = -1;
            while(b != 0) {
                cout << "\n-- Player Operations --" << endl;
                cout << "1 - Add card manually" << endl;
                cout << "2 - Show hand" << endl;
                cout << "0 - Back" << endl;

                cout << "\nChoice: ";
                cin >> b;

                if(b == 1) {
                    string cardName;
                    cout << "Enter card name: ";
                    cin >> cardName;
                    game.drawCardFromDeck(id, cardName );
                }
                if(b == 2){
                    game.printCardsOfPlayer(id);
                }
            }
        }

    } 

    return 0;
}

/**
 * 

g++ MagicCard.cpp Player.cpp main.cpp -o main
./main
 */