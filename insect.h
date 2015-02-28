#ifndef INSECT_H
#define INSECT_H

#include "anthill.h"

class Anthill;

//abstract
class Insect
{
public:
    Insect(Anthill*);
    virtual void Tick() = 0;
protected:
    static int consumedFood_;
    Anthill* anthill_;
};

#endif // INSECT_H
