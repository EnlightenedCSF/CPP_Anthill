using namespace std;

#include <iostream>
#include <stdio.h>
#include "anthill.h"

int main(int argc, char *argv[])
{
    FILE* config = fopen("config.txt", "w");

    fprintf(config, "%i\n", 3);

    fprintf(config, "%i\n", 50);

    fprintf(config, "%i\n", 2);
    fprintf(config, "%i %i\n", 2, 3);
    fprintf(config, "%i %i\n", 5, 1);

    fprintf(config, "%c %i\n", 'c', 1);
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
