#ifndef WEAPONS_H
#define WEAPONS_H
using namespace std;
class Weapons {
private:
    string name;
    int attackPower;
    int durability;
    int price;

public:
    Weapons();
    Weapons(string newName);
    string showName();
    void updateName(string newName);
    int showattackPower();
    void updateattackPower(int newattackPower);
    int showDurability();
    void updateDurability(int newDurability);
    int showPrice();
    void updatePrice(int newPrice);
    

};
#endif