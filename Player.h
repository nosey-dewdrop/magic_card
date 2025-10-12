//

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Player {
      private:
            int id;           
            string name;        
            string* hand;  

            /* a pointer pointing to an adress of a string or a string array.  
            name of the pointer is hand.

            string name = "Damla";
            string* ptr = &name;
            */

            /* why pointer?: hand is not the same.  
            so we spare a space in memory.

            - heap üzerinde handsize kadar bir yer aç. bu yerin ilk elemanının adresini hand pointerına yaz.
            hand = new string[handSize];

            void play() {
            string cards[3]; // stack’
            } deleted when the scope is over.

            - opened until you delete it with delete[] hand because it is opened with "new" keyword in the heap.
            hand = new string[3];
            but it always returns the adress of the first element.

            hand[0] == *(hand + 0) -> 0x1000  
            hand[1] == *(hand + 1) -> 0x1008  
            hand[2] == *(hand + 2) -> 0x1010

            - arrayler sabit boyutlular. adres tutarlar. o yüzden pointer olduğunda bir 3 boyutlu hand dizisini, bir 5 boyutlu hand dizisini gösterir.
            yani dizileri değiştirdik gördüğün gibi ama işaret eden pointer değişmedi.
            böylece hep aynı adres farklı arrayleri gösterd.
            !!!! tabii bu boşa çıkan arrayleri new ile oluşturuyorsun yani heap'te. o yüzden delete ile sil yoksa memory leak olur.

            allocate in memory. if you do not delete it is MEMORY LEAK
            DYNAMIC

            stack memory is managed automatically. deconstructor too when retorn 0;
            so, in deconstructor add delete[] hand;
            */

            int handSize;   

      public:
            Player();                           
            Player(int newId, string newName);  
            ~Player();                         

            int getId() const;
            string getName() const;

            void addCard(const string& card);   
            void removeCard(int index);         
            void listCards() const;             
};

#endif