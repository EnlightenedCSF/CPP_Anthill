#ifndef PESTANT_H
#define PESTANT_H

#include "insect.h"

class PestAnt : public virtual Insect
{
public:
    PestAnt(Anthill*);
    void Tick();
};

#endif // PESTANT_H
