#include <iostream>
#include "queen.h"

Queen::Queen(Anthill* anthill) : Insect(anthill)
{

}

void Queen::Tick() {
    anthill_->TakeFood(3);
}

void Queen::EvolveLarva() {
    if (anthill_->GetAntCount(WORKING_ANT) < 30)
        anthill_->AddInsect(WORKING_ANT);
    else
        anthill_->AddInsect(WORKING_ANT);
}
