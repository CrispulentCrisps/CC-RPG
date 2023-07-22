#include "Game.h"

int main()
{
    VDP_setScrollingMode(4, 0);
    Game_Start();
    while(1)
    {   
        VDP_setHorizontalScroll(BG_B, (Frame/8)%8);
        Frame++;
        SYS_doVBlankProcess();
        Game_Update();
    }
    return (0);
}