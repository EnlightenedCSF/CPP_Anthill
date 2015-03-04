#ifndef POLICEANT_H
#define POLICEANT_H

#include <vector>

#include "insect.h"

class PoliceAnt : public virtual Insect
{
public:
    PoliceAnt(Anthill*);
    void Tick();

    void Penny();
    void Benny();
    int GetControlledAntsCount() { return workingAntsUnderControl_; }
private:
    int workingAntsUnderControl_;
};

#endif // POLICEANT_H
