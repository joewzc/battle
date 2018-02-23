#ifndef _HERO_H
#define
#include <vector>
#include "buff.h"

class HeroBase {
    int id;
    int level;
    int sWisdom;
    int sLeader;
    int sForce;
    int sFortune;
    int star;
    int elv;
    int pos;
    public:
    HeroBase(int _id, int _level, int _sWisdom, int _sLeader, int _sForce, int _sFortune, int _star, int _elv, int _pos) : \
        id(_id), level(_level), sWisdom(_sWisdom), sLeader(_sLeader), sForce(_sForce), sFortune(_sFortune), star(_star), elv(_elv), pos(_pos) {}
    HeroBase(HeroBase heroData) ;
    virtual int getValue(char* );
    HeroBase& operation = (HeroBase *);
    virtual int setValue(char *);
    ~HeroBase(){}

};


class HeroBattle : public HeroBase {
    int force;
    int leadership;
    int wisdom;
    int attackValue;
    int hp;
    int defenseValue;
    bool isAttacker;
    int ownArmy;
    int heroData;
    int killerArmy ;
    std::vector<int> skillEffects;
    int skillLength;

    HeroBuff* heroBuff;
    HeroBattle(HeroBase);
    virtual int getValue(char*);
    template <typename T>
    virtual bool setValue(char*, T);
    ~HeroBattle();
}


#endif
