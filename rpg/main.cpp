//  Abel Anand
#include <iostream>
#include <string>
#include <stdio.h>
#include <thread>
#include <unistd.h>
#include <time.h>

//declaring functions
using namespace std;
void heathCheck(int);
void gameOver();
void skip();
void menu();
void planetMenu();
int Scario(int, int);
int Goran(int, int);
int Borjad(int, int);
int Freece(int, int);
int Poyrad(int, int);
int Attack(int, int);







//player struct
struct player {
    string name;
    int health;
    int weaponDamage;
};












int main() {
    srand(time(0));
    string name;
    bool quit = false;
    int planetChoice;
    cout << "Please Enter Player Name:\n";
    cin >> name;
    player player1;
    player1.name = name;
    if (player1.name == "Abel" || player1.name == "abel") {
        player1.health = 100000000;
        player1.weaponDamage = 100000000;
    }
    else {
        player1.health = 100;
        player1.weaponDamage = 50;
    }
    cout << "Hi " << name << " welcome to The Adventures of string name;\nYour task is to survive\nIf you die, all aquired items will be lost\n";
    skip();
    bool scario = false;
    bool goran = false;
    bool borjad = false;
    bool freece = false;
    bool poyrad = false;
    int scarioPlayed = 0;
    int goranPlayed = 0;
    int borjadPlayed = 0;
    int freecePlayed = 0;
    int poyradPlayed = 0;
    cout << "Choose the planet you want to start at.\nYou can only change planets when you finish the mission on the planet\nHint: Choose Poyrad last\n";
    cout << "How to play: Your enemy will do anywhere from 1 - 20 damage on you, you will either dodge, or shoot. Each enemy can be killed with two shots\n";
    while (!quit) {
        planetMenu();
        cin >> planetChoice;
        skip();
        cout << "Health = " << player1.health << "   Weapon Damage = " << player1.weaponDamage << endl;
        switch(planetChoice) {
            case 1:
                scario = true;
                break;
            case 2:
                goran = true;
                break;
            case 3:
                borjad = true;
                break;
            case 4:
                freece = true;
                break;
            case 5:
                poyrad = true;
                break;
        }
        if (scario == true) {
            if (scarioPlayed == 0) {
                player1.health = Scario(player1.health, player1.weaponDamage);
                cout << "First letter: S\n";
                skip();
            }
            else {
                cout << "You already went to this planet, choose another one\n";
            }
        }
        else if (goran == true) {
            if (goranPlayed == 0) {
                player1.health = Goran(player1.health, player1.weaponDamage);
                cout << "Second letter: K\n";
                skip();
            }
            else {
                cout << "You already went to this planet, choose another one\n";
            }
        }
        else if (borjad == true) {
            if (borjadPlayed == 0) {
                player1.health = Borjad(player1.health, player1.weaponDamage);
                cout << "Third letter: Y\n";
                skip();
            }
            else {
                cout << "You already went to this planet, choose another one\n";
            }
        }
        else if (freece == true) {
            if (freecePlayed == 0) {
                player1.health = Freece(player1.health, player1.weaponDamage);
                cout << "Fourth letter: Z\n";
                skip();
            }
            else {
                cout << "You already went to this planet, choose another one\n";
            }
        }
        else if (poyrad == true) {
            if (poyradPlayed == 0) {
                cout << "Fifth letter: M\n";
                player1.health = Poyrad(player1.health, player1.weaponDamage);
                skip();
            }
        }
    }
}









//Functions
void healthCheck(int health) {
    if (health <= 0) {
        gameOver();
    }
}

void gameOver() {
    cout << "Game over\n";
    //add player stats
    exit(0);
}

void skip() {
    for (int i = 0; i < 10; i++) {
        cout << endl;
    }
}

void menu() {
    int choice;
    cout << "Quit Game(1)   Resume(2)\n";
    cin >> choice;
    switch(choice) {
        case 1:
            gameOver();
            break;
        case 2:
            break;
        default:
            menu();
    }
}

void planetMenu() {
    cout << "1. Scario(Homeworld)\n2. Goran(Dwelling of the androids)\n3. Borjad(Land of Gold)\n4. Freece(Desert of ice\n5. Poyrad(Land of the Ogres)\n";
}



//Planets
int Scario(int playerHealth, int playerWeaponDamage) {
    cout << "You go to your home planet, Scario. When you can find a landing pad in the city, you land in a forest. As you hike to the city, you meet a ghoul.\n";
    sleep(3);
    cout << "The ghoul asks you a question, \"Will you find the ghoul's artifact?\"" << "    What's that" << "    You don't need to know that, just find it in Jerk's Junkyard" <<  "    Fine, i'll get it for you\n";
    sleep(4);
    cout << "Jerk's Junkyard(Where all jerks hang out)\n";
    sleep(2);
    cout << "As you enter, you see about 10 goons standing around a pyramid shaped object, that must be it.\nYou approach them, but they raise their guns at you\nYou flip a table and take cover\n";
    for (int i = 0; i < 10; i++) {
        cout << "Goon " << i + 1 << endl;
        playerHealth = Attack(playerHealth, playerWeaponDamage);
    }
    return playerHealth;
}

int Goran(int playerHealth, int playerWeaponDamage) {
    Attack(playerHealth, playerWeaponDamage);
    return playerHealth;
}

int Borjad(int playerHealth, int playerWeaponDamage) {
    Attack(playerHealth, playerWeaponDamage);
    return playerHealth;
}

int Freece(int playerHealth, int playerWeaponDamage) {
    Attack(playerHealth, playerWeaponDamage);
    return playerHealth;
}

int Poyrad(int playerHealth, int playerWeaponDamage) {
    Attack(playerHealth, playerWeaponDamage);
    return playerHealth;
}






//player and enemy functions
int Attack(int playerHealth, int playerWeaponDamage) {
    bool enemyDeath = false;
    int enemyHealth = 100;
    int playerChoice;
    while (!enemyDeath) {
        if (enemyHealth <= 0) {
            cout << "You killed the enemy\n";
            enemyDeath = true;
            break;
        }
        if (playerHealth <= 0) {
            gameOver();
        }
        cout << "1. Hit   2. Dodge\n";
        cin >> playerChoice;
        int hitMiss = (rand() % 2) + 1;
        int enemyDamage = (rand() % 20) + 1;
        if (playerChoice == 1) {
            enemyHealth -= playerWeaponDamage;
            if (hitMiss == 1) {
                cout << "The enemy hit you for " << enemyDamage << endl;
                playerHealth -= enemyDamage;
            }
            else {
                cout << "The enemy missed\n";
            }
        }
        else if (playerChoice == 2) {
            cout << "No Damage done, No Damage taken\n";
        }
        else {
            cout << "-10 health for your ignorance of instructions\n";
            playerHealth -= 10;
        }
        
    }
    return playerHealth;
}
