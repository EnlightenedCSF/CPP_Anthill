#ifndef POLICEANT_H
#define POLICEANT_H

#include <vector>

#include "insect.h"

class PoliceAnt : public virtual Insect
{
public:
    PoliceAnt(Anthill*);
    void Tick();

    void LostAntUnderControl();
    void TakeAnotherAntUnderControl();
    int GetControlledAntsCount() { return workingAntsUnderControl_; }
private:
    int workingAntsUnderControl_;
};

#endif // POLICEANT_H
