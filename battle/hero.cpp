#include "hero.h"


HeroBase::HeroBase(HeroBase heroData) {
    id = heroData.id;
    level = heroData.level;
    sWisdom = heroData.sWisdom;
    sLeader = heroData.sLeader;
    sForce = heroData.sForce;
    sFortune = heroData.sFortune;
    star = heroData.star;
    elv = heroData.elv;
    pos = heroData.pos;
}

virtual int HeroBase::getValue(char* key) 
{
    if(strcmp("id", key) == 0) {
        return id;
    }
    else if(strcmp("level", key) == 0) {
        return level;
    }
    else if(strcmp("sWisdom", key) == 0) {
        return sWisdom;
    }
    else if(strcmp("sLeader", key) == 0) {
        return sLeader;
    } 
    else if(strcmp("sForce", key) == 0) {
        return sForce;
    } 
    else if(strcmp("sFortune", key) == 0) {
        return sFortune;
    }
    else if(strcmp("star", key) == 0) {
        return star;
    }
    else if (strcmp("elv", key) == 0) {
        return elv;
    }
    else if (strcmp("pos", key) == 0) {
        return pos;
    }
    else {
        return -1;
    }
    
}

HeroBase& HeroBase::operator = (HeroBase *heroData) {

    id = heroData->id;
    level = heroData->level;
    sWisdom = heroData->sWisdom;
    sLeader = heroData->sLeader;
    sForce = heroData->sForce;
    sFortune = heroData->sFortune;
    star = heroData->star;
    elv = heroData->elv;
    pos = heroData->pos;
    return *this;
}

HeroBattle::HeroBattle(HeroBase hero): HeroBase(hero){
    skillEffects = NULL;
    force = 0;
    leadership = 0;
    wisdom = 0;
    attackValue = 0;
    hp = 0;
    defenseValue = 0;
    isAttacker = false;
    ownArmy = 0;
    killerArmy = 0;
    heroBuff = new HeroBuff();
}

Herobattle::~HeroBattle() {
    delete heroBuff;
}

template<typename T>
virtual T heroBattle::getValue(char* key) 
{
    if(strcmp("id", key) == 0) {
        return id;
    }
    else if(strcmp("level", key) == 0) {
        return level;
    }
    else if(strcmp("sWisdom", key) == 0) {
        return sWisdom;
    }
    else if(strcmp("sLeader", key) == 0) {
        return sLeader;
    } 
    else if(strcmp("sForce", key) == 0) {
        return sForce;
    } 
    else if(strcmp("sFortune", key) == 0) {
        return sFortune;
    }
    else if(strcmp("star", key) == 0) {
        return star;
    }
    else if (strcmp("elv", key) == 0) {
        return elv;
    }
    else if (strcmp("pos", key) == 0) {
        return pos;
    }
    else if(strcmp("force", key) == 0) {
        return force;
    }
    else if(strcmp("leadership", key) == 0) {
        return leadership;
    }
    else if(strcmp("wisdom", key) == 0) {
        return wisdom;
    }
    else if(strcmp("attackValue", key) == 0) {
        return attackValue;
    } 
    else if(strcmp("hp", key) == 0) {
        return hp;
    } 
    else if(strcmp("defenseValue", key) == 0) {
        return defenseValue;
    }
    else if(strcmp("ownArmy", key) == 0) {
        return ownArmy;
    }
    else if (strcmp("killerArmy", key) == 0) {
        return killArmy;
    }
    else if(strcmp("skillEffects", key) == 0)
    {
        return skillEffects;
    } 
    else {
        return -1;
    }
}

template<typename T>
virtual bool setValue(char*  key, T value)
{
    bool flag = true;
    if(strcmp("id", key) == 0) {
        id = id;
    }
    else if(strcmp("level", key) == 0) {
        level = value;
    }
    else if(strcmp("sWisdom", key) == 0) {
        sWisdom = value;
    }
    else if(strcmp("sLeader", key) == 0) {
        sLeader = value;
    } 
    else if(strcmp("sForce", key) == 0) {
        sForce = value;
    } 
    else if(strcmp("sFortune", key) == 0) {
        sFortune = value;
    }
    else if(strcmp("star", key) == 0) {
        star = value;
    }
    else if (strcmp("elv", key) == 0) {
        elv = value;
    }
    else if (strcmp("pos", key) == 0) {
        pos = value;
    }
    else if(strcmp("force", key) == 0) {
        force = value;
    }
    else if(strcmp("leadership", key) == 0) {
        leadership = value;
    }
    else if(strcmp("wisdom", key) == 0) {
        wisdom = value;
    }
    else if(strcmp("attackValue", key) == 0) {
        attackValue = value;
    } 
    else if(strcmp("hp", key) == 0) {
        hp = value;
    } 
    else if(strcmp("defenseValue", key) == 0) {
        defenseValue = value;
    }
    else if(strcmp("ownArmy", key) == 0) {
        ownArmy = value;
    }
    else if (strcmp("killerArmy", key) == 0) {
        killArmy = value;
    }
    else if (strcmp("skillEffects", key) == 0) {
        skillEffects = value;
    } 
    else {
        flag = false;
    }
    return flag;
}



