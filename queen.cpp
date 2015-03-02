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

    float probPestCnt = anthill_->GetAntCount(WORKING_ANT) * (WorldOptions::getProbToBecomePest() / (float)100);
    int soldierEffectiveness = anthill_->GetAntCount(SOLDIER) * WorldOptions::getSoldierPestKillAmount();

    if (probPestCnt > soldierEffectiveness) {
        anthill_->AddInsect(SOLDIER);
    }
    else {
        anthill_->AddInsect(WORKING_ANT);
    }
}
