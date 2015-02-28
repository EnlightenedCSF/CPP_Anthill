#include <stdio.h>
#include <iostream>
#include "anthill.h"
#include "caterpillar.h"
#include "workingant.h"
#include "policeant.h"
#include "queen.h"
#include "worldoptions.h"

Anthill::Anthill(FILE* file)
{
    foodSources_ = new vector<FoodSource*>;
    insects_ = new vector<Insect*>;
//    int population[ANT_TYPES_CNT] = {0,0,0};
//    population_ = population;

    int larvaFood = 3;
    fscanf(file, "%i\n", &larvaFood);
    WorldOptions::setLarvaFoodToGrow(larvaFood);

    fscanf(file, "%i\n", &foodAmount_);

    int foodStoresCnt;
    fscanf(file, "%i\n", &foodStoresCnt);

    for (int i = 0; i < foodStoresCnt; i++) {
        int distance, capacity;
        fscanf(file, "%i %i\n", &distance, &capacity);
        foodSources_->push_back(new FoodSource(distance, capacity));
    }

    insects_->push_back(new Queen(this));

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
        }
    }
}

Anthill::~Anthill()
{
    delete[] population_;

    if (insects_ != 0) {
        if (!insects_->empty())
            insects_->clear();
        delete insects_;
    }

    if (foodSources_ != 0) {
        if (!foodSources_->empty())
            foodSources_->clear();
        delete foodSources_;
    }
}

void Anthill::Tick() {
    cout << "======== ANTHILL STATISICS ========\n";
    cout << "Food storage size: " << foodAmount_ << '\n';

    cout << "Amount of caterpillars:\t" << population_[LARVA] << '\n';
    cout << "Amount of working ants:\t" << population_[WORKING_ANT] << '\n';
    cout << "Amount of police ants:\t" << population_[POLICE_ANT] << '\n';

    for (unsigned int i = 0; i < insects_->size(); i++) {
        insects_->at(i)->Tick();
    }
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
}

bool Anthill::TakeFood(int amount) {
    if (foodAmount_ >= amount) {
        foodAmount_ -= amount;
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
    case POLICE_ANT:
        insects_->push_back(new PoliceAnt(this));
        break;
    default:
        insects_->push_back(new WorkingAnt(this));
        break;
    }

    population_[antType]++;
}

void Anthill::KillInsect(Insect *insect, int antType) {
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
    }
}

int Anthill::GetAntCount(int antType) {
    return population_[antType];
}
