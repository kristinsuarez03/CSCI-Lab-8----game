#include <iostream>
#include "gamecharacter.h"
using namespace std;

void GameCharacter:: introduce(){
    cout << "I am " << name << "!" << endl;
    cout << "Health: " << health << endl;
    cout << "Attack Power: " << attackPower << endl;
}

    

void GameCharacter:: attack() {
    cout << name << " attacks with " << attackPower << " power!" << endl;
}
    
GameCharacter::GameCharacter(){
    name = "";
	health = 100;
	attackPower = 1;
}
   
GameCharacter::GameCharacter(string newName){
    name = newName;
    health = 100;
    attackPower = 5;
}
   
   // TODO 1: Add setters and getters. Decide which member function should be have read-only functionality
string GameCharacter::showName() const {
   return name;
}
void GameCharacter::updateName(string newName){
   name = newName;
}
int GameCharacter::showHealth() const {
   return health;
}
void GameCharacter::updateHealth(int newHealth){
   if (newHealth < 0){
        health = 0;
    } else{
        health = newHealth;
    }
}
int GameCharacter::showattackPower() const { //const makes it read only
   return attackPower;
}
void GameCharacter::updateattackPower(int newattackPower){
   attackPower = newattackPower;
}
int GameCharacter::showGold() const {
    return gold;
}
void GameCharacter::updateGold(int newGold){
    gold = newGold;
}
