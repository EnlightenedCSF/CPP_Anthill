#ifndef POLICEANT_H
#define POLICEANT_H

#include "insect.h"

class PoliceAnt : public virtual Insect
{
public:
    PoliceAnt(Anthill*);
    void Tick();
};

#endif // POLICEANT_H
