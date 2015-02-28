#ifndef CATERPILLAR_H
#define CATERPILLAR_H

#include "insect.h"

class Caterpillar : public virtual Insect
{
public:
    Caterpillar(Anthill*);
    void Tick();
private:
    int foodLeft_;
};

#endif // CATERPILLAR_H
