#include <iostream>

#include "queen.h"

Queen::Queen(Anthill* anthill) : Insect(anthill) {
    ticksToMakeLarva_ = WorldOptions::getQueenLavaire();
}

void Queen::Tick() {
    if (--ticksToMakeLarva_ == 0) {
        anthill_->AddInsect(LARVA);
        ticksToMakeLarva_ = WorldOptions::getQueenLavaire();
    }

    if (!anthill_->TakeFood(WorldOptions::getQueenFood()))
        anthill_->KillQueen();
}

void Queen::EvolveLarva() {
    anthill_->AddInsect(POLICE_ANT);
}
