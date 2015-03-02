using namespace std;

#include <iostream>
#include <stdlib.h>

#include "workingant.h"


WorkingAnt::WorkingAnt(Anthill* anthill) : Insect(anthill) { }

void WorkingAnt::Tick() {
    anthill_->StoreFood(WorldOptions::getWorkingAntProduction());
    if (!anthill_->TakeFood(WorldOptions::getWorkingAntFood()))
        anthill_->KillInsect(this, WORKING_ANT, true);

    int prob = rand() % 100;
    if (prob < WorldOptions::getProbToBecomePest()) {
       anthill_->AddInsect(PEST_ANT);
       anthill_->KillInsect(this, WORKING_ANT, false);
    }
}
