#include "Player.h"

u16 Player_XPos;
u16 Player_YPos;
u16 Player_local_XPos;
u16 Player_local_YPos;
bool Player_Controlling;

void Player_Start()
{
    Player_local_XPos = 152;
    Player_local_YPos = 112;
    Player_XPad = 48;
    Player_YPad = 48;
    Player_Sprite = SPR_addSprite(&PLAYER, Player_local_XPos, Player_local_YPos, TILE_ATTR(PAL0, 64, FALSE, FALSE));
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
        //If within the bounds of the padding area
        if (Player_local_XPos > 160 - Player_XPad && Player_local_XPos < 160 + Player_XPad)
        {
            if (state == BUTTON_LEFT)
            {
                Player_local_XPos -= Player_Speed;
            }
            else if (state == BUTTON_RIGHT)
            {
                Player_local_XPos += Player_Speed;
            }
            Player_XPos = Player_local_XPos;
        } 
        else if (Player_local_YPos < 120 - Player_YPad && Player_local_YPos > 120 + Player_YPad)
        {            
            if (state == BUTTON_UP)
            {
                Player_local_YPos += Player_Speed;
            }
            else if (state == BUTTON_DOWN)
            {
                Player_local_YPos -= Player_Speed;
            }
            Player_YPos = Player_local_YPos;
        }
        
    }else
    {
        Player_XPos = WorldX - Player_local_XPos;
        Player_YPos = -WorldY - Player_local_YPos;
    }
    
    SPR_setPosition(Player_Sprite,Player_XPos,Player_YPos);
}