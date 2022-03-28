//  Abel Anand🍥
#include <iostream>
#include <string>//dealing with strings
#include <stdio.h>
#include <thread>
#include <unistd.h>//dealing with time
#include <time.h>//time
#include <fstream>//dealing with files
using namespace std;//anything std




//function prototypes
void heathCheck(int);
void gameOver();
void skip();
void menu();
void planetMenu();
void Scario(int&, int&, int&);
void Goran(int&, int&, int&);
void Borjad(int&, int&, int&);
void Freece(int&, int&, int&);
void Poyrad(int&, int&, int&);
void Attack(int&, int&, int&, int, int);




//Maze rooms for borjad
void box1();
void box2();
void box3();
void box4();
void box5();
void box6();
void box7();
void box8();
void box9();
void box10();
void box11();
void box12();





//player struct
struct player {
    string name;
    int health;
    int weaponDamage;
    int score;
};







int main() {
    srand(time(0));
    bool mainQuit = true;
    char mainChoice;
    ifstream in;
    int scarioPlayed = 0;
    int goranPlayed = 0;
    int borjadPlayed = 0;
    int freecePlayed = 0;
    bool savedGame;
    string temp;
    player player1;
    
    cout << "Do you want to play THE ADVENTURES OF string name;\nY/N\n\n";
    cin >> mainChoice;
    mainChoice = toupper(mainChoice);
    switch (mainChoice) {
        case 'Y':
            in.seekg(0, ios::end);
            if (in.tellg() != 0) {
                cout << "You have a saved game, would you like to continue that?\nY/N\n";
                cin >> mainChoice;
                mainChoice = toupper(mainChoice);
                switch (mainChoice) {
                    case 'Y':
                        in.open("/Users/anandab/Documents/real-RPG/rpg/savefile.txt");
                        if (!in.is_open()) {
                            cout << "Savefile is not working\n\n";
                        }
                        savedGame = true;
                        getline(in, temp, ',');
                        scarioPlayed = stoi(temp);
                        getline(in, temp, ',');
                        goranPlayed = stoi(temp);
                        getline(in, temp, ',');
                        borjadPlayed = stoi(temp);
                        getline(in, temp, ',');
                        freecePlayed = stoi(temp);
                        getline(in, temp, ',');
                        player1.health = stoi(temp);
                        getline(in, temp, ',');
                        player1.weaponDamage = stoi(temp);
                        getline(in, temp, ',');
                        player1.score = stoi(temp);
                        getline(in, player1.name);
                        cout << "Welcome back" << player1.name << endl << endl;
                        in.close();
                        break;
                    case 'N':
                        savedGame = false;
                        cout << "Ok, you are going to restart\n";
                        break;
                    default:
                        cout << "You dont get the saved file, sry(not really)\n";
                }
            }
            else {
                savedGame = false;
            }
            
            mainQuit = false;
            break;
        case 'N':
            gameOver();
            break;
        default:
            cout << "You don't know how to read directions, so you are not worthy to play my game\n\n";
            break;
    }
    bool scario = false;
    bool goran = false;
    bool borjad = false;
    bool freece = false;
    bool poyrad = false;
    
    while (mainQuit == false){
        if (savedGame == false) {
    string name;
    cout << "Please Enter Player Name:\n\n";
    cin >> name;
    player1.name = name;
    if (player1.name == "Abel" || player1.name == "abel") {
        player1.health = 100000000;
        player1.weaponDamage = 100000000;
        player1.score = 100000000;
    }
    else if (player1.name == "slater" || player1.name == "Slater" || player1.name == "Brooks" || player1.name == "brooks") {
        cout << "BOZOBOZOBOZOBOZOBOZOBOZOBOZOBOZOBOZOBOZOBOZOBOZOBOZOBOZOBOZOBOZOBOZOBOZOBOZOBOZOBOZOBOZOBOZOBOZOBOZOBOZOBOZOBOZO";
        gameOver();
    }
    else {
        player1.health = 100;
        player1.weaponDamage = 50;
        }
    
    cout << "Hi " << name << " welcome to The Adventures of string name;\n\nYour task is to survive\n\n";
    skip();
        }
    string poyradCode = "SKYZM";//code
    bool poyradQuit;
    int poyradChoice;//if you want to choose a different planet or try the poyrad code again
    string playerCode;//code that the player enters
        
    cout << "Choose the planet you want to start at.\n\nYou can only change planets when you finish the mission on the planet\n\nHint: Choose Poyrad last\n\n";
        sleep(3);
    cout << "How to play: Your enemy will do a random damage on you(changes between different planets), you will either dodge, or shoot. Each enemy will have a set amount of health\n\n";
    sleep(4);
        bool quit = false;
        int planetChoice;
        while (!quit) {
            if (scarioPlayed != 0 || goranPlayed!=0 || borjadPlayed != 0 || freecePlayed != 0) {
                char choice;
                cout << "Would you like to save and quit?\nY/N\n";
                cin >> choice;
                choice = toupper(choice);
                if (choice == 'Y') {
                    ofstream out;
                    out.open("/Users/Abel/Documents/Cpp/rpg/rpg/savefile.txt");//***make sure to change when switching computers***
                    out << scarioPlayed << "," << goranPlayed << "," << borjadPlayed << "," << freecePlayed << "," << player1.health << "," << player1.weaponDamage << "," << player1.score << "," << player1.name;
                    out.close();
                    gameOver();
                }
                else {
                    cout << "Not quitting...\n";
                    quit = true;
                    continue;
                }
            }
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
                cout << "Please choose a valid planet\n\n";
                break;
        }
        if (scario == true) {
            if (scarioPlayed == 0) {
                cout << "Health = " << player1.health << "   Weapon Damage = " << player1.weaponDamage << endl;
                Scario(player1.health, player1.weaponDamage, player1.score);
                cout << "First letter: S\n\n";
                scario = false;
                scarioPlayed++;
                skip();
            }
            else {
                cout << "You already went to this planet, choose another one\n\n";
            }
        }
        else if (goran == true) {
            cout << "Health = " << player1.health << "   Weapon Damage = " << player1.weaponDamage << endl;
            if (goranPlayed == 0) {
                Goran(player1.health, player1.weaponDamage, player1.score);
                cout << "Second letter: K\n\n";
                goran = false;
                goranPlayed++;
                skip();
            }
            else {
                cout << "You already went to this planet, choose another one\n\n";
            }
        }
        else if (borjad == true) {
            cout << "Health = " << player1.health << "   Weapon Damage = " << player1.weaponDamage << endl;
            if (borjadPlayed == 0) {
                Borjad(player1.health, player1.weaponDamage, player1.score);
                cout << "Third letter: Y\n\n";
                borjad = false;
                borjadPlayed++;
                skip();
            }
            else {
                cout << "You already went to this planet, choose another one\n\n";
            }
        }
        else if (freece == true) {
            cout << "Health = " << player1.health << "   Weapon Damage = " << player1.weaponDamage << endl;
            if (freecePlayed == 0) {
                Freece(player1.health, player1.weaponDamage, player1.score);
                cout << "Fourth letter: Z\n\n";
                freece = false;
                freecePlayed++;
                skip();
            }
            else {
                cout << "You already went to this planet, choose another one\n\n";
            }
        }
        else if (poyrad == true) {
            poyradQuit = false;
            cout << "Fifth letter: M\n\n";
            while (!poyradQuit) {
            cout << "Enter the Full Code(All caps)\n\n";
            cin >> playerCode;
                if (playerCode == poyradCode) {
            cout << "Health = " << player1.health << "   Weapon Damage = " << player1.weaponDamage << endl;
                Poyrad(player1.health, player1.weaponDamage, player1.score);
                poyrad = false;
                poyradQuit = true;
                    mainQuit = true;
                skip();
                }
                else {
                    cout << "1. Try again     2. Choose different planet\n\n";
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
    cout << "Game over\n\nScore:";
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
    cout << "Quit Game(1)   Resume(2)\n\n";
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
    cout << "1. Scario(Homeworld)\n\n2. Goran(Dwelling of the androids)\n\n3. Borjad(Land of Gold)\n\n4. Freece(Desert of ice\n\n5. Poyrad(Land of the Ogres)\n\n";
}


























//Planets
void Scario(int &playerHealth, int &playerWeaponDamage, int &playerScore) {
    cout << "You go to your home planet, Scario. When you can't find a landing pad in the city, you land in a forest. As you hike to the city, you meet a ghoul.\n\n";
    sleep(3);
    cout << "The ghoul asks you a question, \"Will you find the ghoul's artifact?\"" << "    What's that" << "    You don't need to know that, just find it in Jerk's Junkyard" <<  "    Fine, i'll get it for you\n\n";
    sleep(4);
    cout << "Jerk's Junkyard(Where all jerks hang out)\n\n";
    sleep(2);
    cout << "As you enter, you see about 10 goons standing around a pyramid shaped object, that must be it.\n\nYou approach them, but they raise their guns at you\n\nYou flip a table and take cover\n\n";
    for (int i = 0; i < 10; i++) {
        cout << "Goon " << i + 1 << endl;
        Attack(playerHealth, playerWeaponDamage, playerScore, 100, 20);
    }
    cout << "You finish all the goons and take the pyramid, it starts glowing\n\nYou leave the junkyard and go to the place where you met the ghoul\n\nIt's still there, hovering over the ground\n\n\"So, you got the artifact\"     \"Yeah, you could have at least warned me people were protecting it\"\n\n";
    sleep(5);
    cout << "\"Oh, yes, I knew I forgot to tell a detail\"     \"Yeah, well so what do I get for helping you\"     \"The artifact of course\"     \"So it wasn't for you!\"     \"Oh no, I left out yet another detail, Oh well, good bye\"\n\n";
    sleep(5);
    cout << "The ghoul vanishes into thin air. You examine the artifact it's still glowing, suddenly you feel better, like a gust of wind flowed through you\n\n";
    playerHealth += 20;
    cout << "+20 Health\n\n";
}




void Goran(int &playerHealth, int &playerWeaponDamage, int &playerScore) {
    cout << "You travel to the planet of the androids. You land in the capital Robotron. A robot comes to greet you.\n\n\"Welcome to Robotron, what brings you here\"     \"I'm just here for some fun\"     \"Then why do you carry a gun\"     \"Like I said, for fun. Anyways, do you know where I can make some money\"\n\n";
    sleep(5);
    cout << " \"What do you do\"     \"Anything that involves a gun\"     \"Ok, will you do a job for me\"     \"What job\"n     \"You have to rescue my friend, he was captured by a gang.\"     \"How much is the pay\"     \"We'll discuss that after you rescue him\"    \"Fine, give me an advance amount\". The robot gives you 1000 credits\n\n";
    sleep(5);
    cout << "\"Where is he\"     \"He's being held hostage in the DEN\"     \"Where's that\"     \"I'll show you\". The robot takes you to a giant building in the center of town.     ";
    cout << "\"He's being held in the 50th story, you'll have to sneak to get in there\"     \"Or I could just kill my way there\"\n\nYou go to the evevator and take it to the 50th floor, there you are greeted by some dangerous looking robots they take out their guns, and you take cover behind a corner\n\n";
    for (int i = 0; i < 15; i++) {
        cout << "Robot " << i + 1 << endl;
        Attack(playerHealth, playerWeaponDamage, playerScore, 75, 25);
    }
    cout << "You kill all the robots at make your way to a room, there, you see a robot being electrocuted. You shut off the mechanism and take him off his binds. You carry him to the elevator.\n\n";
    sleep(5);
    cout << "\"Who are you\"     \"Your friend paid me to rescue you\"     \"Which friend\"     \"The blue one\"     \"I don't have a blue friend\"     \"The one who wears a red bandana\"     Suddenly the robot's face looks scared.\"That's the one who locked me in here\"\n\n";
    sleep(5);
    cout << "\"After all that bonding I thought we were friends. Now you've insulted me\". The blue robot takes out a golden gun. You recognize it as the 24 carat upgrade, a high damaging upgrade\n\nHe starts shooting at you and you take cover\n\n";
    Attack(playerHealth, playerWeaponDamage, playerScore, 150, 50);
    cout << "You kill the blue robot. He drops his gun, it does 25 more damage than your current gun\n\n";
    sleep(2);
    cout << "\"Thank you for saving me\"     \"Yeah, no problem\"     \"How much did he owe you\"     \"It's fine, this gun's worth way more\"     \"I can't thank you enough\"     \"I'll be leaving now, i've had enough of Goran for a day\"\n\n";
    sleep(4);
    cout << "You leave goran with your new gun\n\n";
    playerWeaponDamage += 10;
    cout << "+10 weapon damage     New weapon upgrade- 24 Carat\n\n";
}

void Borjad(int &playerHealth, int &playerWeaponDamage, int &playerScore) {
    cout << "You go to the rich desert planet of Borjad. As you fly over the capital city of Nala, you see merchants lining the streets with their goods. You decide it would be better to land somewhere in the desert\n\n";
    sleep(4);
    cout << "As you go deeper into the desert, you see a single merchant with a camel. You land your ship near where he is. He approaches you. \"Hey traveler, my precious Jewel is in the heart of the underground maze, will you get it.\"     \"Sure, where's the maze\". Suddenly the sand below you sinks.";
    sleep(5);
    cout << "You are in the maze\n\n";
    box1();
    sleep(2);
    cout << "\"Here's your jewel, I could swear the maze had me going in circles, anyway, how'd you get your jewlel stuck in the maze\"     \"Oh, I put it there\"     \"Then why'd you ask me to get it for you\"     \"I never asked you to get it for ME, I just asked you to get it\"\n\n";
    sleep(4);
    cout << "\"Wow, all that time in the maze for nothing\"     \"No, you got the jewel, it makes you stronger\". You know the merchant isn't lying, you do feel more refreshed. You thank him and leave Borjad\n\n+10 health\n\n";
    playerHealth += 10;
}

void Freece(int &playerHealth, int &playerWeaponDamage, int &playerScore) {
    cout << "You go to the frozen sphere that is the planet Freece. Not much goes on in Freece except for mountaineering, about 70% of Freece is still undocumented\n\n";
    sleep(3);
    cout << "";
}

void Poyrad(int &playerHealth, int &playerWeaponDamage, int &playerScore) {
    
}















//player and enemy functions
void Attack(int &playerHealth, int &playerWeaponDamage, int &playerScore, int enemyHealth, int enemyRandDamage) {
    bool enemyDeath = false;
    int playerChoice;
    while (!enemyDeath) {
        if (enemyHealth <= 0) {
            cout << "You killed the enemy\n\n";
            enemyDeath = true;
            break;
        }
        healthCheck(playerHealth);
        cout << "1. Hit(Assualt rifle)   2. Dodge\n\n";
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
                cout << "The enemy missed\n\n";
            }
        }
        else if (playerChoice == 2) {
            cout << "No Damage done, No Damage taken\n\n";
        }
        else {
            cout << "-10 health for your ignorance of instructions\n\n";
            playerHealth -= 10;
        }
    }
    playerHealth += 10;




}




















//Functions for maze rooms
void box1(){
    int choice;
    bool quit = false;
    cout << "Would you like to go right(1) or down(2)\n\n";
    while (!quit) {
        cin >> choice;
        switch (choice) {
            case 1:
                box2();
                break;
            case 2:
                box4();
                break;
            default:
                cout << "plz enter correc ting\n\n";
                break;
        }
    }
}

void box2() {
    int choice;
    bool quit = false;
    cout << "Would you like to go right(1), left(2), or down(3)\n\n";
    while (!quit) {
        cin >> choice;
        switch (choice) {
            case 1:
                box3();
                break;
            case 2:
                box1();
                break;
            case 3:
                box5();
                break;
            default:
                cout << "plz enter correc ting\n\n";
                break;
        }
    }
}

void box3() {
    cout << "Dead End, You have to go left\n\n";
    box2();
}

void box4() {
    int choice;
    bool quit = false;
    cout << "Would you like to go up(1), down(2), or right(3)\n\n";
    while (!quit) {
        cin >> choice;
        switch (choice) {
            case 1:
                box1();
                break;
            case 2:
                box7();
                break;
            case 3:
                box5();
                break;
            default:
                cout << "plz enter correc ting\n\n";
                break;
        }
    }
}

void box5() {
    int choice;
    bool quit = false;
    cout << "Would you like to go right(1), left(2), up(3), or down(4)\n\n";
    while (!quit) {
        cin >> choice;
        switch (choice) {
            case 1:
                box6();
                break;
            case 2:
                box4();
                break;
            case 3:
                box2();
                break;
            case 4:
                box9();
            default:
                cout << "plz enter correc ting\n\n";
                break;
        }
    }
}

void box6() {
    int choice;
    bool quit = false;
    cout << "Would you like to go left(1) or down(2)\n\n";
    while (!quit) {
        cin >> choice;
        switch (choice) {
            case 1:
                box5();
                break;
            case 2:
                box9();
                break;
            default:
                cout << "plz enter correc ting\n\n";
                break;
        }
    }
}

void box7() {
    int choice;
    bool quit = false;
    cout << "Would you like to go right(1), down(2) or up(3)\n\n";
    while (!quit) {
        cin >> choice;
        switch (choice) {
            case 1:
                box8();
                break;
            case 2:
                box10();
                break;
            case 3:
                box4();
                break;
            default:
                cout << "plz enter correc ting\n\n";
                break;
        }
    }
}

void box8() {
    int choice;
    bool quit = false;
    cout << "Would you like to go right(1) or left(2)\n\n";
    while (!quit) {
        cin >> choice;
        switch (choice) {
            case 1:
                box9();
                break;
            case 2:
                box7();
                break;
            default:
                cout << "plz enter correc ting\n\n";
                break;
        }
    }
}

void box9() {
    int choice;
    bool quit = false;
    cout << "Would you like to go up(1), down(2) or left(3)\n\n";
    while (!quit) {
        cin >> choice;
        switch (choice) {
            case 1:
                box6();
                break;
            case 2:
                box12();
                break;
            case 3:
                box8();
                break;
            default:
                cout << "plz enter correc ting\n\n";
                break;
        }
    }
}

void box10() {
    int choice;
    bool quit = false;
    cout << "Would you like to go up(1), or right(2)\n\n";
    while (!quit) {
        cin >> choice;
        switch (choice) {
            case 1:
                box7();
                break;
            case 2:
                box11();
                break;
            default:
                cout << "plz enter correc ting\n\n";
                break;
        }
    }
}

void box11() {
    cout << "You find the jewel and go back to the merchant\n\n  ";
}

void box12() {
    cout << "Dead End, you have to go up\n\n";
    box9();
}
