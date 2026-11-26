#include <iostream>
#include "armor.h"
using namespace std;
    Armor::Armor(){
        name = "unlisted";
        armor = 1;
        durability = 1;
        price = 1;
    }
    Armor::Armor(string newName){
        name = newName;
        armor = 1;
        durability = 1;
        price = 1;
    }
    string Armor::showName(){
        return name;
    }
    void Armor::updateName(string newName){
        name = newName;
    }
    int Armor::showArmor(){
        return armor;
    }
    void Armor::updateArmor(int newArmor){
        armor = newArmor;
    }
    int Armor::showDurability(){
        return durability;
    }
    void Armor::updateDurability(int newDurability){
        durability = newDurability;
    }
    int Armor::showPrice(){
        return price;
    }
    void Armor::updatePrice(int newPrice){
        price = newPrice;
    }