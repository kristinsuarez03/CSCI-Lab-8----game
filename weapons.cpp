#include <iostream>
#include "weapons.h"
using namespace std;
    Weapons::Weapons(){
        name = "unlisted";
        attackPower = 1;
        durability = 1;
        price = 1;
    }
    Weapons::Weapons(string newName){
        name = newName;
        attackPower = 1;
        durability = 1;
        price = 1;
    }
    string Weapons::showName(){
        return name;
    }
    void Weapons::updateName(string newName){
        name = newName;
    }
    int Weapons::showattackPower(){
        return attackPower;
    }
    void Weapons::updateattackPower(int newattackPower){
        attackPower = newattackPower;
    }
    int Weapons::showDurability(){
        return durability;
    }
    void Weapons::updateDurability(int newDurability){
        durability = newDurability;
    }
    int Weapons::showPrice(){
        return price;
    }
    void Weapons::updatePrice(int newPrice){
        price = newPrice;
    }