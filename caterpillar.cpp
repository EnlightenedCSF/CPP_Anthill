#include <iostream>
#include "caterpillar.h"
#include "worldoptions.h"
#include "queen.h"

Caterpillar::Caterpillar(Anthill* anthill) : Insect(anthill)
{
    foodLeft_ = WorldOptions::getLarvaFoodToGrow();
}

void Caterpillar::Tick() {
    if (--foodLeft_ == 0) {
        anthill_->GetQueen()->EvolveLarva();
        anthill_->KillInsect(this, LARVA);
    }
}
