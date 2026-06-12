#include "character.h"
#include "battlesim.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void menu(){
    std::cout << "Welcome to the ultimate challenge! Defeat all your enemies and as a reward you'll receive a cake of your choosing!\n" << std::endl;
    std::cout << "Select your character: " << std::endl;
    std::cout << "1. Mage \nStrength: 5 --- Health: 100 --- Special ability: Magic spells (Mana: 150)\n" << std::endl;
    std::cout << "2. Knight \nStrength: 15 --- Health: 250 --- Special ability: Holy power\n" << std::endl;
    std::cout << "3. Assassin \nStrength: 20 --- Health: 150 --- Special ability: Critical strike\n" << std::endl;
    std::cout << "4. Quit\n" << std::endl;
    std::cout << "Please select the number of the character chosen: " << std::endl;
};

int main(){
    srand(time(0));
    BattleSim bats;
    roundsim res;
    int option = 0;
    int optionn = 0;
    bool death_p = false;
    std::string playername = "undefined";
    std::string playertitle = "undefined";

    Character* player = nullptr;

    menu();
    std::cin >> optionn;

    if (optionn == 4){
        std::cout << "Bye bye!" << std::endl;
        return 0;
    }

    std::cout << "What is your name? " << std::endl;
    std::cin >> playername;
    std::cout << "What title do you choose? " << std::endl;
    std::cin >> playertitle;

    switch(optionn){

    case 1:{
        Character* player = new Mage(playername, playertitle, 100, 5);
        for(Character* enemy : bats.enemies){
            std::cout << enemy -> get_name() << enemy -> get_title() << std::endl;
            std::cout << "-----------VS-----------" << std::endl;
            std::cout << playername << " " << playertitle << std::endl;
            int round = 1;
            player -> set_health(100);
            while(player -> get_health() > 0 && enemy -> get_health() > 0){
                std::cout << "Round " << round << std::endl;
                std::cout << "Battle menu:\n" << std::endl;
                std::cout << "1. Punch? (+5 damage, 0 mana, 5% miss rate)" << std::endl;
                std::cout << "2. Lightning (+20 damage, 15 mana, 20% miss rate)" << std::endl;
                std::cout << "3. Fireball (+50 damage, 30 mana, 45% miss rate)" << std::endl;
                std::cout << "4. Light spear (+60 damage, 65 mana, 60% miss rate)" << std::endl;
                int option = 0;
                std::cin >> option;

                roundsim res = bats.figthing(player, enemy, option);

                if (res.player_dmging > 0){
                    if (option == 1){
                        std::cout << "You think spells are useless anyway so you punch your enemy!" << std::endl;
                        std::cout << "Damage dealt: " << res.player_dmging << std::endl;
                    }
                    else if (option == 2){
                        std::cout << "You quickly channel your mana and release Lightning!" << std::endl;
                        std::cout << "Damage dealt: " << res.player_dmging << std::endl; 
                    }
                    else if (option == 3){
                        std::cout << "You focus and use Fireball!" << std::endl;
                        std::cout << "Damage dealt: " << res.player_dmging << std::endl;
                    }
                    else if (option == 4){
                        std::cout << "You use all of your magical knowledge and unleash Light Spear!" << std::endl;
                        std::cout << "Damage dealt: " << res.player_dmging << std::endl;
                    }
                }
                else{
                    int miss = (rand() % 3) + 1;
                    if (miss == 1){
                        std::cout << "You close your eyes and focus on the spell and... you fell asleep... MISSED!" << std::endl;
                    }
                    else if (miss == 2){
                        std::cout << "You channel your mana and point at your enemy but you sneezed! MISSED!" << std::endl; 
                    }
                    else if (miss == 3){
                        std::cout << "...I won't even say anything that was embarrassing. MISSED!" << std::endl;
                    }
                }

                if (res.dead_enemy){
                    std::cout << enemy -> get_name() << enemy -> get_title() << " was defeated!" << std::endl;
                    break;
                }
                
                //ENEMY PRINTS
                if (res.enemy_dmging == 0){
                    int miss = (rand() % 3) + 1;
                    if (enemy -> get_name() == "Frieren"){
                        if (miss == 1){
                            std::cout << "The enemy looks at you with malicious intent, then is distracted by a butterfly. MISSED!" << std::endl;
                        }
                        else if (miss == 2){
                            std::cout << "The enemy channels their mana but bites their tongue! MISSED!" << std::endl; 
                        }
                        else if (miss == 3){
                            std::cout << "The enemy launches a spell at you, but a bird intercepts it and dies! MISSED!" << std::endl;
                        }
                    }
                    else if (enemy -> get_name() == "Edward"){
                        if (miss == 1){
                            std::cout << "The enemy senses you want to win lets gives you their turn. MISSED!" << std::endl;
                        }
                        else if (miss == 2){
                            std::cout << "The enemy swings their sword and cuts in half... a tree?! MISSED!" << std::endl; 
                        }
                        else if (miss == 3){
                            std::cout << "The enemy points a finger at you while yelling for their goddess to hit you! MISSED!" << std::endl;
                        }
                    }
                    else if (enemy -> get_name() == "Ezio"){
                        if (miss == 1){
                            std::cout << "The enemy launches daggers at you, but you deflect them all. MISSED!" << std::endl;
                        }
                        else if (miss == 2){
                            std::cout << "The enemy runs towards you and slices... bread... looks like they were hungry. MISSED!" << std::endl; 
                        }
                        else if (miss == 3){
                            std::cout << "The enemy throws a smoke bomb! But its a dud... MISSED!" << std::endl;
                        }
                    }
                }

                if (res.dead_player){
                    std::cout << playername << " " << playertitle << " was defeated!" << std::endl;
                    death_p = true;
                    break;
                }


                std::cout << "Health: " << player -> get_health() << std::endl;
                std::cout << "Enemy health: " << enemy -> get_health() << std::endl;
                round++;
            }
            if (death_p){
                break;
            }
            
        }
        if (!death_p){
            std::cout << "You win! Congratulations!" << std::endl;
            std::cout << "The cake was a lie" << std::endl;
        }
        else{
            std::cout << "You lose!";
        }
        delete player;
        break;
    }

    case 2:{
        Character* player = new Knight(playername, playertitle, 250, 15);
        for(Character* enemy : bats.enemies){
            std::cout << enemy -> get_name() << enemy -> get_title() << std::endl;
            std::cout << "-----------VS-----------" << std::endl;
            std::cout << playername << " " << playertitle << std::endl;
            int round = 1;
            player -> set_health(250);
            while(player -> get_health() > 0 && enemy -> get_health() > 0){
                std::cout << "Round " << round << std::endl;
                std::cout << "Battle menu:\n" << std::endl;
                std::cout << "1. Sword swing (+15 damage, 20% miss rate)" << std::endl;
                std::cout << "2. Holy strike (+15 damage, 40% miss rate, chance of healing or dealing +30 damage)\n" << std::endl;
                int option = 0;
                std::cin >> option;

                roundsim res = bats.figthing(player, enemy, option);

                if (res.player_dmging > 0){
                    if (option == 1){
                        std::cout << "You lunge at your enemy and strike!" << std::endl;
                        std::cout << "Damage dealt: " << res.player_dmging << std::endl;
                    }
                    else if (option == 2){
                        std::cout << "You pray to your goddess and unleash Holy strike!" << std::endl;
                        std::cout << "Damage dealt: " << res.player_dmging << std::endl; 
                    }
                }
                else{
                    int miss = (rand() % 3) + 1;
                    if (miss == 1){
                        std::cout << "You swing your sword at your enemy but it bounces off?! MISSED!" << std::endl;
                    }
                    else if (miss == 2){
                        std::cout << "Your enemy looked sad so you intentionally hit the ground instead! MISSED!" << std::endl; 
                    }
                    else if (miss == 3){
                        std::cout << "You pray to your goddess but forget you are fighting. MISSED!" << std::endl;
                    }
                }

                if (res.dead_enemy){
                    std::cout << enemy -> get_name() << enemy -> get_title() << " was defeated!" << std::endl;
                    break;
                }
                
                //ENEMY PRINTS
                if (res.enemy_dmging == 0){
                    int miss = (rand() % 3) + 1;
                    if (enemy -> get_name() == "Frieren"){
                        if (miss == 1){
                            std::cout << "The enemy looks at you with malicious intent, then is distracted by a butterfly. MISSED!" << std::endl;
                        }
                        else if (miss == 2){
                            std::cout << "The enemy channels their mana but bites their tongue! MISSED!" << std::endl; 
                        }
                        else if (miss == 3){
                            std::cout << "The enemy launches a spell at you, but a bird intercepts it and dies! MISSED!" << std::endl;
                        }
                    }
                    else if (enemy -> get_name() == "Edward"){
                        if (miss == 1){
                            std::cout << "The enemy senses you want to win lets gives you their turn. MISSED!" << std::endl;
                        }
                        else if (miss == 2){
                            std::cout << "The enemy swings their sword and cuts in half... a tree?! MISSED!" << std::endl; 
                        }
                        else if (miss == 3){
                            std::cout << "The enemy points a finger at you while yelling for their goddess to hit you! MISSED!" << std::endl;
                        }
                    }
                    else if (enemy -> get_name() == "Ezio"){
                        if (miss == 1){
                            std::cout << "The enemy launches daggers at you, but you deflect them all. MISSED!" << std::endl;
                        }
                        else if (miss == 2){
                            std::cout << "The enemy runs towards you and slices... bread... looks like they were hungry. MISSED!" << std::endl; 
                        }
                        else if (miss == 3){
                            std::cout << "The enemy throws a smoke bomb! But its a dud... MISSED!" << std::endl;
                        }
                    }
                }

                if (res.dead_player){
                    std::cout << playername << " " << playertitle << " was defeated!" << std::endl;
                    death_p = true;
                    break;
                }


                std::cout << "Health: " << player -> get_health() << std::endl;
                std::cout << "Enemy health: " << enemy -> get_health() << std::endl;
                round++;
            }
            if (death_p){
                break;
            }
        }
        if (!death_p){
            std::cout << "You win! Congratulations!" << std::endl;
            std::cout << "The cake was a lie" << std::endl;
        }
        else{
            std::cout << "You lose!";
        }
        delete player;
        break;
    }
    case 3:{
        Character* player = new Assassin(playername, playertitle, 150, 20);
        for(Character* enemy : bats.enemies){
            std::cout << enemy -> get_name() << enemy -> get_title() << std::endl;
            std::cout << "-----------VS-----------" << std::endl;
            std::cout << playername << " " << playertitle << std::endl;
            int round = 1;
            player -> set_health(150);
            while(player -> get_health() > 0 && enemy -> get_health() > 0){
                std::cout << "Round " << round << std::endl;
                std::cout << "Battle menu:\n" << std::endl;
                std::cout << "1. Slash (+20 damage, 10% miss rate)" << std::endl;
                std::cout << "2. Backslash (x3 damage, 50% miss rate)\n" << std::endl;
                int option = 0;
                std::cin >> option;

                roundsim res = bats.figthing(player, enemy, option);

                if (res.player_dmging > 0){
                    if (option == 1){
                        std::cout << "You swiftly run towards your enemy and slash their side!" << std::endl;
                        std::cout << "Damage dealt: " << res.player_dmging << std::endl;
                    }
                    if (option == 2){
                        std::cout << "You enter the shadows and slash the enemies back!" << std::endl;
                        std::cout << "Damage dealt: " << res.player_dmging << std::endl; 
                    }
                }
                else{
                    int miss = (rand() % 3) + 1;
                    if (miss == 1){
                        std::cout << "You enter the shadows and get lost! MISSED!" << std::endl;
                    }
                    else if (miss == 2){
                        std::cout << "You run towards your enemy clumsily and they just step aside! MISSED!" << std::endl; 
                    }
                    else if (miss == 3){
                        std::cout << "You try to strike a deal with the enemy to let you win, but they refuse. MISSED!" << std::endl;
                    }
                }

                if (res.dead_enemy){
                    std::cout << enemy -> get_name() << enemy -> get_title() << " was defeated!" << std::endl;
                    break;
                }
                
                //ENEMY PRINTS
                if (res.enemy_dmging == 0){
                    int miss = (rand() % 3) + 1;
                    if (enemy -> get_name() == "Frieren"){
                        if (miss == 1){
                            std::cout << "The enemy looks at you with malicious intent, then is distracted by a butterfly. MISSED!" << std::endl;
                        }
                        else if (miss == 2){
                            std::cout << "The enemy channels their mana but bites their tongue! MISSED!" << std::endl; 
                        }
                        else if (miss == 3){
                            std::cout << "The enemy launches a spell at you, but a bird intercepts it and dies! MISSED!" << std::endl;
                        }
                    }
                    else if (enemy -> get_name() == "Edward"){
                        if (miss == 1){
                            std::cout << "The enemy senses you want to win lets gives you their turn. MISSED!" << std::endl;
                        }
                        else if (miss == 2){
                            std::cout << "The enemy swings their sword and cuts in half... a tree?! MISSED!" << std::endl; 
                        }
                        else if (miss == 3){
                            std::cout << "The enemy points a finger at you while yelling for their goddess to hit you! MISSED!" << std::endl;
                        }
                    }
                    else if (enemy -> get_name() == "Ezio"){
                        if (miss == 1){
                            std::cout << "The enemy launches daggers at you, but you deflect them all. MISSED!" << std::endl;
                        }
                        else if (miss == 2){
                            std::cout << "The enemy runs towards you and slices... bread... looks like they were hungry. MISSED!" << std::endl; 
                        }
                        else if (miss == 3){
                            std::cout << "The enemy throws a smoke bomb! But its a dud... MISSED!" << std::endl;
                        }
                    }
                }

                if (res.dead_player){
                    std::cout << playername << " " << playertitle << " was defeated!" << std::endl;
                    death_p = true;
                    break;
                }


                std::cout << "Health: " << player -> get_health() << std::endl;
                std::cout << "Enemy health: " << enemy -> get_health() << std::endl;
                round++;
            }
            if (death_p){
                break;
            }
        }
        if (!death_p){
            std::cout << "You win! Congratulations!" << std::endl;
            std::cout << "The cake was a lie" << std::endl;
        }
        else{
            std::cout << "You lose!";
        }
        delete player;
        break;
    }
    }
return 0;
}