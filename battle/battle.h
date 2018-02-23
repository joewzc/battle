#ifndef _BATTLE_H

#define

#include <map>
#include "buff.h"

class SkillEffect {
    int     id;
    int     range;
    int     asid;
    int     dsid;
    int     ahid;
    int     dhid;
    int     define;
    float   value;
    int     state;
};

class SkillRecord {
    char*   type;
    bool    launch;
    int     skillID;
    int     soldierID;
    int     heroID;
    bool    isOwnSkill;
    int     wave;
    int     round;
    std::vector<SkillEffect> skillEffects;
};

class EventBase {
    std::map<int, int> event;
};

class EventRecord {
    char* type;
    std::vector<std::map<int, EventBase>>   aevents;
    std::vector<std::map<int, EventBase>>   devents;
};


class BattleRecord {
    public:
    char* type;
    std::map<std::string, float>  AS;
    std::map<std::string, float>  DS;
    std::map<std::string, float>  AH;
    std::map<std::string, float>  DH;
};

class BattleResult {
    OutputBuff                  outputBuff;
    std::vector<SkillRecord>    pskills;
    int                         result;
    bool                        allDead;
    std::map<int, int>          newAttackSoldiers;
    std::map<int, int>          newDefenseSoldiers;
    std::map<int, int*>         loseAttackHeros;
    std::map<int, int*>         loseDefenseHeros;
    std::vector<std::map<int, EventBase>>   aevents;
    std::vector<std::map<int, EventBase>>   devents;
};

#endif
