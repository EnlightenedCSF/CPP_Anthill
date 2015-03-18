#ifndef ANTHILL_H
#define ANTHILL_H

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>

#include "insect.h"
#include "worldoptions.h"
#include "dayinfo.h"

class Queen;
class Insect;
class Soldier;
class PestAnt;

using namespace std;

class Anthill
{
public:
    Anthill(FILE*);
    ~Anthill();
    void InputAntTypes();

    void Tick();

    Queen* GetQueen();

    void StoreFood(double);
    bool TakeFood(double);
    int GetFoodAmount();

    int GetAntCount();
    int GetAntCount(int);

    void AddInsect(int);
    void KillInsect(Insect*, int, bool);

    bool FightPest(Soldier*);
    bool FightWithRandomAnt(PestAnt*);
    void KillQueen();

private:
    vector<string> &Split(const string &s, char delim, vector<string> &elems);
    int population_[ANT_TYPES_CNT];
    vector<Insect*>* insects_;
    bool isQueenAlive_;

    double foodAmount_;

    WorldOptions* worldOptions_;
    DayInfo* dayInfo_;
    int day_;
    float randSumToSpawnPest_;

    int GetAntUnderControlCount();
};

#endif // ANTHILL_H
