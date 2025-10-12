#ifndef MAGICCARD_H
#define MAGICCARD_H
// guard. define if it is left undefined.
#include <string>
using namespace std;

class MagicCard {
public:
    MagicCard();
    ~MagicCard(); //nesneyi yok etmek için. dinamik belleği (new ile açılanları) temizliyor.
};

#endif //ifndef kapatıyor...