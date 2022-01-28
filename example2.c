//std
#include "stdlib.h"
#include "unistd.h"

//stuff
#define TEDDY
#include "teddy.h"

//main
int main(void)
{
    TeddyInit(40, 80, 0x00FF00, NULL);

    while(TeddyRun())
    {
        sleep(1);

        TeddyAddLine("test");
    }

    TeddyClose();

    return 0;
}

