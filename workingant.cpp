using namespace std;

#include <iostream>

#include "workingant.h"


WorkingAnt::WorkingAnt(Anthill* anthill) : Insect(anthill) {
    hp_ = WorldOptions::getWorkingAntHp();
}

void WorkingAnt::Tick() {
    anthill_->StoreFood(WorldOptions::getWorkingAntProduction());
    if (!anthill_->TakeFood(WorldOptions::getWorkingAntFood()))
        anthill_->KillInsect(this, WORKING_ANT, true);
}
