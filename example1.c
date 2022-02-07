//std
#include "stdlib.h"

//T20
#include "T20/T20.h"

//main
int main()
{
    T20Init(40, 60, NULL);

    T20Colors(0xFFFFFF, 0x0000FF, 0x000000);

    while(1)
    {
        char *str = T20ReadLine();
        
        if(!str) { break; }

        T20AddLine(str);

        free(str);
    }

    T20Close();

    return 0;
}

