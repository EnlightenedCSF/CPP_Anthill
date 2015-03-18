#include <string>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <math.h>

#include "anthill.h"
#include "caterpillar.h"
#include "workingant.h"
#include "policeant.h"
#include "queen.h"
#include "pestant.h"
#include "insect.h"
#include "worldoptions.h"
#include "soldier.h"
#include "dayinfo.h"

using namespace std;

Anthill::Anthill(FILE* file)
{
    day_ = 1;
    dayInfo_ = new DayInfo();
    worldOptions_ = new WorldOptions(file);
    randSumToSpawnPest_ = 3.497;

    int temp;
    fscanf(file, "%i\n", &temp);
    foodAmount_ = (double) temp;

    insects_ = new vector<Insect*>;
    insects_->push_back(new Queen(this));
    isQueenAlive_ = true;

    /*char type;
    int count;
    int code;
    while (1) {
        code = fscanf(file, "%c %i\n", &type, &count);
        if (code == EOF)
            break;

        switch(type) {
        case 'l':
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
    }*/
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

vector<string> &Anthill::Split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

void Anthill::InputAntTypes() {
    string command;

    cout << "=== Types of ants: ===\n";
    cout << "[l] Larva\n[w] Working ant\n[p] Police ant\n[s] Soldier\n[e] Pest ant\n";
    cout << "----------\nInput pattern: \"<char-type><space><amount>\", for example: \"w 3\"\n[q] For exit\n\n";

    do {
        getline(cin, command);

        if (command.compare("q") == 0)
            break;

        vector<string> tokens;
        tokens = Split(command, ' ', tokens);
        int count;
        if (tokens.size() != 2) {
            cout << "Error!\n";
            continue;
        }
        try {
            count = atoi(tokens[1].c_str());

            switch (tokens[0][0]) {
            case 'w':
            case 'W':
                for (int i = 0; i < count; i++) {
                    AddInsect(WORKING_ANT);
                }
                break;
            case 's':
            case 'S':
                for (int i = 0; i < count; i++) {
                    AddInsect(SOLDIER);
                }
                break;
            case 'p':
            case 'P':
                for (int i = 0; i < count; i++) {
                    AddInsect(POLICE_ANT);
                }
                break;
            case 'l':
            case 'L':
                for (int i = 0; i < count; i++) {
                    AddInsect(LARVA);
                }
                break;
            case 'e':
            case 'E':
                for (int i = 0; i < count; i++) {
                    AddInsect(PEST_ANT);
                }
                break;
            default:
                break;
            }

            cout << "Added!\n";
        }
        catch (...) {
            cout << "Error!\n";
            continue;
        }

    } while (1);
}

void Anthill::Tick() {
    if (day_ != 1) {

        randSumToSpawnPest_ += ((float) rand() / (RAND_MAX));
        if (randSumToSpawnPest_ > WorldOptions::getDaysToSpawnPest()) {
            AddInsect(PEST_ANT);
            randSumToSpawnPest_ -= WorldOptions::getDaysToSpawnPest();
        }

        for (unsigned int i = 0; i < insects_->size(); i++) {
            Insect* insect = insects_->at(i);
            insect->Tick();
        }
    }

    cout << "\033[2J\033[1;1H"; //clear screen

    cout << "============= ANTHILL STATISICS: DAY " << day_++ << " =============\n";
    cout << "Food storage size: " << foodAmount_ << "\t( " << dayInfo_->GetFoodProduced()
         << "+ ; " << dayInfo_->GetFoodConsumed() << "- )\n";

    cout << "Queen is " << (isQueenAlive_ ? "alive" : "dead") << "\n";
    cout << "Amount of larvas:\t" << population_[LARVA] << '\n';
    cout << "Amount of working ants:\t" << population_[WORKING_ANT]
            << "\t Under control: " << GetAntUnderControlCount() << '\n';
    cout << "Amount of soldiers:\t" << population_[SOLDIER] << '\n';
    cout << "Amount of police ants:\t" << population_[POLICE_ANT] << '\n';
    cout << "Amount of pests:\t" << population_[PEST_ANT] << '\n';

    cout << "------\n";

    cout << dayInfo_->GetPestKills() << " ants were killed by pests today\n";
    cout << dayInfo_->GetPestKilled() << " of pests were killed by soldiers\n";
    cout << dayInfo_->GetAntsDiedFromStarvation() << " of ants died because of lack of food\n";

    dayInfo_->Refresh();
}

int Anthill::GetAntUnderControlCount() {
    int result = 0;
    for (unsigned int i = 0; i < insects_->size(); i++) {
        WorkingAnt* ant = dynamic_cast<WorkingAnt*>(insects_->at(i));
        if (ant && ant->HasTaskMaster()) {
            result++;
        }
    }
    return result;
}

Queen* Anthill::GetQueen() { // TODO
    for (unsigned int i = 0; i < insects_->size(); i++) {
        if (dynamic_cast<Queen*>(insects_->at(i)) != 0)
            return dynamic_cast<Queen*>(insects_->at(i));
    }
    return 0;
}

void Anthill::StoreFood(double amount) {
    this->foodAmount_ += amount;
    this->dayInfo_->ProduceFood(amount);
}

bool Anthill::TakeFood(double amount) {
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
    PoliceAnt* newOfficer;

    switch (antType) {
    case LARVA:
        insects_->push_back(new larva(this));
        break;
    case WORKING_ANT:
        insects_->push_back(new WorkingAnt(this));
        break;
    case POLICE_ANT:
        newOfficer = new PoliceAnt(this);
        for (unsigned int i = 0; i < insects_->size(); i++) {
            if (newOfficer->GetControlledAntsCount() >= WorldOptions::getPoliceWorkers())
                break;

            WorkingAnt* ant = dynamic_cast<WorkingAnt*>(insects_->at(i));
            if (ant != 0 && !ant->HasTaskMaster()) {
                ant->FindTaskMaster(newOfficer);
                newOfficer->TakeAnotherAntUnderControl();
            }
        }

        insects_->push_back(new PoliceAnt(this));
        break;
    case PEST_ANT:
        insects_->push_back(new PestAnt(this));
        break;
    case SOLDIER:
        insects_->push_back(new Soldier(this));
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
        WorkingAnt* ant = dynamic_cast<WorkingAnt*>(insects_->at(index));
        if (ant != 0) {
            ant->GetTaskMaster()->LostAntUnderControl();
        }
        else {
            PoliceAnt* pAnt = dynamic_cast<PoliceAnt*>(insects_->at(index));
            if (pAnt != 0) {
                for (unsigned int j = 0; j < insects_->size(); j++){
                    ant = dynamic_cast<WorkingAnt*>(insects_->at(j));
                    if (ant != 0 && ant->GetTaskMaster() == pAnt) {
                        ant->LoseTaskMaster();
                    }
                }
            }
        }

        insects_->erase(insects_->begin() + index);
        population_[antType]--;
        if (wasStarvationDeath)
            dayInfo_->RegisterStarvationDeath();
    }
}

bool Anthill::FightWithRandomAnt(PestAnt *pest) {
    int cnt = 0;
    for (int  i = 0; i < ANT_TYPES_CNT; i++) {
        cnt += population_[i];
    }
    if (cnt == 0)
        return true;

    int index;
    bool isTargetDead = false;
    int antType = -1;

    do {
        index = rand() % (insects_->size() - 1) + 1;

        PestAnt* p = dynamic_cast<PestAnt*>(insects_->at(index));
        if (p == 0) {
            if (insects_->at(index)->InflictDamage())
                isTargetDead = true;

            if (dynamic_cast<WorkingAnt*>(insects_->at(index)))
                antType = WORKING_ANT;
            else if (dynamic_cast<Soldier*>(insects_->at(index)))
                antType = SOLDIER;
            else if (dynamic_cast<larva*>(insects_->at(index)))
                antType = LARVA;
            else if (dynamic_cast<PoliceAnt*>(insects_->at(index)))
                antType = POLICE_ANT;

            break;
        }
    } while (antType == -1);

    if (isTargetDead) {
        KillInsect(insects_->at(index), antType, false);
    }

    return !pest->InflictDamage();
}

bool Anthill::FightPest(Soldier *soldier) {
    int index = -1;
    for (unsigned int i = 0; i < insects_->size(); i++) {
        PestAnt* pest = dynamic_cast<PestAnt*>(insects_->at(i));
        if (pest != 0) {
            if (pest->InflictDamage()) {
                index = i;
            }
            break;
        }
    }
    if (index != -1) {
        insects_->erase(insects_->begin() + index);
        population_[PEST_ANT]--;
    }

    return !soldier->InflictDamage();
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
