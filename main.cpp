#include <iostream>
#include <string>
#include "MagicCard.h"

using namespace std;

int main() {
    MagicCard game;
    int choice = -1;

    while(choice != 0) {
        cout << "\n==============================" << endl;
        cout << " MAGIC CARD TEST MENU" << endl;
        cout << "==============================\n" << endl;

        cout << "1 - Game operations (players)" << endl;
        cout << "2 - Player operations (hands)" << endl;
        cout << "0 - Exit" << endl;

        cout << "\nChoice: ";
        cin >> choice;

        // ---------------- GAME OPS ----------------
        if(choice == 1) {
            int sub = -1;
            while(sub != 0) {
                cout << "\n-- Game Operations --" << endl;
                cout << "1 - Add Player" << endl;
                cout << "2 - Remove Player" << endl;
                cout << "3 - Print Players" << endl;
                cout << "4 - Print Draw Pile (count only)" << endl;
                cout << "5 - Print Discard Pile (top only)" << endl;
                cout << "0 - Back" << endl;

                cout << "\nChoice: ";
                cin >> sub;

                if(sub == 1) {
                    int id;
                    string name;
                    cout << "Enter id: ";
                    cin >> id;
                    cout << "Enter name: ";
                    cin >> name;
                    game.addPlayer(id, name);
                }

                else if(sub == 2) {
                    int id;
                    cout << "Enter id: ";
                    cin >> id;
                    game.removePlayer(id);
                }

                else if(sub == 3) {
                    game.printPlayers();
                }

                else if(sub == 4) {
                    cout << "Draw count = " << game.getDrawCount() << endl;
                }

                else if(sub == 5) {
                    cout << "Discard count = " << game.getDiscardCount() << endl;
                    if(game.getDiscardCount() > 0)
                        cout << "Top = " << game.topDiscard() << endl;
                }
            }
        }

        // ---------------- PLAYER OPS ----------------
        else if(choice == 2) {
            int id;
            cout << "Target player ID: ";
            cin >> id;

            if(!game.playerExists(id)) {
                cout << "NO SUCH PLAYER.\n";
                continue;
            }

            int sub = -1;
            while(sub != 0) {
                cout << "\n-- Player Operations --" << endl;
                cout << "1 - Add card manually" << endl;
                cout << "2 - Remove card manually" << endl;
                cout << "3 - Show hand" << endl;
                cout << "0 - Back" << endl;

                cout << "\nChoice: ";
                cin >> sub;

                if(sub == 1) {
                    int n;
                    cout << "Enter card index: ";
                    cin >> n;
                    game.drawCardFromDeck(id, n);
                }

                else if(sub == 2) {
                    string card;
                    cout << "Enter card to remove: ";
                    cin >> card;
                    game.getPlayerById(id).removeCard(card);
                }

                else if(sub == 3) {
                    game.getPlayerById(id).printCards();
                }
            }
        }

    } // while choice

    return 0;
}

/**
 * 

g++ MagicCard.cpp Player.cpp main.cpp -o main
./main
 */