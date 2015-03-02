#include <stdlib.h>

#include "pestant.h"

PestAnt::PestAnt(Anthill* anthill) : Insect(anthill) {}

void PestAnt::Tick() {
    int r = rand() % 100;
    if (r <= 14) {
        anthill_->KillRandomInsect();
    }

    anthill_->TakeFood(2);
}
