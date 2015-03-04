using namespace std;

#include <iostream>

#include "workingant.h"


WorkingAnt::WorkingAnt(Anthill* anthill) : Insect(anthill) {
    hp_ = WorldOptions::getWorkingAntHp();
}

void WorkingAnt::Tick() {
    double production = WorldOptions::getWorkingAntProduction();
    if (HasFather())
        production *= 1.1;

    anthill_->StoreFood(production);
    if (!anthill_->TakeFood(WorldOptions::getWorkingAntFood()))
        anthill_->KillInsect(this, WORKING_ANT, true);
}
