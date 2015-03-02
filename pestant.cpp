#include <stdlib.h>

#include "pestant.h"

PestAnt::PestAnt(Anthill* anthill) : Insect(anthill) {}

void PestAnt::Tick() {
    int r = rand() % 100;
    if (r <= WorldOptions::getPestKillProbability()) {
        anthill_->KillRandomInsect();
    }

    if (!anthill_->TakeFood(WorldOptions::getPestFood()))
        anthill_->KillInsect(this, PEST_ANT, true);
}
