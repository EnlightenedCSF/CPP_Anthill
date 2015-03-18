#include <stdlib.h>

#include "worldoptions.h"

int WorldOptions::larvaHp_;
int WorldOptions::larvaFood_;
int WorldOptions::larvaTicksToGrow_;
int WorldOptions::queenFood_;
int WorldOptions::queenLavaire_;
int WorldOptions::soldierHp_;
int WorldOptions::soldierFood_;
int WorldOptions::soldierPestKillAmount_;
int WorldOptions::policeHp_;
int WorldOptions::policeFood_;
int WorldOptions::workingAntHp_;
int WorldOptions::workingAntFood_;
int WorldOptions::workingAntProduction_;
int WorldOptions::pestFood_;
int WorldOptions::pestHp_;
float WorldOptions::daysToSpawnPest_;
int WorldOptions::policeWorkersCount_;


WorldOptions::WorldOptions(FILE* file)
{
    int queenFood = 3;
    fscanf(file, "%i\n", &queenFood);
    queenFood_ = queenFood;

    int queenLavaire = 2;
    fscanf(file, "%i\n", &queenLavaire);
    queenLavaire_ = queenLavaire;

    int soldierHp = 3;
    fscanf(file, "%i\n", &soldierHp);
    soldierHp_ = soldierHp;

    int soldierFood = 2;
    fscanf(file, "%i\n", &soldierFood);
    soldierFood_ = soldierFood;

    int soldierPestKillAmount = 2;
    fscanf(file, "%i\n", &soldierPestKillAmount);
    soldierPestKillAmount_ = soldierPestKillAmount;

    int policeHp = 3;
    fscanf(file, "%i\n", &policeHp);
    policeHp_ = policeHp;

    int policeFood = 2;
    fscanf(file, "%i\n", &policeFood);
    policeFood_ = policeFood;

    int workingAntHp = 2;
    fscanf(file, "%i\n", &workingAntHp);
    workingAntHp_ = workingAntHp;

    int workingAntFood = 1;
    fscanf(file, "%i\n", &workingAntFood);
    workingAntFood_ = workingAntFood;

    int workingAntProduction = 2;
    fscanf(file, "%i\n", &workingAntProduction);
    workingAntProduction_ = workingAntProduction;

    int larvaHp = 1;
    fscanf(file, "%i\n", &larvaHp);
    larvaHp_ = larvaHp;

    int larvaFood = 3;
    fscanf(file, "%i\n", &larvaFood);
    larvaFood_ = larvaFood;

    int larvaTicksToGrow = 3;
    fscanf(file, "%i\n", &larvaTicksToGrow);
    larvaTicksToGrow_ = larvaTicksToGrow;

    int pestHp = 5;
    fscanf(file, "%i\n", &pestHp);
    pestHp_ = pestHp;

    int pestFood = 2;
    fscanf(file, "%i\n", &pestFood);
    pestFood_ = pestFood;

    float daysToSpawnPest = 3.5;
    fscanf(file, "%f\n", &daysToSpawnPest);
    daysToSpawnPest_ = daysToSpawnPest;

    int p = 5;
    fscanf(file, "%i\n", &p);
    policeWorkersCount_ = p;
}
