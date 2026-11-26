#include <iostream>
#include <vector>
#include "gamecharacter.h"
#include "weapons.h"
#include "armor.h"
using namespace std;
// turns: fight(choose weak medium strong), shop(), rest, quit
int main(){
    cout << "You just arrived home from a long day of work." << endl;
    cout << "You: Aw man, I can't wait to play my favorite game..." << endl;
    cout << "You sit on the couch in front of the TV and turn on the console." << endl;
    
    cout << endl;

    cout << "====================================" << endl;
    cout << "           [SWORD QUEST]            " << endl;
    cout << "====================================" << endl;
    cout << endl;

    int choice;
    int fightChoice;
    int shopChoice;
    int battleChoice;
    
    int weaponChoice;
    int weaponBonus = 0;
    int weaponDurability = 0;
    string equippedWeapon = "None";
    
    int armorChoice;
    int armorBonus = 0;
    int armorDurability = 0;
    string equippedArmor = "None";

    int enemiesDefeated = 0;
    bool bossBattle = false;
    
    string name;
    bool playing = true;

    cout << "1. Create a hero" << endl;
    cout << "2. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    
    if (choice == 2){
    return 0;
    }
    else if (choice == 1){
        cout << "Enter your hero's name: ";
        cin >> name;
    }
    else{
        cout << "Invalid choice. Exiting the game." << endl;
        return 0;
    }
    
    
    GameCharacter hero;
    hero.updateName(name);
    hero.updateHealth(100);
    hero.updateattackPower(10);
    hero.updateGold(0);
    hero.introduce();
    GameCharacter enemy;
    
    Weapons woodenSword("Wooden sword");
    woodenSword.updateattackPower(15);
    woodenSword.updateDurability(10);
    woodenSword.updatePrice(10);

    Weapons ironSword("Iron sword");
    ironSword.updateattackPower(25);
    ironSword.updateDurability(20);
    ironSword.updatePrice(25);

    Weapons diamondSword("Diamond sword");
    diamondSword.updateattackPower(40);
    diamondSword.updateDurability(30);
    diamondSword.updatePrice(50);
    
    Armor leatherArmor("Leather armor");
    leatherArmor.updateArmor(2);
    leatherArmor.updateDurability(10);
    leatherArmor.updatePrice(10);

    Armor ironArmor("Iron armor");
    ironArmor.updateArmor(5);
    ironArmor.updateDurability(20);
    ironArmor.updatePrice(25);

    Armor diamondArmor("Diamond armor");
    diamondArmor.updateArmor(10);
    diamondArmor.updateDurability(30);
    diamondArmor.updatePrice(50);


    cout << endl;
    cout << "You have chosen to play as " << hero.showName() << "." << endl;
    cout << "You are now ready to embark on your adventure to defeat the evil murder boss guy!!" << endl;
    
    while (playing == true){
        cout << endl;
        cout << "What would you like to do?" << endl;
        cout << "1. Fight" << endl;
        cout << "2. Shop" << endl;
        cout << "3. Rest" << endl;
        cout << "4. Quit" << endl;
        cout << "5. view hero stats" << endl;
        cout << "6. change hero name" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
    

        if (cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        switch(choice){
            case 1:
                cout << endl;
                cout << "You have chosen to fight!" << endl;
                cout << "Choose your opponent: " << endl;
                cout << "1. weak enemy" << endl;
                cout << "2. medium enemy" << endl;
                cout << "3. strong enemy" << endl;
                cout << "4. go back" << endl;
                cout << "Enter your choice: ";
                cin >> fightChoice;
                // Fight logic
                cout << endl;
                if (fightChoice == 1){
                    enemy.updateName("Weak enemy");
                    enemy.updateHealth(20);
                    enemy.updateattackPower(5);
                    enemy.updateGold(10);
                }else if (fightChoice == 2){

                    enemy.updateName("Medium enemy");
                    enemy.updateHealth(50);
                    enemy.updateattackPower(10);
                    enemy.updateGold(20);
                }else if (fightChoice == 3){
                    enemy.updateName("Strong enemy");
                    enemy.updateHealth(100);
                    enemy.updateattackPower(20);
                    enemy.updateGold(50);
                }else if (fightChoice == 4){
                    break;
                } else {
                    cout << "Invalid choice. Please try again." << endl;
                    break;
                }
                while (hero.showHealth() > 0 && enemy.showHealth() > 0){
                    cout << endl;
                    cout << "What would you like to do?" << endl;
                    cout << "1. Attack" << endl;
                    cout << "2. Defend" << endl;
                    cout << "3. Run away" << endl;
                    cout << "Enter your choice: ";
                    cin >> battleChoice;

                    if (cin.fail()){
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Invalid input. Please enter a number." << endl;
                        continue;
                    }

                    if (battleChoice == 1){
                        cout << "You attack the " << enemy.showName() << "!" << endl;
                        enemy.updateHealth(enemy.showHealth() - hero.showattackPower());
                        if (weaponDurability > 0){
                            weaponDurability--;
                            cout << "Your " << equippedWeapon << "'s durability is now " << weaponDurability << "." << endl;
                            if (weaponDurability == 0){
                                cout << "Your " << equippedWeapon << " has broken!" << endl;
                                hero.updateattackPower(hero.showattackPower() - weaponBonus);
                                weaponBonus = 0;
                                equippedWeapon = "None";
                            }
                        }
                        cout << "The " << enemy.showName() << "'s health is now " << enemy.showHealth() << "." << endl;


                        if (enemy.showHealth() <= 0){
                            cout << "You have defeated the " << enemy.showName() << "!" << endl;
                            cout << "You have earned " << enemy.showGold() << " gold." << endl;
                            hero.updateGold(hero.showGold() + enemy.showGold());

                            if (bossBattle == true){
                                cout << endl;
                                cout << "=================================" << endl;
                                cout << "            VICTORY!             " << endl;
                                cout << "=================================" << endl;
                                cout << "You have defeated the evil murder boss guy and saved the world!" << endl;
                                cout << "congratulations! you have won the game!" << endl;
                                playing = false;
                                break;
                            }

                            enemiesDefeated++;
                            cout << "Enemies defeated: " << enemiesDefeated << "/5" << endl;

                            if (enemiesDefeated ==5){
                                bossBattle = true;

                                cout << endl;
                                cout << "You have defeated all five enemies!" << endl;
                                cout << "Suddenly, the ground begins to shake and the sky turns dark." << endl;
                                cout << "A massive shadow looms over you, and you hear a deep, menacing laugh." << endl;
                                cout << "The evil murder boss guy has appeared!" << endl;
                                cout << endl;

                                enemy.updateName("Evil Murder Boss Guy");
                                enemy.updateHealth(150);
                                enemy.updateattackPower(20);
                                enemy.updateGold(100);
                                continue;
                            }
                            break;
                        }
                    } else if (battleChoice == 2){
                            cout << "You prepare to defend yourself!" << endl;
                        } else if (battleChoice == 3){
                            if (bossBattle == true){
                                cout << "You cannot run from the evil murder boss guy!" << endl;
                                continue;
                            } else {
                                cout << "You run away from the " << enemy.showName() << "." << endl;
                                break;
                            }
                        } else {
                            cout << "Invalid choice. Please try again." << endl;
                            continue;
                        }
                    cout << "The " << enemy.showName() << " attacks you!" << endl;
                    int damage = enemy.showattackPower();

                    if (battleChoice == 2){
                        damage = damage / 2;
                    }

                    damage = damage - armorBonus;

                    if (damage < 0){
                        damage = 0;
                    }

                    hero.updateHealth(hero.showHealth() - damage);
                    if (armorDurability > 0){
                        armorDurability--;
                        cout << "Your " << equippedArmor << "'s durability is now " << armorDurability << "." << endl;
                        if (armorDurability == 0){
                            cout << "Your " << equippedArmor << " has broken!" << endl;
                            armorBonus = 0;
                            equippedArmor = "None";
                        }
                    }
                    cout << "Your health is now " << hero.showHealth() << "." << endl;

                    if (hero.showHealth() <= 0){
                        cout << "You have been defeated by the " << enemy.showName() << "." << endl;
                        playing = false;
                        break;
                    }
                    }
                    break;
            case 2:
                cout << endl;
                cout << "You have chosen to shop!" << endl;
                cout << "You have " << hero.showGold() << " gold." << endl;
                cout << endl;
                cout << "Choose an item to purchase: " << endl;
                cout << "1. Weapons" << endl;
                cout << "2. Armor" << endl;
                cout << "3. Strength potion" << endl;
                cout << "4. go back" << endl;
                cout << "Enter your choice: ";
                cin >> shopChoice;
                cout << endl;
                // Shop logic
                if (shopChoice == 1){
                    cout << "Choose a weapon to purchase: " << endl;
                    cout << "You have " << hero.showGold() << " gold." << endl;
                    cout << "1. " << woodenSword.showName() << " - "<< woodenSword.showPrice() << " gold" << endl;
                    cout << "2. " << ironSword.showName() << " - "<< ironSword.showPrice() << " gold" << endl;
                    cout << "3. " << diamondSword.showName() << " - "<< diamondSword.showPrice() << " gold" << endl;
                    cout << "4. go back" << endl;
                    cout << "Enter your choice: ";
                    cin >> weaponChoice;
    
                if (weaponChoice == 1){
                    if (hero.showGold() >= woodenSword.showPrice()){
                        hero.updateGold(hero.showGold() - woodenSword.showPrice());
                        hero.updateattackPower(hero.showattackPower() - weaponBonus + woodenSword.showattackPower());
                        weaponBonus = woodenSword.showattackPower();
                        weaponDurability = woodenSword.showDurability();
                        equippedWeapon = woodenSword.showName();
                        cout << "You have purchased the " << woodenSword.showName() << "!" << endl;
                        cout << "Your attack power is now " << hero.showattackPower() << "." << endl;
                        cout << "You have " << hero.showGold() << " gold left." << endl;
                    } else {
                        cout << "You do not have enough gold to purchase the " << woodenSword.showName() << "." << endl;
                    }
                } else if (weaponChoice == 2){
                    if (hero.showGold() >= ironSword.showPrice()){
                        hero.updateGold(hero.showGold() - ironSword.showPrice());
                        hero.updateattackPower(hero.showattackPower() - weaponBonus + ironSword.showattackPower());
                        weaponBonus = ironSword.showattackPower();
                        weaponDurability = ironSword.showDurability();
                        equippedWeapon = ironSword.showName();
                        cout << "You have purchased the " << ironSword.showName() << "!" << endl;
                        cout << "Your attack power is now " << hero.showattackPower() << "." << endl;
                        cout << "You have " << hero.showGold() << " gold left." << endl;
                    } else {
                        cout << "You do not have enough gold to purchase the " << ironSword.showName() << "." << endl;
                    }
                } else if (weaponChoice == 3){
                    if (hero.showGold() >= diamondSword.showPrice()){
                        hero.updateGold(hero.showGold() - diamondSword.showPrice());
                        hero.updateattackPower(hero.showattackPower() - weaponBonus + diamondSword.showattackPower());
                        weaponBonus = diamondSword.showattackPower();
                        weaponDurability = diamondSword.showDurability();
                        equippedWeapon = diamondSword.showName();
                        cout << "You have purchased the " << diamondSword.showName() << "!" << endl;
                        cout << "Your attack power is now " << hero.showattackPower() << "." << endl;
                        cout << "You have " << hero.showGold() << " gold left." << endl;
                    } else {
                        cout << "You do not have enough gold to purchase the " << diamondSword.showName() << "." << endl;
                    }
                } else if (weaponChoice == 4){
                    break;
                } else { 
                    cout << "Invalid choice. Please try again." << endl;
                }
            }  else if (shopChoice == 2){
                    cout << "Choose an armor to purchase: " << endl;
                    cout << "You have " << hero.showGold() << " gold." << endl;
                    cout << "1. " << leatherArmor.showName() << " - "<< leatherArmor.showPrice() << " gold" << endl;
                    cout << "2. " << ironArmor.showName() << " - "<< ironArmor.showPrice() << " gold" << endl;
                    cout << "3. " << diamondArmor.showName() << " - "<< diamondArmor.showPrice() << " gold" << endl;
                    cout << "4. go back" << endl;
                    cout << "Enter your choice: ";
                    cin >> armorChoice;

                if (armorChoice == 1){
                    if (hero.showGold() >= leatherArmor.showPrice()){
                        hero.updateGold(hero.showGold() - leatherArmor.showPrice());
                        armorBonus = leatherArmor.showArmor();
                        armorDurability = leatherArmor.showDurability();
                        equippedArmor = leatherArmor.showName();
                        cout << "You have purchased the " << leatherArmor.showName() << "!" << endl;
                        cout << "Your damage reduction is now " << armorBonus << "." << endl;
                        cout << "You have " << hero.showGold() << " gold left." << endl;
                    } else {
                        cout << "You do not have enough gold to purchase the " << leatherArmor.showName() << "." << endl;
                    }
                } else if (armorChoice == 2){
                    if (hero.showGold() >= ironArmor.showPrice()){
                        hero.updateGold(hero.showGold() - ironArmor.showPrice());
                        armorBonus = ironArmor.showArmor();
                        armorDurability = ironArmor.showDurability();
                        equippedArmor = ironArmor.showName();
                        cout << "You have purchased the " << ironArmor.showName() << "!" << endl;
                        cout << "Your damage reduction is now " << armorBonus << "." << endl;
                        cout << "You have " << hero.showGold() << " gold left." << endl;
                    } else {
                        cout << "You do not have enough gold to purchase the " << ironArmor.showName() << "." << endl;
                    }
                } else if (armorChoice == 3){
                    if (hero.showGold() >= diamondArmor.showPrice()){
                        hero.updateGold(hero.showGold() - diamondArmor.showPrice());
                        armorBonus = diamondArmor.showArmor();
                        armorDurability = diamondArmor.showDurability();
                        equippedArmor = diamondArmor.showName();
                        cout << "You have purchased the " << diamondArmor.showName() << "!" << endl;
                        cout << "Your damage reduction is now " << armorBonus << "." << endl;
                        cout << "You have " << hero.showGold() << " gold left." << endl;
                    } else {
                        cout << "You do not have enough gold to purchase the " << diamondArmor.showName() << "." << endl;
                    }
                } else if (armorChoice == 4){
                    break;
                } else {
                    cout << "Invalid choice. Please try again." << endl;
                }
            } else if (shopChoice == 3){
                cout << endl;
                cout << "strength potion costs 20 gold." << endl;
                if (hero.showGold() >= 20){
                    hero.updateGold(hero.showGold() - 20);
                    hero.updateattackPower(hero.showattackPower() + 5);
                    cout << "You have " << hero.showGold() << " gold left." << endl;
                    cout << "You have purchased a strength potion!" << endl;
                    cout << "Your attack power is now " << hero.showattackPower() << "." << endl;
                    cout << "You have " << hero.showGold() << " gold left." << endl;
                    } else {
                        cout << "You do not have enough gold to purchase a strength potion." << endl;
                    }
                } else if (shopChoice == 4){
                    break;
                } else {
                    cout << "Invalid choice. Please try again." << endl;
                }
                break;



            case 3:
                cout << "You have chosen to rest!" << endl;
                if (hero.showHealth() >= 100) {
                    cout << "Your health is already full. You cannot rest right now." << endl;
                } else {
                    cout << "You take a rest and regain some health." << endl;
                    hero.updateHealth(hero.showHealth() + 20);
                    if (hero.showHealth() > 100){
                    hero.updateHealth(100);
                    }
                    cout << "Your health has been restored to " << hero.showHealth() << "." << endl;
                }
                // Rest logic
                break;
            case 4:
                playing = false;
                break;
            case 5:
                hero.introduce();
                cout << "Equipped weapon: " << equippedWeapon << endl;
                cout << "Equipped armor: " << equippedArmor << endl;
                cout << "Gold: " << hero.showGold() << endl;
                break;
            case 6:
                cout << "Enter your new hero's name: ";
                cin >> name;
                hero.updateName(name);
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}




