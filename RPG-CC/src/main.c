#include "Game.h"

int main()
{
    Game_Start();
    while(1)
    {   
        SYS_doVBlankProcess();
    }
    return (0);
}