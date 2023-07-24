#ifndef PLAYER_H
#define PLAYER_H
#include "Camera.h"

extern u16 Player_XPos;
extern u16 Player_YPos;
extern u16 Player_local_XPos;
extern u16 Player_local_YPos;

extern bool Player_Controlling;

Sprite* Player_Sprite;

void Player_Start(void);
void Player_CalculatePosition(void);
void Player_Update(void);

#endif