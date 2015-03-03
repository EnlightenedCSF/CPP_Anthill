#include "pestant.h"

PestAnt::PestAnt(Anthill* anthill) : Insect(anthill) {
    hp_ = WorldOptions::getPestHp();
}

void PestAnt::Tick() {

    if (!anthill_->FightWithRandomAnt(this)) {
        anthill_->KillInsect(this, PEST_ANT, false);
    }

    if (!anthill_->TakeFood(WorldOptions::getPestFood()))
        anthill_->KillInsect(this, PEST_ANT, true);
}
