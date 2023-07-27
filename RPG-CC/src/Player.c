#include "Player.h"

u16 Player_XPos = 0;
u16 Player_YPos = 0;
u16 Player_local_XPos = 0;
u16 Player_local_YPos = 0;
bool Player_Controlling = TRUE;

void Player_Start()
{
    Player_Speed = 2;
    Player_local_XPos = 152;
    Player_local_YPos = 112;
    Player_XPos = Player_local_XPos;
    Player_YPos = Player_local_YPos;
    Player_XPad = 24;
    Player_YPad = 24;
    PAL_setPalette(PAL0,PLAYER.palette->data, CPU);
    PAL_setColor(15, 0xffffff);
    Player_Sprite = SPR_addSprite(&PLAYER, Player_XPos, Player_YPos, TILE_ATTR(PAL0, 64, FALSE, FALSE));
    Player_Controlling = TRUE;
}

void Player_Update(u16 state)
{
    Player_CalculatePosition(state);
}

void Player_CalculatePosition(u16 state)
{
    if (Player_Controlling)
    {
        VDP_drawText("PLAYER IN CONTROL", 0, 0);
        //If within the bounds of the padding area
            if (state & BUTTON_LEFT)
            {
                if (Player_local_XPos > (160 - Player_XPad))
                {
                    Player_local_XPos -= Player_Speed;
                }
                else 
                {
                    Player_local_XPos = (160 - Player_XPad);
                    WorldX += Player_Speed;
                }
            }

            if (state & BUTTON_RIGHT)
            {
                if (Player_local_XPos < (160 + Player_XPad))
                {
                    Player_local_XPos += Player_Speed;
                }
                else 
                {
                    Player_local_XPos = (160 + Player_XPad);
                    WorldX -= Player_Speed;
                }
            }

            Player_XPos = Player_local_XPos;
    
            if (state & BUTTON_UP)
            {
                if (Player_local_YPos > (120 - Player_YPad))
                {
                    Player_local_YPos -= Player_Speed;
                }
                else 
                {
                    Player_local_YPos = (120 - Player_YPad);
                    WorldY -= Player_Speed;
                }
            }
            if (state & BUTTON_DOWN)
            {
                if (Player_local_YPos < (120 + Player_YPad))
                {
                    Player_local_YPos += Player_Speed;
                }
                else 
                {
                    Player_local_YPos = (120 + Player_YPad);
                    WorldY += Player_Speed;
                }
            }
            Player_YPos = Player_local_YPos;
    }
    else
    {
        Player_XPos = WorldX - Player_local_XPos;
        Player_YPos = -WorldY - Player_local_YPos;
    }

    SPR_setPosition(Player_Sprite,Player_XPos,Player_YPos);
}