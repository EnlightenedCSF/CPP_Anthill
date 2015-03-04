using namespace std;

#include "policeant.h"


PoliceAnt::PoliceAnt(Anthill* anthill) : Insect(anthill)
{
    hp_ = WorldOptions::getPoliceHp();
    workingAntsUnderControl_ = 0;
}

void PoliceAnt::Tick() {
    if (!anthill_->TakeFood(WorldOptions::getPoliceFood())) {
        anthill_->KillInsect(this, POLICE_ANT, true);
    }
}

void PoliceAnt::Penny() {
    workingAntsUnderControl_--;
}

void PoliceAnt::Benny() {
    workingAntsUnderControl_++;
}
