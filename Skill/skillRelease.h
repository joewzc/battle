#ifndef _SKILL_RELEASE
#define _SKILL_RELEASE

enum CombatMode {
    "none" = 0,                   //无限制
    "attackCity" = 1,             //攻城战
    "underCity" = 2,              //城下战
    "attackRobber" = 3,           //平匪
    "invade" = 4,                 //掠地
    "faction" = 5,                //阵营战
    "arena" = 6,                  //演武
    "practice" = 7,                //家族里切磋
    "search" = 8
};

enum Opportunity {
    "passive" = 1,                //阵前释放
    "fightStartOnce" = 2,         //首次出阵
    "fightStartEveryTime" = 3,    //每当出阵
    "armyRetreated" = 4,          //击破敌军
    "heroRetreated" = 5,          //武将退却
    "fightEndOnce" = 6,           //首次归阵
    "fightEndEveryTime" = 7,      //每当归阵
    "otherAllyArmyRetreated"= 8,  //每当我方其他军团退却
    "otherAllyHeroRetreated" = 9, //每当我方其他武将退却
    "enemyHeroRetreated" = 10     //每当敌方武将退却
};

enum Condition {
    "asAttacher" = 1,   //作为进攻方
    "asDefender" = 2    //作为防守方
};

enum EffectObject {
    "armyHerosSelf" = 13,   //本方全军武将
    "armyGroupHeroSelf" = 19,       //本方全军武将
    "armyRandomHeroSelf" = 9  //本军团１随机武将
};

#endif


