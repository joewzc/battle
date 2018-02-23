#include "soldier.h"


SoldierBase::SoldierBase(SoldierBase soldier)
{
    id = soldier.id;
    number = soldier.number;
    trainLv = soldier.trainLv;
    pos = soldier.pos;
    elv = soldier.elv;
    std::vector<int>::iterator it = soldier.skillIDs.begin();
    for( ; it != soldier.skillIDs.end(); it++) 
    {
        skillIDs.push_back(*it);
    }
}


SoldierBase::SoldierBase(int _id, int _pos, int _number, int _trainLv, int  skill[], int _elv, int _length){
    id = _id;
    number = _number;
    trainLv = _trainLv;
    elv = _elv;
    pos = _pos;
    for(int index=0; index<_length; index++) {
        skillIDs.push_back(skill[index]);  
    }
}

template<typename T>
int SoldierBase::setValue(char* key, T value, int length=0) 
{
    if(strcmp(key, "id") == 0)
    {
        id = value;
    }
    else if(strcmp(key, "number") == 0)
    {
        number = value;
    }
    else if(strcmp(key, "trainLv") == 0)
    {
        trainLv = value;
    }
    else if(strcmp(key, "pos") == 0)
    {
        pos = value;
    }
    else if(strcmp(key, "elv") == 0)
    {
        elv = value;
    }
    else if(strcmp(key, "skillIDs") == 0)
    {
       for(int index=0; index<length; index++)
       {
           skillIDs.push_back(value[index]);
       }
    } 
    else 
    {
        return -1;
    }

    return 0;
}


SoldierBattle::SoldierBattle(SoldierBase soldier): SolderBase(soldier) {
    attackValue = 0;
    defenseValue = 0;
    speed = 100 - soldier.pos;
    hp = 0;
    originalNumber = soldier.number;
    force = 0;
    wisdom = 0;
}


template<typename T1>
int SoldierBattle::setValue(char* key, T1 value, int length=0) 
{
    if(strcmp(key, "id") == 0)
    {
        id = value;
    }
    else if(strcmp(key, "number") == 0)
    {
        number = value;
    }
    else if(strcmp(key, "trainLv") == 0)
    {
        trainLv = value;
    }
    else if(strcmp(key, "pos") == 0)
    {
        pos = value;
    }
    else if(strcmp(key, "elv") == 0)
    {
        elv = value;
    }
    else if(strcmp(key, "skillIDs") == 0)
    {
       for(int index=0; index<length; index++)
       {
           skillIDs.push_back(value[index]);
       }
    }
    else if(strcmp(key, "attackValue") == 0) 
    {
        attackValue = value;
    } 
    else if(strcmp(key, "defenseValue") == 0)
    {
        defenseValue = value;
    }
    else if(strcmp(key, "speed") == 0)
    {
        speed = value;
    }
    else if(strcmp(key, "hp") == 0) 
    {
        hp = value;
    }
    else if(strcmp(key, "originalNumber") == 0) 
    {
        originalNumber = value;
    }
    else if(strcmp(key, "force") == 0)
    {
        force = value;
    }
    else if(strcmp(key, "wisdom") == 0)
    {
        wisdom = value;
    }
    else 
    {
        return -1;
    }

    return 0;
}

