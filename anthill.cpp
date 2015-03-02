#include <stdio.h>
#include <iostream>
#include <stdlib.h>

#include "anthill.h"
#include "caterpillar.h"
#include "workingant.h"
#include "policeant.h"
#include "queen.h"
#include "pestant.h"
#include "worldoptions.h"
#include "soldier.h"
#include "dayinfo.h"


Anthill::Anthill(FILE* file)
{
    day_ = 1;
    dayInfo_ = new DayInfo();
    worldOptions_ = new WorldOptions(file);

    fscanf(file, "%i\n", &foodAmount_);

    insects_ = new vector<Insect*>;
    insects_->push_back(new Queen(this));
    isQueenAlive_ = true;

    char type;
    int count;
    int code;
    while (1) {
        code = fscanf(file, "%c %i\n", &type, &count);
        if (code == EOF)
            break;

        switch(type) {
        case 'c':
            for (int i = 0; i < count; i++) {
                this->AddInsect(LARVA);
            }
            break;

        case 's':
            for (int i = 0; i < count; i++) {
                this->AddInsect(SOLDIER);
            }
            break;

        case 'w':
            for (int i = 0; i < count; i++) {
                this->AddInsect(WORKING_ANT);
            }
            break;
        case 'p':
            for (int i = 0; i < count; i++) {
                this->AddInsect(POLICE_ANT);
            }
            break;
        case 'e':
            for (int i = 0; i < count; i++) {
                this->AddInsect(PEST_ANT);
            }
            break;
        }
    }
}

Anthill::~Anthill()
{
    if (insects_ != 0) {
        if (!insects_->empty())
            insects_->clear();
        delete insects_;
    }

    delete worldOptions_;
    delete dayInfo_;
}

void Anthill::Tick() {
    for (unsigned int i = 0; i < insects_->size(); i++) {
        Insect* insect = insects_->at(i);
        insect->Tick();
    }

    cout << "============= ANTHILL STATISICS: DAY " << day_++ << " =============\n";
    cout << "Food storage size: " << foodAmount_ << "\t( " << dayInfo_->GetFoodProduced()
         << "+ ; " << dayInfo_->GetFoodConsumed() << "- )\n";

    cout << "Queen is " << (isQueenAlive_ ? "alive" : "dead") << "\n";
    cout << "Amount of caterpillars:\t" << population_[LARVA] << '\n';
    cout << "Amount of working ants:\t" << population_[WORKING_ANT] << '\n';
    cout << "Amount of soldiers:\t" << population_[SOLDIER] << '\n';
    cout << "Amount of police ants:\t" << population_[POLICE_ANT] << '\n';
    cout << "Amount of pests:\t" << population_[PEST_ANT] << '\n';

    cout << "------\n";

    cout << dayInfo_->GetPestKills() << " ants were killed by pests today\n";
    cout << dayInfo_->GetPestKilled() << " of pests were killed by soldiers\n";
    cout << dayInfo_->GetAntsDiedFromStarvation() << " of ants died because of lack of food\n";

    dayInfo_->Refresh();
}

Queen* Anthill::GetQueen() {
    for (unsigned int i = 0; i < insects_->size(); i++) {
        if (dynamic_cast<Queen*>(insects_->at(i)) != 0)
            return dynamic_cast<Queen*>(insects_->at(i));
    }
    return 0;
}

void Anthill::StoreFood(int amount) {
    this->foodAmount_ += amount;
    this->dayInfo_->ProduceFood(amount);
}

bool Anthill::TakeFood(int amount) {
    if (foodAmount_ >= amount) {
        foodAmount_ -= amount;
        this->dayInfo_->ConsumeFood(amount);
        return true;
    }
    return false;
}

int Anthill::GetFoodAmount() {
    return foodAmount_;
}

void Anthill::AddInsect(int antType) {
    switch (antType) {
    case LARVA:
        insects_->push_back(new Caterpillar(this));
        break;
    case WORKING_ANT:
        insects_->push_back(new WorkingAnt(this));
        break;
    case SOLDIER:
        insects_->push_back(new Soldier(this));
        break;
    case POLICE_ANT:
        insects_->push_back(new PoliceAnt(this));
        break;
    case PEST_ANT:
        insects_->push_back(new PestAnt(this));
        break;
    default:
        insects_->push_back(new WorkingAnt(this));
        break;
    }

    population_[antType]++;
}

void Anthill::KillInsect(Insect *insect, int antType, bool wasStarvationDeath) {
    int index = -1;
    for (unsigned int i = 0; i < insects_->size(); i++) {
        if (insect == insects_->at(i)) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        insects_->erase(insects_->begin() + index);
        population_[antType]--;
        if (wasStarvationDeath)
            dayInfo_->RegisterStarvationDeath();
    }
}

void Anthill::KillRandomInsect() {
    int index;
    int antType;
    do {
        antType = -1;
        index = rand() % (insects_->size() - 1) + 1;

        if (dynamic_cast<Caterpillar*>(insects_->at(index)) != 0)
            antType = LARVA;
        else if (dynamic_cast<WorkingAnt*>(insects_->at(index)) != 0)
            antType = WORKING_ANT;
        else if (dynamic_cast<PoliceAnt*>(insects_->at(index)) != 0)
            antType = POLICE_ANT;

    } while (antType == -1);

    insects_->erase(insects_->begin() + index);
    population_[antType]--;
    dayInfo_->RegisterKillByPest();
}

void Anthill::KillPest() {
    if (population_[PEST_ANT] == 0)
        return;

    int index = -1;
    for (unsigned int i = 0; i < insects_->size(); i++) {
        if (dynamic_cast<PestAnt*>(insects_->at(i)) != 0) {
            index = i;
            break;
        }
    }

    insects_->erase(insects_->begin() + index);
    population_[PEST_ANT]--;
    dayInfo_->RegisterPestKilled();
}

void Anthill::KillQueen() {
    insects_->erase(insects_->begin());
    isQueenAlive_ = false;
}

int Anthill::GetAntCount(int antType) {
    return population_[antType];
}

int Anthill::GetAntCount() {
    return insects_->size() - 1;
}
