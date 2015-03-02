#ifndef CATERPILLAR_H
#define CATERPILLAR_H

#include "insect.h"

class Caterpillar : public virtual Insect
{
public:
    Caterpillar(Anthill*);
    void Tick();
private:
    int ticksLeft_;
};

#endif // CATERPILLAR_H
