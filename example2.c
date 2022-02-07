//std
#include "unistd.h"

//T20
#include "T20/T20.h"

//main
int main(void)
{
    T20Init(40, 80, 0);

    T20Colors(0xFFFFFF, 0x0000FF, 0x000000);

    while(T20Run())
    {
        sleep(1);

        T20AddLine("test");
    }

    T20Close();

    return 0;
}

