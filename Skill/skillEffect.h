#ifndef _SKILL_EFFECT
#define _SKILL_EFFECT

enum SkillEffectFX {
     "hit" = 6,                    //受击
     "attackAndDefenseUp" = 11,    //攻防上升
     "attackUp" = 12,              //攻击上升
     "defenseUp" = 13,             //防御上升
     "attackAndDefenseDown" = 21,  //攻防下降
     "attackDown" = 22,            //攻击下降
     "defenseDown" = 23,           //防御下降
     "defenseBroken" = 24,         //防御归0，即无效
     "swimming" = 31,              //眩晕
     "curse" = 32,                 //诅咒
     "bless" = 33,                 //祝福
     "revive" = 41,                //复活
     "immuneChaos" = 51,           //免疫混乱
     "immuneSkill" = 52,           //免疫技能
     "reflectSkill" = 53,          //反射技能
     "quitBattleField" = 63        //退出战场（非特效）
};

enum SkillEffect {
    "produceUp" = 1,                //生产加成
    "buildSpeedUp" = 2,             //建筑加速
    "attackAndDefenseUp" = 3,         //攻防加成
    "attackUp" = 4,                   //攻击加成
    "defenseUp" = 5,                  //防御加成
    "revive" = 6,                     //回复士兵
    "destroySoldierDirectly" = 7,     //消灭士兵
    "freezeAttack1" = 8,              //军团动摇
    "freezeAttack3" = 9,              //军团混乱
    "retreatHero" = 10,               //武将退却
    "retreatArmy" = 11,               //军团退却
    "attackOnceMore" = 12,            //额外攻击
    "immuneChaos" = 13,               //免疫混乱
    "immuneSkill" = 14,               //免疫计谋
    "reflectSkill" = 15,              //反射计谋
    "attackAndDefenseDown" = 16,      //攻防下降
    "attackDown" = 17,                //攻击下降
    "defenseDown" = 18,               //防御下降
    "defenseBroken" = 19,             //防御失效
    "arrowTowerInvalid" = 20,         //箭塔失效
    "cityWallInvalid" = 21,           //城墙失效
    "restrictionInvalid" = 22,        //相克失效
    "restrictionUp" = 23,             //相克加成
    "skillRateUp" = 24,               //技能成功率提升
    "revivePeople" = 25,            //人口回复加成
    "hospitalUp" = 26,                //医馆回复加成
    "destroySoliderBySoldier" = 27,   //消灭士兵
    "shyFight" = 28,                  //军团怯战
    "destroySoliderByForce" = 29,     //消灭士兵-武力
    "destroySoliderByWisdom" = 30,    //消灭士兵-智力
    "curse" = 31,                     //诅咒
    "bless" = 32,                     //祝福
    "hospitalInvalid" = 33,           //屠杀
    "destroyBuilding" = 34,           //破坏
    "storageUp" = 35,               //仓库加成
    "arrowTowerUp" = 36,            //箭塔加成
    "cityWallUp" = 37,              //城墙加成
    "trainSoldierCostDown" = 38,    //训练消耗
    "trainHeroCostDown" = 39,       //修行消耗
    "dakUp" = 40,                   //驿站加成
    "immuneRetreatHero" = 41,         //免疫退将
    "soldierHPUp" = 42,               //士兵生命加成
    "soldierHPDown" = 43,             //士兵生命下降
    "skillRateDown" = 44,             //技能成功率下降
    "leadershipUp" = 45,              //增加武将统率
    "wisdomUp" = 46,                  //增加武将智力
    "forceUp" = 47,                   //增加武将武力
    "heroAttackUp" = 48,              //增加武将攻击
    "heroDefenseUp" = 49,             //增加武将防御
    "heroHPUp" = 50,                  //增加武将生命
    "invisible" = 51,                 //不能成为目标
    "taunt" = 52,                     //优先成为目标
    "leadershipDown" = 53,            //减少武将统率
    "wisdomDown" = 54,                //减少武将智力
    "forceDown" = 55,                 //减少武将武力
    "heroAttackDown" = 56,            //减少武将攻击
    "heroDefenseDown" = 57,           //减少武将防御
    "heroHPDown" = 58,                //减少武将生命
    "attackContinuous" = 59,          //连击
    "critical" = 60,                  //暴击
    "removeNegativeBuff" = 61,        //移除减益buff
    "transferAllBuff" = 62,           //转移所有Buff
    "deathRattleInvalid" = 63,        //亡语失效
    "deathRattleTakeEffect" = 64,     //亡语触发
    "transferPositiveBuff" = 65,      //转移增益Buff 将目标军团增益buff转移给本军团
    "transferNegativeBuff" = 66,      //转移减益Buff 将本军团减益buff转移给目标军团
    "removeAllBuff" = 67,             //移除所有Buff
    "removeAllPositiveBuff" = 68,     //移除增益Buff
    "immuneRetreatArmy" = 69,         //免疫退军团
    "silent" = 70,                    //沉默，无法放技能
    "relive" = 74,                    //复活，技能不重置, 之所不用revive是因为6已经用了
    "reborn" = 75,                    //重生，技能会重置
    "callback" = 76                   //召回，技能会重置
};

enum DebuffEffect {

};

enum EffectDefine {
    "absolute" = 1,     //绝对值
    "percent" = 2,      //百分比值
    "id" = 3            //ID
};

enum EndType {
    "once" = 1,         //一次
    "oneTurn" = 2,      //一轮
    "wholeBattle" = 3   //整场战斗
};



#endif
