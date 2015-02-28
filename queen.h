#ifndef QUEEN_H
#define QUEEN_H

#include "insect.h"

class Queen : public virtual Insect
{
public:
    Queen(Anthill*);
    void Tick();

    void EvolveLarva();
};

#endif // QUEEN_H
