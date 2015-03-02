#ifndef SOLDIER_H
#define SOLDIER_H

#include "anthill.h"
#include "insect.h"

class Soldier : public virtual Insect
{
public:
    Soldier(Anthill*);
    void Tick();
};

#endif // SOLDIER_H
