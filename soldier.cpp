#include "soldier.h"

Soldier::Soldier(Anthill* anthill) : Insect(anthill) {}

void Soldier::Tick() {
    for (int i = 0; i < WorldOptions::getSoldierPestKillAmount(); i++)
        anthill_->KillPest();

    if (!anthill_->TakeFood(WorldOptions::getSoldierFood()))
        anthill_->KillInsect(this, SOLDIER, true);
}
