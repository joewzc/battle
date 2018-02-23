#ifndef _SOLDIER_H

#define

class SoldierBase {
    int id;
    int number;
    int trainLv;
    int pos;
    std::vector<int> skillIDs;
    int elv;
    public:
    SoldierBase(int, int, int, int, int [], int , int);
    SoldierBase(SoldierBase);
    template<typename T>
    int setValue(char* key, T value, int length=0);
    ~SoldierBase(){
    //    delete[] skillIDs;
    }
};

class SoldierBattle : public SoldierBase {
    int attackValue;
    int defenseValue;
    int speed;
    int hp;
    int originalNumber;
    int force;
    int wisdom;
    public:
    SoldierBattle(SoldierBase);
    template<typename T>
    int setBattleValue(char* key, T value);
};
#endif
