using namespace std;

#ifndef ANTHILL_H
#define ANTHILL_H

#include <vector>
#include "insect.h"
#include "foodsource.h"
#include "worldoptions.h"

class Queen;
class Insect;

class Anthill
{
public:
    Anthill(FILE* file);
    ~Anthill();
    void Tick();
    Queen* GetQueen();

    void StoreFood(int);
    bool TakeFood(int);
    int GetFoodAmount();

    int GetAntCount(int);

    void AddInsect(int);
    void KillInsect(Insect*, int);
private:
    vector<Insect*>* insects_;
    vector<FoodSource*>* foodSources_;
    int foodAmount_;

    int population_[ANT_TYPES_CNT];
};

#endif // ANTHILL_H
