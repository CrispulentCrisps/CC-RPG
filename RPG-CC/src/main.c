#include "Game.h"

int main()
{
    Game_Start();
    while(1)
    {
        Frame++;
        SYS_doVBlankProcess();
        Game_Update();
    }
    return (0);
}