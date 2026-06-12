#ifndef BATTLESIM_H
#define BATTLESIM_H
#include "character.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

struct roundsim{
    int player_dmging;
    int enemy_dmging;
    bool dead_enemy;
    bool dead_player;
    int playeroption;
    int enemyoption;
};

class BattleSim{
    public:

    std::vector<Character*> enemies = {
        new Mage("Frieren", " the Slayer", 100, 5),
        new Assassin("Ezio", " Il Mentore", 150, 25),
        new Knight("Edward", " the Black Prince", 250, 15)
    };
    ~BattleSim(){
        for(Character* enemy:enemies){
            delete enemy;
        }
    };





    roundsim figthing(Character* player, Character* enemy, int option){
        roundsim result = {0, 0, false, false, 0, 0};
        
        result.player_dmging = player -> attack(*enemy, option);
        result.playeroption = player -> get_selection();

        if(enemy -> get_health() <= 0){
            result.dead_enemy = true;
            result.enemy_dmging = 0;
            result.enemyoption = 0;
            return result;
        }

        result.enemy_dmging = enemy -> attack(*player, 0);
        result.enemyoption = enemy -> get_selection();

        if(player -> get_health() <= 0){
            result.dead_player = true;
        }
        return result;
    }
};



#endif