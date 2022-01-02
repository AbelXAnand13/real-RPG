//  Abel Anand
#include <iostream>
#include <string>
#include <stdio.h>
#include <thread>
#include <unistd.h>
#include <curses.h>

//declaring functions
using namespace std;
void heathCheck();
void gameOver();
void skip();
void menu();
void planetMenu();

struct player {
    string name;
    long health;
};

int main() {
    WINDOW *initscr(void); 
    string name;
    bool quit = false;
    cout << "Please Enter Player Name:\n";
    cin >> name;
    player player1;
    player1.name = name;
    player1.health = 100;
    cout << "Hi " << name << " welcome to Warblade\nYour task is to survive\nIf you die, all aquired items will be lost\n";
    skip();
    bool Scario;
    bool Goran;
    bool Borjad;
    bool Freece;
    bool Poyrad;
    cout << "Choose the planet you want to start at.\nYou can only leave when you finish the mission on the planet\n";
    planetMenu();
    while (!quit) {
        
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
