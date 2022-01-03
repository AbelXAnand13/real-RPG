//  Abel Anand
#include <iostream>
#include <string>
#include <stdio.h>
#include <thread>
#include <unistd.h>
#include <curses.h>

//declaring functions
using namespace std;
void heathCheck(int);
void gameOver();
void skip();
void menu();
void planetMenu();
int Scario(int);
int Goran(int);
int Borjad(int);
int Freece(int);
int Poyrad(int);

struct player {
    string name;
    int health;
};

int main() {
    string name;
    bool quit = false;
    int planetChoice;
    cout << "Please Enter Player Name:\n";
    cin >> name;
    player player1;
    player1.name = name;
    player1.health = 100;
    int playerHealth = player1.health;
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
    int freecePLayed = 0;
    int poyradPlayed = 0;
    cout << "Choose the planet you want to start at.\nYou can only change planets when you finish the mission on the planet\nHint: Choose Poyrad last\n";
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
            Scario(playerHealth);
        }
        else if (goran == true) {
            Goran(playerHealth);
        }
        else if (borjad == true) {
            Borjad(playerHealth);
        }
        else if (freece == true) {
            Freece(playerHealth);
        }
        else if (poyrad == true) {
            Poyrad(playerHealth);
        }
    }
}

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

int Scario(int health) {
    return health;
}

int Goran(int health) {
    return health;
}

int Borjad(int health) {
    return health;
}

int Freece(int health) {
    return health;
}

int Poyrad(int health) {
    return health;
}
