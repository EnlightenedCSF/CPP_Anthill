#ifndef WORLDOPTIONS_H
#define WORLDOPTIONS_H

#define ANT_TYPES_CNT 3
#define LARVA 0
#define WORKING_ANT 1
#define POLICE_ANT 2

class WorldOptions
{
public:
    WorldOptions();
    ~WorldOptions();

    static void setLarvaFoodToGrow(int amount) { larvaFoodToGrow_ = amount; }
    static int getLarvaFoodToGrow() { return larvaFoodToGrow_; }
    static int getAntTypesCount() { return ANT_TYPES_CNT; }
    static int getCodeCaterpillar() { return LARVA; }
    static int getCodeWorkingAnt() { return WORKING_ANT; }
    static int getCodePoliceAnt() { return POLICE_ANT; }
private:
    static int larvaFoodToGrow_;
};

#endif // WORLDOPTIONS_H
