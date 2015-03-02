#include <stdlib.h>

#include "worldoptions.h"

int WorldOptions::larvaFood_;
int WorldOptions::larvaTicksToGrow_;
int WorldOptions::queenFood_;
int WorldOptions::queenLavaire_;
int WorldOptions::soldierFood_;
int WorldOptions::soldierPestKillAmount_;
int WorldOptions::policeFood_;
float WorldOptions::policeBonus_;
int WorldOptions::workingAntFood_;
int WorldOptions::workingAntProduction_;


WorldOptions::WorldOptions(FILE* file)
{
    int queenFood = 3;
    fscanf(file, "%i\n", &queenFood);
    queenFood_ = queenFood;

    int queenLavaire = 2;
    fscanf(file, "%i\n", &queenLavaire);
    queenLavaire_ = queenLavaire;

    int soldierFood = 2;
    fscanf(file, "%i\n", &soldierFood);
    soldierFood_ = soldierFood;

    int soldierPestKillAmount = 2;
    fscanf(file, "%i\n", &soldierPestKillAmount);
    soldierPestKillAmount_ = soldierPestKillAmount;

    int policeFood = 2;
    fscanf(file, "%i\n", &policeFood);
    policeFood_ = policeFood;

    float policeFoodMiningIncrease = 0;
    fscanf(file, "%f\n", &policeFoodMiningIncrease);
    policeBonus_ = policeFoodMiningIncrease;

    int workingAntFood = 1;
    fscanf(file, "%i\n", &workingAntFood);
    workingAntFood_ = workingAntFood;

    int workingAntProduction = 2;
    fscanf(file, "%i\n", &workingAntProduction);
    workingAntProduction_ = workingAntProduction;

    int larvaFood = 3;
    fscanf(file, "%i\n", &larvaFood);
    larvaFood_ = larvaFood;

    int larvaTicksToGrow = 3;
    fscanf(file, "%i\n", &larvaTicksToGrow);
    larvaTicksToGrow_ = larvaTicksToGrow;
}

WorldOptions::~WorldOptions()
{

}
