#include "dayinfo.h"

DayInfo::DayInfo()
{
    Refresh();
}

void DayInfo::Refresh() {
    foodLoss_ = 0;
    foodProduction_ = 0;

    pestKills_ = 0;
    pestsKilled_ = 0;

    hungerDead_ = 0;
}

void DayInfo::ProduceFood(int amount) {
    foodProduction_ += amount;
}

void DayInfo::ConsumeFood(int amount) {
    foodLoss_ += amount;
}

void DayInfo::RegisterKillByPest() {
    pestKills_++;
}

void DayInfo::RegisterPestKilled() {
    pestsKilled_++;
}

void DayInfo::RegisterStarvationDeath() {
    hungerDead_++;
}
