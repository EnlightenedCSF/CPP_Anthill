#ifndef larva_H
#define larva_H

#include "insect.h"

class larva : public virtual Insect
{
public:
    larva(Anthill*);
    void Tick();
private:
    int ticksLeft_;
};

#endif // larva_H
