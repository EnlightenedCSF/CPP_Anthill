#ifndef WORKINGANT_H
#define WORKINGANT_H

#include "insect.h"

class WorkingAnt : public virtual Insect
{
public:
    WorkingAnt(Anthill*);
    void Tick();
};

#endif // WORKINGANT_H
