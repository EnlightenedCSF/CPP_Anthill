#include <iostream>

#include "caterpillar.h"
#include "worldoptions.h"
#include "queen.h"

larva::larva(Anthill* anthill) : Insect(anthill)
{
    ticksLeft_ = WorldOptions::getLarvaTicksToGrow();
    hp_ = WorldOptions::getLarvaHp();
}

void larva::Tick() {
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
