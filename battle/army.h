#ifndef ARMY_H

#define
#include <map>
#include <vector>
#include "hero.h"
#include "soldier.h"


class Army {
    SoldierBase* p_soldier;
    std::vector<HeroBase> heros;
    public:
    Army(Soldier, Hero [], int);

    ~Army() {
        delete p_soldier;
    }
};




class ArmyBattle {
    bool    isAttacker;
    bool    retreated;
    int*    skillEffects;
    int*    events;
    ArmyBuff*       armyBuff;
    std::vector<HeroBattle> herosBattle;
    SoldierBattle*  soldier;

    ArmyBattle(Army armyInfo): Army(armyInfo), isAttacker(false),retreated(false) {
        //TODO
    }
    virtual int setArmyValue(char* key);
}


class ArmiesBattleInfo 
{
    std::vector<ArmyBattle> armies;
    public:
    static int initArmyBattleInfo(Army, int, bool, Buff, float);
};

#endif
