#ifndef DAYINFO_H
#define DAYINFO_H

class DayInfo
{
public:
    DayInfo();

    void Refresh();

    void ProduceFood(int);
    void ConsumeFood(int);

    void RegisterKillByPest();
    void RegisterPestKilled();
    void RegisterStarvationDeath();

    int GetFoodProduced() { return foodProduction_; }
    int GetFoodConsumed() { return foodLoss_; }

    int GetPestKills() { return pestKills_; }
    int GetPestKilled() { return pestsKilled_; }

    int GetAntsDiedFromStarvation() { return hungerDead_; }

private:
    int foodProduction_;
    int foodLoss_;

    int pestsKilled_;
    int pestKills_;

    int hungerDead_;
};

#endif // DAYINFO_H
