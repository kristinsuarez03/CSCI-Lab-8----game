#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H
using namespace std;
class GameCharacter {
private:
    string name;
    int health;
    int attackPower;
    int gold;

public:   
    void introduce();
    void attack();
    GameCharacter();
    GameCharacter(string newName);
    string showName() const;
    void updateName(string newName);
    int showHealth() const;
    void updateHealth(int newHealth);
    int showattackPower() const;
    void updateattackPower(int newattackPower);
    int showGold() const;
    void updateGold(int newGold);
};
#endif