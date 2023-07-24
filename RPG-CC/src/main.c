#include "Game.h"

int main()
{
    Game_Start();
    while(1)
    {
        Frame++;
        Game_Update();
        SYS_doVBlankProcess();
    }
    return (0);
}