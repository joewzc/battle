#include "buff.h"

float Buff::getValue(char* key) {
    if(strcmp(key, "attackValueTune") == 0) {
        return attackValueTune;
    } 
    else if(strcmp(key, "defenseValueTune") == 0) {
        return defenseValueTune;
    }
    else if(strcmp(key, "rescueValueTune") == 0) {
        return rescueValueTune;
    } 
    else if(strcmp(key, "yinglieciLevel") == 0) {
        return yinglieciLevel;
    } 
    else {
        return 0.0;
    }
}

int Buff::setValue(char* key, float value) 
{
    if (strcmp(key, "attackValueTune") == 0)
    {
        attackValueTune = value;
    }
    else if (strcmp(key, "defenseValueTune") == 0)
    {
        defenseValueTune = value;
    }
    else if (strcmp(key, "rescueValueTune") == 0)
    {
        rescueValueTune = value;
    }
    else if (strcmp(key, "yinglieciLevel") == 0)
    {
        yinglieciLevel = value;
    }
    else
    {
        return -1;
    }
    return 0;
}

template<typename T>
int ArmyBuff::setValue(char* key, T value)
{
    if (strcmp(key, "freezeAttackCOunt") == 0) 
    {
        freezeAttackCount = value;
    }
    else if (strcmp(key, "shyFightCount") == 0)
    {
        shyFightCount = value;
    }
    else if (strcmp(key, "immuneChaosCount") == 0) 
    {
        immuneChaosCount = value;
    }
    else if (strcmp(key, "immuneRetreatHeroCount") == 0)
    {
        immuneRetreatHeroCount = value;
    }
    else if (strcmp(key, "immuneRetreatArmyCount") == 0)
    {
        immuneRetreatArmyCount = value;
    }
    else if (strcmp(key, "reflectSkillCount") == 0)
    {
        reflectSkillCount = value;
    }
    else if (strcmp(key, "attackValueTune") == 0)
    {
        attackValueTune = value;
    }
    else if (strcmp(key, "defenseValueTune") == 0)
    {
        defenseValueTune = value;
    }
    else if (strcmp(key, "restrictionValueTune") == 0)
    {
        restrictionValueTune = value;
    }
    else if (strcmp(key, "skillRateTune") == 0)
    {
        skillRateTune = value;
    }
    else if (strcmp(key, "curse") == 0)
    {
        curse = value;
    }

}
