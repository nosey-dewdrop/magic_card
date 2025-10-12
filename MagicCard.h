#ifndef MAGICCARD_H
#define MAGICCARD_H
#include <string>
using namespace std;

class MagicCard {
      private:
            struct Player {
                  int id;
                  string name;
                  string* cards;      
                  int cardCount;  

                  Player() {
                        id = 0;
                        name = "";
                        cards = nullptr;
                        cardCount = 0;
                  }

                  Player(int newId) {
                        id = newId;
                        name = "";
                        cards = nullptr;
                        cardCount = 0;
                  }

                  Player(int newId, string newName) {
                        id = newId;
                        name = newName;
                        cards = nullptr;
                        cardCount = 0;
                  }

            };
            
            Player* players;        
            int playerCount;     
            
            string* drawPile;       
            int drawPileSize;      
            
            string* discardPile;    
            int discardPileSize;    
            
            int findPlayerIndex(const int playerID) const;  
            //bool playerExists(const int playerID) const;     
            //bool playerHasCard(const int playerIndex, const string card) const; 
            //bool cardsMatch(const string card1, const string card2) const;     
            //void removeCardFromPlayer(const int playerIndex, const string card);
            //void addCardToPlayer(const int playerIndex, const string card);   


      public:

            MagicCard();
            ~MagicCard();
            
            void addPlayer(const int playerID, const string name);
            void removePlayer(const int playerID);
            //void switchHands(const int player1ID, const int player2ID);


            void printPlayers() const;
            //void listDrawPile() const;
            // void listDiscardPile() const;
            // void listCardsOfPlayer(const int playerID) const;
            
            // void setDrawPile(const string drawPile[], const int size);
            // void drawCardFromDeck(const int playerID, const int n);
            
            // void play(const int playerID, const string card);
};

#endif