//std
#include "stdio.h"

//stuff
#define TEDDY
#include "teddy.h"

//main
int main()
{
    TeddyInit(40, 80, 0x00FF00, NULL);

    while(1)
    {
        char *str = TeddyReadLine();
        
        if(str==NULL) { break; }

        TeddyAddLine(str);

        free(str);
    }

    TeddyClose();

    return 0;
}

