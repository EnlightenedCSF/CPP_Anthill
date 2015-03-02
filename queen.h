#ifndef QUEEN_H
#define QUEEN_H

#include "insect.h"

class Queen : public virtual Insect
{
public:
    Queen(Anthill*);
    void Tick();

    void EvolveLarva();

private:
    int ticksToMakeLarva_;
};

#endif // QUEEN_H
