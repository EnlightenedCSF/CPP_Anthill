using namespace std;

#include <iostream>
#include "workingant.h"


WorkingAnt::WorkingAnt(Anthill* anthill) : Insect(anthill)
{

}

WorkingAnt::~WorkingAnt()
{

}

void WorkingAnt::Tick() {
    anthill_->StoreFood(2);
    anthill_->TakeFood(1);
}
