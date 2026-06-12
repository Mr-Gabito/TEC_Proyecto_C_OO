#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <cstdlib>
#include <ctime>


class Character{
    protected: 
    std::string name;
    std::string title;
    int health;
    int strength;
    int selection = 0;

    public: 
    //Constructores
    Character(){
        name = "undefined";
        title = "undefined";
        health = 0;
        strength = 0;
    };
    Character(std::string n, std::string t, int h, int s){
        name = n;
        title = t;
        health = h;
        strength = s;
    };
    virtual ~Character() {}

    
    //getters
    std::string get_name(){
        return name;
    };
    std::string get_title(){
        return title;
    };
    int get_health(){
        return health;
    };
    int get_strength(){
        return strength;
    };
    int get_selection(){
        return selection;
    }

    //setters
    void set_name(std::string n){
        name = n;
    };
    void set_title(std::string t){
        title = t;
    };
    void set_health(int h){
        health = h;
    };
    void set_strength(int s){
        strength = s;
    };

    void dmgd(int damage){
        health -= damage;
        if(health < 0){
            health = 0;
        };
    };

    
    virtual int attack(Character& user, int option = 0) = 0;
};




class Assassin: public Character{
    private:
    int crits = 30;

    public: 
    Assassin(){
        name = "undefined";
        title = "undefined";
        health = 0;
        strength = 0;
    };
    Assassin(std::string n, std::string t, int h, int s){
        name = n;
        title = t;
        health = h;
        strength = s;
    };
    int attack(Character& player, int option) override{
        srand(time(0)); 
        int fdmg = strength;
        int fhealth = health;
        selection = option;
        //If option = 0, then it indicates the bot will be attacking
        if (option == 0){
            int enemyopt = (rand() % 100) + 1;
            if (enemyopt <= 65){
                option = 1;
            }
            else {
                option = 2;
            }
        }
        selection = option;
        if (option == 1){
            int missrate = (rand() % 100) + 1;
            if (missrate < 10) { 
                return 0;
            }
            else {
                fdmg = strength;
            }
        }
        else if(option == 2){
            int missrate = (rand() % 100) + 1;
            if (missrate < 50){
                return 0;
            }
            else{
                int critchance = (rand() % 100) + 1;
                if (critchance < crits){
                    fdmg = strength * 3;
                    player.dmgd(fdmg);
                    return fdmg;
                }
            }
        }
        player.dmgd(fdmg);
        return fdmg;
    }
};


//ALL OF THESE CHARACTERS NEED WORK I DONT KNOW ANYTHING HELp


class Knight: public Character{
    private:
    int holy = 50;

    public: 
    Knight(){
        name = "undefined";
        title = "undefined";
        health = 0;
        strength = 0;
    };
    Knight(std::string n, std::string t, int h, int s){
        name = n;
        title = t;
        health = h;
        strength = s;
    };

    int attack(Character& player, int option) override{
        srand(time(0));
        int fdmg = strength;
        int fhealth = health;
        selection = option;
        if(option == 0){
            int enemyopt = (rand() % 100) + 1;
            if (enemyopt <= 65){
                option = 1;
            }
            else{
                option = 2;
            }
        }
        selection = option;
        if (option == 1){
            int missrate = (rand() % 100) + 1;
            if (missrate < 20) { 
                return 0;
            }
            else{
                fdmg = strength;
            }
        }
        else if(option == 2){
            int missrate = (rand() % 100) + 1;
            if (missrate < 40){
                return 0;
            }
            else{            
                int holychance = (rand() % 100) + 1;
                if (holychance < holy){
                    fdmg = strength + 30;
                    player.dmgd(fdmg);
                    return fdmg;
                }
                else if (holychance > holy){
                    fhealth = health + 30;
                    player.dmgd(fdmg);
                    set_health(fhealth);
                    return fdmg;
                }
            }
        }
        player.dmgd(fdmg);
        return fdmg;
    }
};





class Mage: public Character{
    private:
    int mana = 150;

    public: 
    Mage(){
        name = "undefined";
        title = "undefined";
        health = 0;
        strength = 0;
    };
    Mage(std::string n, std::string t, int h, int s){
        name = n;
        title = t;
        health = h;
        strength = s;
    };

    int attack(Character& player, int option) override{
        int fdmg = strength;
        int fhealth = health;
        if(option == 0){
            int enemyopt = (rand() % 100) + 1;
            if(enemyopt <= 15){
                option = 1;
            }
            else if(enemyopt > 15 && enemyopt <= 45){
                option = 2;
            }
            else if(enemyopt > 45 && enemyopt <= 75){
                option = 3;
            }
            else if(enemyopt > 75 && enemyopt <= 100){
                option = 4;
            }
        }
        if (option == 1){
            int missrate = (rand() % 100) + 1;
            if (missrate < 5) { 
                return 0;
            }
        }
        else if(option == 2){
            int missrate = (rand() % 100) + 1;
            if(missrate < 20){
                return 0;
            }
            else{
                fdmg = strength + 20;
                mana = mana - 15;
                player.dmgd(fdmg);
                return fdmg;
            }
        }
        else if(option == 3){
            int missrate = (rand() % 100) + 1;
            if(missrate < 45){
                return 0;
            }
            else{
                fdmg = strength + 50;
                mana = mana - 30;
                player.dmgd(fdmg);
                return fdmg;
            }
        }
        else if(option == 4){
            int missrate = (rand() % 100) + 1;
            if(missrate < 60){
                return 0;
            }
            else{
                fdmg = strength + 60;
                mana = mana - 65;
                player.dmgd(fdmg);
                return fdmg;
            }
        }                             
    player.dmgd(fdmg);
    return fdmg;
    }
};
//MAKE AT LEAST TWO MORE CHARACTERS TO CHOOSE
#endif