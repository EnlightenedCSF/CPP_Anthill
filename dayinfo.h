#ifndef DAYINFO_H
#define DAYINFO_H

class DayInfo
{
public:
    DayInfo();

    void Refresh();

    void ProduceFood(double);
    void ConsumeFood(double);

    void RegisterKillByPest();
    void RegisterPestKilled();
    void RegisterStarvationDeath();

    double GetFoodProduced() { return foodProduction_; }
    double GetFoodConsumed() { return foodLoss_; }

    int GetPestKills() { return pestKills_; }
    int GetPestKilled() { return pestsKilled_; }

    int GetAntsDiedFromStarvation() { return hungerDead_; }

private:
    double foodProduction_;
    double foodLoss_;

    int pestsKilled_;
    int pestKills_;

    int hungerDead_;
};

#endif // DAYINFO_H
