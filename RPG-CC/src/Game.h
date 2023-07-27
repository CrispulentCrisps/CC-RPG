#ifndef GAME_H
#define GAME_H

#include "Player.h"

extern bool DEBUG;

extern u8 SceneIndex;
extern u32 Frame;

extern u16 Joy_1_State;
extern u16 Joy_2_State;

enum GAME_STATE {
    MAP,
    CUTSCENE,
    BATTLE,
    NON
};

enum SCENE_LIST {
    TITLE,

};

struct UIBox{
    int x;
    int y;
    int w;
    int h;
    const char* StoredText;
    const char* DisplayText;
};

struct Scene {
    Sprite sprites[80];
    struct UIBox boxes[8];
};

extern struct Scene scenes[2];

void Game_Start(void);
void Game_Update(void);
void Game_DEBUG_CALL(void);
#endif