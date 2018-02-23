#ifndef _BUFF
#define _BUFF

struct EffectParam {
	bool percent;	//绝对值or百分比
	int  value      //参数值
};

class ArmyBuff {
	int freezeAttackCount ;
    int shyFightCount ;
    //freezeWaveAttackCount : 0;
    //freezeRoundAttackCount : 0;
    int immuneChaosCount;
    int immuneSkillCount;
    int immuneRetreatHeroCount;
    int immuneRetreatArmyCount;
    int reflectSkillCount;
    EffectParam attackValueTune;
    EffectParam defenseValueTune;
    EffectParam restrictionValueTune;
    EffectParam skillRateTune;
    EffectParam curse;    //诅咒
    EffectParam blessing;    //祝福
    EffectParam soldierHPValueTune;   // 士兵生命加成
    int attackContinuousCount;
    int ignoreRestriction;
    int disableDefense;
    int disableArrowTower;
    int disableWall;
    int buildingBuff; //TODO　建筑加成buff
    int plusBuff;             //TODO 神兽等其他类型加成buff
    int criticalPercent;
    int silentCount;

    public:
    ArmyBuff();
    ArmyBuff(int buildingBuff; int plusBuff);
    int getNormalValue(char* name);
    EffectParam getStructValue(char* name);
    int setValue(char* name; int value; int percent=0);
};

class HeroBuff {
	int invisibleCount ; //不能成为目标，
    int tauntCount ; //优先成为目标
    int immuneRetreatCount ; // 自身免疫退将
    bool tempInvisible ; // 只有一次效果的不能成为目标
    bool tempTaunt ; // 只有一次效果的优先成为目标
    bool tempImmuneRetreat ; //只有一次效果的免疫退将
    EffectParam leaderTune ; // 统率增减
    EffectParam forceTune ; // 武力增减
    EffectParam wisdomTune ; // 智力增减
    EffectParam attackTune ; // 攻击增减
    EffecfParam defenseTune ; // 防御增减
    EffectParam hpTune ; // 生命增减
    int deathRattleInvalidCount;  //亡语失效
    int silentCount; //沉默
    int reliveCount; //复活
    int rebornCount; //重生
    EffectParam fortuneTune; //武将运增减

    public:
        HeroBuff(){
            invisibleCount = 0;
            tauntCount = 0;
            immuneRetreatCount = 0;
            tempInvisible = false;
            tempTaunt = false;
            tempImmuneRetreat = false;
            deathRattleInvalidCount = 0;
            silentCount = 0;
            reliveCount = 0;
            rebornCount = 0;
            leaderTune.percent = 0;
            leaderTune.value = 0;
            forceTune.percent = 0;
            forceTune.value = 0;
            wisdomTune.percent = 0;
            wisdomTune.value = 0;
            attackTune.percent = 0;
            attackTune.value = 0;
            defenseTune.percent = 0;
            defenseTune.value = 0;
            hpTune.percent = 0;
            hpTune.value = 0;
            fortuneTune.percent = 0;
            fortuneTune.value = 0;
        }
}





