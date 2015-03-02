#include <iostream>

#include "caterpillar.h"
#include "worldoptions.h"
#include "queen.h"

Caterpillar::Caterpillar(Anthill* anthill) : Insect(anthill)
{
    ticksLeft_ = WorldOptions::getLarvaTicksToGrow();
}

void Caterpillar::Tick() {
    if (ticksLeft_ == 0) {
        anthill_->GetQueen()->EvolveLarva();
        anthill_->KillInsect(this, LARVA);
    }
    else {
        ticksLeft_--;
        anthill_->TakeFood(WorldOptions::getLarvaFood());
    }
}
