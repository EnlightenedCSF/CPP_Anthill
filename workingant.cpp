using namespace std;

#include <iostream>
#include "workingant.h"


WorkingAnt::WorkingAnt(Anthill* anthill) : Insect(anthill)
{

}

void WorkingAnt::Tick() {
    anthill_->StoreFood(WorldOptions::getWorkingAntProduction());
    anthill_->TakeFood(WorldOptions::getWorkingAntFood());
}
