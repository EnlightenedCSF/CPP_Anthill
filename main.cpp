using namespace std;

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "anthill.h"


int main(int argc, char *argv[])
{
    srand(time(0));

    FILE* config = fopen("config.txt", "w");

    fprintf(config, "%i\n", 3); // queenFood
    fprintf(config, "%i\n", 2); // queen will produce 1 larva every 2 turns

    fprintf(config, "%i\n", 2); // soldierFood
    fprintf(config, "%i\n", 2); // soldierPestKillAmount

    fprintf(config, "%i\n", 2); // policeFood
    fprintf(config, "%f\n", 0.1); // policeBonus

    fprintf(config, "%i\n", 1); // workingAntFood
    fprintf(config, "%i\n", 2); // workingAntProduction

    fprintf(config, "%i\n", 3); // larvaFood
    fprintf(config, "%i\n", 3); // larvaTicksToGrow

    fprintf(config, "%i\n", 50); // foodStorageSize

    fprintf(config, "%c %i\n", 'w', 1);
    fclose(config);

    config = fopen("config.txt", "r");
    if (config == 0)
        return -1;

    Anthill* anthill = new Anthill(config);

    char command;
    do {
        anthill->Tick();
        cin >> command;
        cout << '\n';
    } while (command != 'q');

    return 0;
}
