using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "insect.h"

Insect::Insect(Anthill* anthill)
{
    anthill_ = anthill;
}

//int Insect::Tick() {
//   int prob = rand() % 100;
//   if (prob < WorldOptions::getProbToBecomePest()) {
//       anthill_->AddInsect(PEST_ANT);
//       return 1;
//    }
//    return 0;
//}
