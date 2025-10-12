#include "Player.h"
#include "Card.h"
#include "MagicCard.h"
#include <iostream>
using namespace std;

int main() {
    cout << "\n⋆˚౨ৎ ⋆.˚ magic card test started ⋆˚౨ৎ ⋆.˚\n" << endl;

    Player damla(1, "damla");

    Card shield("shield", 5);
    Card sword("sword", 8);
    MagicCard fireball("fireball", 10, "burns the opponent");
    MagicCard heal("healing light", 6, "restores health");

    damla.addCard("shield");
    damla.addCard("fireball");
    damla.addCard("healing light");
    damla.listCards();

    damla.removeCard(1);
    damla.listCards();

    shield.printCard();
    sword.printCard();
    fireball.printCard();
    heal.printCard();

    cout << "\n⋆˚౨ৎ ⋆.˚ end of Program ⋆˚౨ৎ ⋆.˚\n" << endl;
    return 0;
}
