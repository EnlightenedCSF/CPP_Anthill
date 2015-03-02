#ifndef WORLDOPTIONS_H
#define WORLDOPTIONS_H

#include <stdio.h>
#include <stdlib.h>

#define ANT_TYPES_CNT 5
#define LARVA 0
#define WORKING_ANT 1
#define POLICE_ANT 2
#define PEST_ANT 3
#define SOLDIER 4

class WorldOptions
{
public:
    WorldOptions(FILE*);

    static int getQueenFood() { return queenFood_; }
    static int getQueenLavaire() { return queenLavaire_; }
    static int getSoldierFood() { return soldierFood_; }
    static int getSoldierPestKillAmount() { return soldierPestKillAmount_; }
    static int getPoliceFood() { return policeFood_; }
    static int getPoliceBonus() { return policeBonus_; }
    static int getWorkingAntFood() { return workingAntFood_; }
    static int getWorkingAntProduction() { return workingAntProduction_; }
    static int getLarvaFood() { return larvaFood_; }
    static int getLarvaTicksToGrow() { return larvaTicksToGrow_; }
    static int getPestKillProbability() { return pestKillProbability_; }
    static int getProbToBecomePest() { return probToBecomePest_; }
    static int getPestFood() { return pestFood_; }

private:
    static int queenFood_;
    static int queenLavaire_;

    static int soldierFood_;
    static int soldierPestKillAmount_;

    static int policeFood_;
    static float policeBonus_;

    static int workingAntFood_;
    static int workingAntProduction_;

    static int larvaFood_;
    static int larvaTicksToGrow_;

    static int pestFood_;
    static int probToBecomePest_;
    static int pestKillProbability_;
};

#endif // WORLDOPTIONS_H
