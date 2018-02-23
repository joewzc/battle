#include "army.h"


Army::Army(Soldier soldierData, Hero heroData[], int length) {
    p_soldier = new Soldier(soldierData);
    for(Hero* index=0; index<length; index++) {
        heros.push_back(heroData[index]);
    }
}


ArmyBattle::ArmyBattle(Army armyInfo): isAttacker(false),retreated(false) {
    //TODO
    soldier = new SoldierBattle(*(armyInfo->p_soldier));
    std::vector<HeroBase>::iterator it;
    for(it = armyInfo.heros.begin(); it != armyInfo.heros.end(); it++) 
    {
        HeroBattle heroBattle = *it;
        herosBattle.push_back(heroBattle);
    }

    skillEffects = NULL;
    events = NULL;
    armyBuff = new ArmyBuff();
}
