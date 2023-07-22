#ifndef GAME_H
#define GAME_H

#include <genesis.h>
#include <resource.h>
#include "Camera.h"

extern uint8_t SceneIndex;
extern uint32_t Frame;

void Game_Start(void);
void Game_Update(void);

#endif