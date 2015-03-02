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
        Queen* queen = anthill_->GetQueen();
        if (queen != 0)
            queen->EvolveLarva();

        anthill_->KillInsect(this, LARVA, false);
    }
    else {
        if (!anthill_->TakeFood(WorldOptions::getLarvaFood()))
            anthill_->KillInsect(this, LARVA, true);
        ticksLeft_--;
    }
}
