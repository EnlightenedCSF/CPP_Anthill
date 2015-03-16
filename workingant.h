#ifndef WORKINGANT_H
#define WORKINGANT_H

#include "insect.h"
#include "policeant.h"

class WorkingAnt : public virtual Insect
{
public:
    WorkingAnt(Anthill*);
    void Tick();

    void FindTaskMaster(PoliceAnt* taskMaster) { taskMaster_ = taskMaster; }
    void LoseTaskMaster() { taskMaster_ = 0; }
    bool HasTaskMaster() { return taskMaster_ != 0; }
    PoliceAnt* GetTaskMaster() { return taskMaster_; }
private:
    PoliceAnt* taskMaster_;
};

#endif // WORKINGANT_H
