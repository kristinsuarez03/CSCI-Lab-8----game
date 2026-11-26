#ifndef ARMOR_H
#define ARMOR_H
#include <string>
using namespace std;

class Armor {
private:
    string name;
    int armor;
    int durability;
    int price;

public:
    Armor();
    Armor(string newName);
    string showName();
    void updateName(string newName);
    int showArmor();
    void updateArmor(int newArmor);
    int showDurability();
    void updateDurability(int newDurability);
    int showPrice();
    void updatePrice(int newPrice);
    

};
#endif