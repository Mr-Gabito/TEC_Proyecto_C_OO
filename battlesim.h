#ifndef BATTLESIM_H
#define BATTLESIM_H
#include "character.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

class BattleSim{
    public:
    void fighting(Character* player, Character* enemy){
        int round = 1;

        while(player -> health > 0 && enemy -> get_health() > 0) {
        }
};

#endif