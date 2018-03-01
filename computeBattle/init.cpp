void initArmyInfo(Army[] armies, int armySize, int soldiers[], int newNumbers[], int loseHeros[], bool isAttacker, BuildingBuff buff) {

    //TODO 当计算结束时需要释放该处内存
    BattleArmy battleArmy[armySize] = {};
    for(int index=0; index<armySize; index++) {
        BattleArmy battleArmy[index] = new BattleArmy(armies[index], isAttacker); 
    }
    
}
