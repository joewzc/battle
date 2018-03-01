#include "army.h"

void BattleHero::setValue (Hero hero, BattleArmy* p_army, bool isAttack) {
    id = hero.id;
    level = hero.level;
    sWisdom = hero.sWisdom;
    sLeader = hero.sLeader;
    sForce = hero.sForce;
    star = hero.star;
    retreated = false;
    force = 0;
    leadership = 0;
    wisdom = 0;
    fortune = 0;
    attackValue = 0;
    defenseValue = 0;
    hp = 0;
    isAttacker = isAttack;
    army = p_army;
    skillEffects = 0;
}

