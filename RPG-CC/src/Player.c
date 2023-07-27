#include "Player.h"

u16 Player_XPos = 0;
u16 Player_YPos = 0;
u16 Player_local_XPos = 0;
u16 Player_local_YPos = 0;
bool Player_Controlling = TRUE;

void Player_Start()
{
    Player_Speed = 1;
    Player_local_XPos = 152;
    Player_local_YPos = 112;
    Player_XPos = Player_local_XPos;
    Player_YPos = Player_local_YPos;
    Player_XPad = 24;
    Player_YPad = 24;
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
        if ((Player_local_XPos > (160 - Player_XPad)) && (Player_local_XPos < (160 + Player_XPad)))
        {
            VDP_drawText("IN X BOUND", 0, 1);
            if (state & BUTTON_LEFT)
            {
                VDP_drawText("LEFT PRESSED  ", 0, 3);
                Player_local_XPos -= Player_Speed;
            }
            else if (state & BUTTON_RIGHT)
            {
                VDP_drawText("RIGHT PRESSED", 0, 3);
                Player_local_XPos += Player_Speed;
            }
        } 
        else
        {
            if (Player_local_XPos < (160 - Player_XPad))
            {
                Player_local_XPos = (160 - Player_XPad);
            }
            else if (Player_local_XPos > (160 + Player_XPad))
            {
                Player_local_XPos = (160 + Player_XPad);
            }
            
            VDP_drawText("              ", 0, 1);
            if (state & BUTTON_LEFT)
            {
                WorldX -= Player_Speed;
            }
            else if (state & BUTTON_RIGHT)
            {
                WorldX += Player_Speed;
            }
        } 
        
        if ((Player_local_YPos > (120 - Player_YPad)) && (Player_local_YPos < (120 + Player_YPad)))
        {            
            VDP_drawText("IN Y BOUND", 0, 2);
            if (state == BUTTON_UP)
            {
                VDP_drawText("UP PRESSED   ", 0, 4);
                Player_local_YPos -= Player_Speed;
            }
            else if (state == BUTTON_DOWN)
            {
                VDP_drawText("DOWN PRESSED   ", 0, 4);
                Player_local_YPos += Player_Speed;
            }
        }
        else if((Player_local_YPos < (120 - Player_YPad)) && (Player_local_YPos > (120 + Player_YPad)))       
        {            
            if (Player_local_YPos < (120 - Player_YPad))
            {
                Player_local_YPos = (120 - Player_YPad);
            }
            else if (Player_local_YPos > (120 + Player_YPad))
            {
                Player_local_YPos = (120 + Player_YPad);
            }
            VDP_drawText("              ", 0, 2);
            if (state & BUTTON_UP)
            {
                WorldY += Player_Speed;
            }
            else if (state & BUTTON_DOWN)
            {
                WorldY -= Player_Speed;
            }
        }
        
        Player_XPos = Player_local_XPos;
        Player_YPos = Player_local_YPos;
        
    }else
    {
        Player_XPos = WorldX - Player_local_XPos;
        Player_YPos = -WorldY - Player_local_YPos;
    }

    SPR_setPosition(Player_Sprite,Player_XPos,Player_YPos);
}