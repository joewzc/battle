#include "army.h"
#include "buff.h"

#define ROUNDNUMBER 10

int computeBattleResult(Army attackArmyArray[],Army defenseArmyArray[], int battleType, Buff battleBuff, int attackLength, int defenseLength) {
    if(attackLength == 0 && defenseLength == 0) 
    {
        return 0;
    }

    if(attackLength == 0)
    {
        return -1;
    }

    if(defenseLength == 0)
    {
        return 1;
    }

    this.attackArmies = attackArmyArray;
    this.defenseArmies = defenseArmyArray;

    Buff* attackBuildingBuff = new Buff(battleBuff.attackBuildingBuff);
    Buff* defenseBuildingBUff = new Buff(battleBuff.defenseBuildingBuff);
    ArmiesBattleInfo* attackArmies = new ArmiesBattleInfo();
    ArmiesBattleInfo* defenseArmies = new ArmiesBattleInfo();
    ArmiesBattleInfo::initArmyBattleInfo(attackArmyArray, attackLength, false, attackBuildingBuff, )
    int roundNumber = 10;
    
}


static int ArmiesBattleInfo::initArmyBattleInfo(Army armyArray[], int armyLength,  bool isAttacker, Buff buildingBuff, float plusBuff, ArmiesBattleInfo* armiesInfo) {
    for(int index=0; index < armyLength; index++) 
    {
        ArmyBattle armyInfo = armyArray[index];
        armiesInfo.armies.push_back(armyInfo);
    }
}
