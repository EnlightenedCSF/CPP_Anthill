using namespace std;

#ifndef ANTHILL_H
#define ANTHILL_H

#include <stdio.h>
#include <vector>

#include "insect.h"
#include "worldoptions.h"
#include "dayinfo.h"

class Queen;
class Insect;
class Soldier;
class PestAnt;


class Anthill
{
public:
    Anthill(FILE*);
    ~Anthill();
    void Tick();
    Queen* GetQueen();

    void StoreFood(int);
    bool TakeFood(int);
    int GetFoodAmount();

    int GetAntCount();
    int GetAntCount(int);

    void AddInsect(int);
    void KillInsect(Insect*, int, bool);

    bool FightPest(Soldier*);
    bool FightWithRandomAnt(PestAnt*);
    void KillQueen();

private:
    int population_[ANT_TYPES_CNT];
    vector<Insect*>* insects_;
    bool isQueenAlive_;

    int foodAmount_;

    WorldOptions* worldOptions_;
    DayInfo* dayInfo_;
    int day_;
};

#endif // ANTHILL_H
