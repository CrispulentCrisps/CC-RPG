#include "Player.h"

u16 Player_XPos;
u16 Player_YPos;
u16 Player_local_XPos;
u16 Player_local_YPos;

void Player_Start()
{
    Player_local_XPos = 0;
    Player_local_YPos = 0;
    Player_Sprite = SPR_addSprite(&PLAYER, Player_local_XPos, Player_local_YPos, TILE_ATTR(PAL0, 64, FALSE, FALSE));
}

void Player_Update()
{
    Player_CalculatePosition();
}

void Player_CalculatePosition()
{
    if (Cam_DirectControl)
    {

    }else
    {
        Player_XPos = WorldX - Player_local_XPos;
        Player_YPos = WorldY - Player_local_YPos;
    }
    SPR_setPosition(Player_Sprite,Player_XPos,-Player_YPos);
}