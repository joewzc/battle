
#ifndef _ARMY
#define _ARMY
#include "buff.h"

struct Soldier {
	int id;			//兵种ID
	int number;		//士兵数量
	int trainLv;	//训练等级
	int pos;		//队伍所处位置
	int* skillIDs;	//技能ID数组
	int skillLength; //技能数组长度
	int elv;			//兵种转生等级
    Soldier(Soldier soldier){
        id = soldier.id;
        number = soldier.number;
        trainLv = soldier.trainLv;
        pos = soldier.pos;
        skillLength = soldier.skillLength;
        elv = soldier.elv;
        skillIDs = soldier.skillIDs;
    }
};

struct Hero {
	int id;			//武将ID
	int level;		//武将等级
	int sWisdom;	//武将智力
	int sLeader;	//武将统帅
	int sForce;		//武力值
	int star		//武将转星
};

struct BattleSoldier : public Soldier {
    int attackValue;
    int defenseValue;
    int hp;
    int speed;
    int originalNumber;
    int force;
    int wisdom;
    BattleSoldier(Soldier soldier): soldier(soldier)
};

struct BattleHero : public Hero {
    bool retreated;
    int force;
    int leadership;
    int wisdom;
    int fortune;
    int attackValue;
    int defenseValue;
    int hp;
    bool isAttacker;
    BattleArmy* army;
    int skillEffects; //TODO　数组


}

class Army {
    protected:
	Soldier soldier;
	Hero* heros;	
	int heroSize
	
    public:
	Army(Soldier; Hero*; int);
	int getSoldierInfo();
	int getHeroInfo();
};

class BattleArmy {
    bool isAttacker;
    bool retreated;
    int skillEffects;
    BattleSoldier soldier;
    BattleHero* heros;
    int heroSize;
    BattleArmy(Army army, bool isAttacker): soldier(army.soldier){

    }
}


