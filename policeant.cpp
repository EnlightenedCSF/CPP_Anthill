using namespace std;

#include "policeant.h"


PoliceAnt::PoliceAnt(Anthill* anthill) : Insect(anthill)
{
    hp_ = WorldOptions::getPoliceHp();
}

void PoliceAnt::Tick() {
}
