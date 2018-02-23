#ifndef _BUFF_H

#define

class Buff {
    float attackValueTune;
    float defenseValueTune;
    float rescueValueTune;
    float yinglieciLevel;
    public:
    Buff(): attackValueTune(0.0), defenseValueTune(0.0), rescueValueTune(0.0), yinglieciLevel(0.0) {}
    Buff(buff buffValue) {
        attackValueTune = buffValue.attackValueTune;
        defenseValueTune = buffValue.defenseValueTune;
        rescueValueTune = buffValue.rescueValueTune;
        yinglieciLevel = buffValue.yinglieciLevel;
    }
    float getValue(char* key);
    int setValue(char*, float);
};

class BattleBuff {
    Buff attackBuildingBuff;
    Buff defenseBuildingBuff;
    float attackerPlusBuff;
    float defenserPlusBuff;
    float attackPlusBuff;
    float defensePlusBuff;
    public:
    BattleBuff(): attackBuildingBuff(), defenseBuildingBuff(), attackerPlusBuff(0.0), defenserPlusBuff(0.0), attackPlusBuff(0.0), defensePlusBuff(0.0) {}

};

class PercentAndValue {
	int percent;
	int value;
    public:
    percentAndValue(): percent(0), value(0) {}
	PercentAndValue(int p, int v): percent(p), value(v) {}
	PercentAndValue(PercentAndValue pv): percent(pv.percent), value(pv.value) {}
};

class ArmyBuff {
    int             freezeAttackCount;
    int             shyFightCount;
    int             immuneChaosCount;
    int             immuneSkillCount;
    int             immuneRetreatHeroCount;
    int             immuneRetreatArmyCount;
    int             reflectSkillCount;
    PercentAndValue attackValueTune;
    PercentAndValue defenseValueTune;
    PercentAndValue restrictionValueTune;
    PercentAndValue skillRateTune;
    PercentAndValue curse;    //诅咒
    PercentAndValue blessing;    //祝福
    PercentAndValue soldierHPValueTune;   // 士兵生命加成
    int             attackContinuousCount;
    int             ignoreRestriction;
    int             disableDefense;
    int             disableArrowTower;
    int             disableWall;
    Buff            buildingBuff;
    int             plusBuff;
    int             criticalPercent ;
    int             silentCount;
    
    public:
    ArmyBuff():freezeAttackCount(0), shyFightCount(0), immuneChaosCount(0), immuneSkillCount(0), immuneRetreatHeroCount(0), immuneRetreatArmyCount(0),\
               reflectSkillCount(0), attackValueTune(), defenseValueTune(), restrictionValueTune(), skillRateTune(), curse(),\
               blessing(), soldierHPValueTune(), attackContinuousCount(0), ignoreRestriction(0), disableDefense(0), disableArrowTower(0),\
               disableWall(0), plusBuff(0), criticalPercent(0), silentCount(0), buildingBuff() {}
    template<typename T>
    int setValue(char*, T key);
};


class HeroBuff {
	int 			invisibleCount ; //不能成为目标，
	int           	tauntCount ; //优先成为目标
	int        		immuneRetreatCount ; // 自身免疫退将
	bool     		tempInvisible ; // 只有一次效果的不能成为目标
	bool   			tempTaunt ; // 只有一次效果的优先成为目标
	bool      		tempImmuneRetreat; //只有一次效果的免疫退将
	PercentAndValue	leaderTune ;// 统率增减
	PercentAndValue forceTune  ;// 武力增减
	PercentAndValue wisdomTune ;// 智力增减
	PercentAndValue attackTune  ;// 攻击增减
	PercentAndValue defenseTune ; // 防御增减
	PercentAndValue hpTune ; // 生命增减
	int             deathRattleInvalidCount ;  //亡语失效
	int            	silentCount ; //沉默
	int         	reliveCount ; //复活
	int      		rebornCount ; //重生

	HeroBuff(): invisibleCount(0), tauntCount(0), immuneRetreatCount(0), tempInvisible(false), tempTaunt(false), tempImmuneRetreat(false), leaderTune(),\
				forceTune(), wisdomTune(), attackTune(), defenseTune(), hpTune(), deathRattleInvalidCount(0), silentCount(0), reliveCount(0), rebornCount(0) {}
};

class OutputBuff {
    bool attackHospitalDisable;
    bool defenseHospitalDisable;
    float destroyBuildingPercent;
};

#endif
