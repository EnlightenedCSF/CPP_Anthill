#include "soldier.h"

Soldier::Soldier(Anthill* anthill) : Insect(anthill) {
    hp_ = WorldOptions::getSoldierHp();
}

void Soldier::Tick() {
    for (int i = 0; i < WorldOptions::getSoldierPestKillAmount(); i++)
        if (!anthill_->FightPest(this)) {
            anthill_->KillInsect(this, SOLDIER, false);
        }

    if (!anthill_->TakeFood(WorldOptions::getSoldierFood()))
        anthill_->KillInsect(this, SOLDIER, true);
}
