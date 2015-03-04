#ifndef WORKINGANT_H
#define WORKINGANT_H

#include "insect.h"
#include "policeant.h"

class WorkingAnt : public virtual Insect
{
public:
    WorkingAnt(Anthill*);
    void Tick();

    void FindFather(PoliceAnt* vady) { LUKE_I_AM_YOUR_FATHER_ = vady; }
    void LoseFather() { LUKE_I_AM_YOUR_FATHER_ = 0; }
    bool HasFather() { return LUKE_I_AM_YOUR_FATHER_ != 0; }
    PoliceAnt* GetFather() { return LUKE_I_AM_YOUR_FATHER_; }
private:
    PoliceAnt* LUKE_I_AM_YOUR_FATHER_;
};

#endif // WORKINGANT_H
