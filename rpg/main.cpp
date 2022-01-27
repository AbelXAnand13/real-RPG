//  Abel Anand
#include <iostream>
#include <string>
#include <stdio.h>
#include <thread>
#include <unistd.h>
#include <time.h>
using namespace std;

//declaring functions
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
int Attack(int, int, int, int);







//player struct
struct player {
    string name;
    int health;
    int weaponDamage;
    int score;
};





// Nothing to see here, just some local variables on vacation
int score = 0;
int weaponDamageBoost;


int main() {
    srand(time(0));
    bool mainQuit = true;
    char mainChoice;
    cout << "Do you want to play THE ADVENTURES OF string name;\nY/N\n";
    cin >> mainChoice;
    mainChoice = toupper(mainChoice);
    switch (mainChoice) {
        case 'Y':
            mainQuit = false;
            break;
        case 'N':
            gameOver();
            break;
        default:
            cout << "You don't know how to read directions, so you are not worthy to play my game\n";
            break;
    }
    bool scario = false;
    bool goran = false;
    bool borjad = false;
    bool freece = false;
    bool poyrad = false;
    int scarioPlayed = 0;
    int goranPlayed = 0;
    int borjadPlayed = 0;
    int freecePlayed = 0;
    while (mainQuit == false){
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
    cout << "Hi " << name << " welcome to The Adventures of string name;\nYour task is to survive\n";
    skip();
    
    string poyradCode = "SKYZM";
    bool poyradQuit;
    int poyradChoice;//if you want to choose a different planet or try the poyrad code again
    string playerCode;//code that the player enters
    cout << "Choose the planet you want to start at.\nYou can only change planets when you finish the mission on the planet\nHint: Choose Poyrad last\n";
    cout << "How to play: Your enemy will do anywhere from 1 - 20 damage on you, you will either dodge, or shoot. Each enemy can be killed with two shots\n";
    while (!quit) {
        planetMenu();
        cin >> planetChoice;
        skip();
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
            default:
                cout << "Please choose a valid planet\n";
                break;
        }
        if (scario == true) {
            if (scarioPlayed == 0) {
                cout << "Health = " << player1.health << "   Weapon Damage = " << player1.weaponDamage << endl;
                player1.health = Scario(player1.health, player1.weaponDamage);
                cout << "First letter: S\n";
                score += 100;
                scario = false;
                scarioPlayed++;
                skip();
            }
            else {
                cout << "You already went to this planet, choose another one\n";
            }
        }
        else if (goran == true) {
            cout << "Health = " << player1.health << "   Weapon Damage = " << player1.weaponDamage << endl;
            if (goranPlayed == 0) {
                player1.health = Goran(player1.health, player1.weaponDamage);
                cout << "Second letter: K\n";
                player1.weaponDamage += weaponDamageBoost;
                score += 100;
                goran = false;
                goranPlayed++;
                skip();
            }
            else {
                cout << "You already went to this planet, choose another one\n";
            }
        }
        else if (borjad == true) {
            cout << "Health = " << player1.health << "   Weapon Damage = " << player1.weaponDamage << endl;
            if (borjadPlayed == 0) {
                player1.health = Borjad(player1.health, player1.weaponDamage);
                cout << "Third letter: Y\n";
                score += 100;
                borjad = false;
                borjadPlayed++;
                skip();
            }
            else {
                cout << "You already went to this planet, choose another one\n";
            }
        }
        else if (freece == true) {
            cout << "Health = " << player1.health << "   Weapon Damage = " << player1.weaponDamage << endl;
            if (freecePlayed == 0) {
                player1.health = Freece(player1.health, player1.weaponDamage);
                cout << "Fourth letter: Z\n";
                score += 100;
                freece = false;
                freecePlayed++;
                skip();
            }
            else {
                cout << "You already went to this planet, choose another one\n";
            }
        }
        else if (poyrad == true) {
            poyradQuit = false;
            cout << "Fifth letter: M\n";
            while (!poyradQuit) {
            cout << "Enter the Full Code(All caps)\n";
            cin >> playerCode;
                if (playerCode == poyradCode) {
            cout << "Health = " << player1.health << "   Weapon Damage = " << player1.weaponDamage << endl;
                player1.health = Poyrad(player1.health, player1.weaponDamage);
                    score += 100;
                poyrad = false;
                poyradQuit = true;
                    mainQuit = true;
                skip();
                }
                else {
                    cout << "1. Try again     2. Choose different planet\n";
                    cin >> poyradChoice;
                    switch (poyradChoice) {
                        case 1:
                            break;
                        case 2:
                            poyradQuit = true;
                            break;
                        }
                    }
                }
            }
        else {
            continue;
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
    cout << "Game over\nScore:" << score;
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
    cout << "You go to your home planet, Scario. When you can't find a landing pad in the city, you land in a forest. As you hike to the city, you meet a ghoul.\n";
    sleep(3);
    cout << "The ghoul asks you a question, \"Will you find the ghoul's artifact?\"" << "    What's that" << "    You don't need to know that, just find it in Jerk's Junkyard" <<  "    Fine, i'll get it for you\n";
    sleep(4);
    cout << "Jerk's Junkyard(Where all jerks hang out)\n";
    sleep(2);
    cout << "As you enter, you see about 10 goons standing around a pyramid shaped object, that must be it.\nYou approach them, but they raise their guns at you\nYou flip a table and take cover\n";
    for (int i = 0; i < 10; i++) {
        cout << "Goon " << i + 1 << endl;
        playerHealth = Attack(playerHealth, playerWeaponDamage, 100, 20);
    }
    cout << "You finish all the goons and take the pyramid, it starts glowing\nYou leave the junkyard and go to the place where you met the ghoul\nIt's still there, hovering over the ground\n\"So, you got the artifact\"     \"Yeah, you could have at least warned me people were protecting it\"\n";
    sleep(5);
    cout << "\"Oh, yes, I knew I forgot to tell a detail\"     \"Yeah, well so what do I get for helping you\"     \"The artifact of course\"     \"So it wasn't for you!\"     \"Oh no, I left out yet another detail, Oh well, good bye\"\n";
    sleep(5);
    cout << "The ghoul vanishes into thin air. You examine the artifact it's still glowing, suddenly you feel better, like a gust of wind flowed through you\n";
    playerHealth += 20;
    cout << "+20 Health\n";
    return playerHealth;
}




int Goran(int playerHealth, int playerWeaponDamage) {
    cout << "You travel to the planet of the androids. You land in the capital Robotron. A robot comes to greet you.\n\"Welcome to Robotron, what brings you here\"     \"I'm just here for some fun\"     \"Then why do you carry a gun\"     \"Like I said, for fun. Anyways, do you know where I can make some money\"\n";
    sleep(5);
    cout << " \"What do you do\"     \"Anything that involves a gun\"     \"Ok, will you do a job for me\"     \"What job\"n     \"You have to rescue my friend, he was captured by a gang.\"     \"How much is the pay\"     \"We'll discuss that after you rescue him\"    \"Fine, give me an advance amount\". The robot gives you 1000 credits\n";
    sleep(5);
    cout << "\"Where is he\"     \"He's being held hostage in the DEN\"     \"Where's that\"     \"I'll show you\". The robot takes you to a giant building in the center of town.     ";
    cout << "\"He's being held in the 50th story, you'll have to sneak to get in there\"     \"Or I could just kill my way there\"\nYou go to the evevator and take it to the 50th floor, there you are greeted by some dangerous looking robots they take out their guns, and you take cover behind a corner\n";
    for (int i = 0; i < 15; i++) {
        cout << "Robot " << i + 1 << endl;
        playerHealth = Attack(playerHealth, playerWeaponDamage, 75, 25);
    }
    cout << "You kill all the robots at make your way to a room, there, you see a robot being electrocuted. You shut off the mechanism and take him off his binds. You carry him to the elevator.\n";
    sleep(5);
    cout << "\"Who are you\"     \"Your friend paid me to rescue you\"     \"Which friend\"     \"The blue one\"     \"I don't have a blue friend\"     \"The one who wears a red bandana\"     Suddenly the robot's face looks scared.\"That's the one who locked me in here\"\n";
    sleep(5);
    cout << "\"After all that bonding I thought we were friends. Now you've insulted me\". The blue robot takes out a golden gun. You recognize it as the 24 carat upgrade, a high damaging upgrade\nHe starts shooting at you and you take cover\n";
    Attack(playerHealth, playerWeaponDamage, 150, 50);
    cout << "You kill the blue robot. He drops his gun, it does 25 more damage than your current gun\n";
    sleep(2);
    cout << "\"Thank you for saving me\"     \"Yeah, no problem\"     \"How much did he owe you\"     \"It's fine, this gun's worth way more\"     \"I can't thank you enough\"     \"I'll be leaving now, i've had enough of Goran for a day\"\n";
    sleep(4);
    cout << "You leave goran with your new gun\n";
    weaponDamageBoost = 10;
    cout << "+10 weapon damage     New weapon upgrade- 24 Carat\n";
    return playerHealth;
}

int Borjad(int playerHealth, int playerWeaponDamage) {
    return playerHealth;
}

int Freece(int playerHealth, int playerWeaponDamage) {
    return playerHealth;
}

int Poyrad(int playerHealth, int playerWeaponDamage) {
    return playerHealth;
}






//player and enemy functions
int Attack(int playerHealth, int playerWeaponDamage, int enemyHealth, int enemyRandDamage) {
    bool enemyDeath = false;
    bool reload = false;
    int playerChoice;
    while (!enemyDeath) {
        if (enemyHealth <= 0) {
            cout << "You killed the enemy\n";
            enemyDeath = true;
            break;
        }
        healthCheck(playerHealth);
        cout << "1. Hit(Assualt rifle)   2. Dodge\n";
        cin >> playerChoice;
        int hitMiss = (rand() % 3) + 1;
        int enemyDamage = (rand() % enemyRandDamage) + 1;
        if (playerChoice == 1) {
            enemyHealth -= playerWeaponDamage;
            if (hitMiss == 1 || hitMiss == 2) {
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
    playerHealth += 10;
    score += 10;
    return playerHealth;
}
