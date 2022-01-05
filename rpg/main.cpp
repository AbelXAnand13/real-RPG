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
int enemyAttack(int, int);







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
    bool scario;
    bool goran;
    bool borjad;
    bool freece;
    bool poyrad;
    int scarioPlayed = 0;
    int goranPlayed = 0;
    int borjadPlayed = 0;
    int freecePlayed = 0;
    int poyradPlayed = 0;
    cout << "Choose the planet you want to start at.\nYou can only change planets when you finish the mission on the planet\nHint: Choose Poyrad last\n";
    cout << "How to play: Your enemy will do anywhere from 1 - 20 damage on you, you will either dodge, or shoot. Each enemy can be killed with two shots\n";
    planetMenu();
    while (!quit) {
        cin >> planetChoice;
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
            }
            else {
                cout << "You already went to this planet, choose another one\n";
            }
        }
        else if (goran == true) {
            if (goranPlayed == 0) {
                player1.health = Goran(player1.health, player1.weaponDamage);
            }
            else {
                cout << "You already went to this planet, choose another one\n";
            }
        }
        else if (borjad == true) {
            if (borjadPlayed == 0) {
                player1.health = Borjad(player1.health, player1.weaponDamage);
            }
            else {
                cout << "You already went to this planet, choose another one\n";
            }
        }
        else if (freece == true) {
            if (freecePlayed == 0) {
                player1.health = Freece(player1.health, player1.weaponDamage);
            }
            else {
                cout << "You already went to this planet, choose another one\n";
            }
        }
        else if (poyrad == true) {
            if (poyradPlayed == 0) {
            player1.health = Poyrad(player1.health, player1.weaponDamage);
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
    cout << "Game over";
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
    cout << "You go to your home planet, Scario. When you can find a landing pad in the city, you land in a forest. As you hike to the city, you meet a ghoul";
    enemyAttack(playerHealth, playerWeaponDamage);
    return playerHealth;
}

int Goran(int playerHealth, int playerWeaponDamage) {
    enemyAttack(playerHealth, playerWeaponDamage);
    return playerHealth;
}

int Borjad(int playerHealth, int playerWeaponDamage) {
    enemyAttack(playerHealth, playerWeaponDamage);
    return playerHealth;
}

int Freece(int playerHealth, int playerWeaponDamage) {
    enemyAttack(playerHealth, playerWeaponDamage);
    return playerHealth;
}

int Poyrad(int playerHealth, int playerWeaponDamage) {
    enemyAttack(playerHealth, playerWeaponDamage);
    return playerHealth;
}






//player and enemy functions
int Attack(int playerHealth, int playerWeaponDamage) {
    bool playerDeath = false;
    bool enemyDeath = false;
    int health = 100;
    while (!enemyDeath) {
        if (health <= 0) {
            cout << "You killed the enemy\n";
            enemyDeath = true;
        }
        if (playerHealth <= 0) {
            gameOver();
        }
        int hitMiss = (rand() % 2) + 1;
        if (hitMiss == 1) {
            int damage = (rand() % 20) + 1;
            cout << "The enemy hit you for " << damage << " damage\n";
            playerHealth -= damage;
        }
        else {
            cout << "The enemy missed\n";
            health -= playerWeaponDamage;
        }
    }
    return playerHealth;
}
