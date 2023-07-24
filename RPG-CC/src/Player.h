#ifndef PLAYER_H
#define PLAYER_H

#include "Camera.h"

extern u16 Player_XPos;
extern u16 Player_YPos;
extern u16 Player_local_XPos;
extern u16 Player_local_YPos;

u8 Player_XPad;
u8 Player_YPad;
u8 Player_Speed;

extern bool Player_Controlling;

Sprite* Player_Sprite;

void Player_Start(void);
void Player_CalculatePosition(u16 state);
void Player_Update(u16 state);

#endif