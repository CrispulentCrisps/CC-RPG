#include "Game.h"

u8 SceneIndex = 0;
u32 Frame = 0;

u16 Joy_1_State = 0;
u16 Joy_2_State = 0;

struct Scene scenes[2];

bool DEBUG = TRUE;

void myJoyHandler( u16 joy, u16 changed, u16 state)
{
    if (joy == JOY_1)
    {
        Joy_1_State = state;
    }
    else if (joy == JOY_2)
    {
        Joy_2_State = state;
    }
}

void Game_Start(){ 
    //This assumes we start at the title
    VDP_loadTileSet(UISET.tileset,1,CPU);
    PAL_setPalette(PAL3,UISET.palette->data, CPU);
    VDP_loadTileSet(TITLESET.tileset,7,CPU);
    PAL_setPalette(PAL1,TITLESET.palette->data, CPU);
    VDP_fillTileMapRect(BG_B,TILE_ATTR_FULL(PAL1,0,FALSE,FALSE,7),0,0,64,64);

    VDP_loadFont(&FONT, CPU);
    VDP_setTextPlane(BG_A);
    VDP_setTextPriority(1);

    struct UIBox MainBox;
    MainBox.x = 3;
    MainBox.y = 5;
    MainBox.w = 32;
    MainBox.h = 12;
    const char* t = "Hello Megadrive";
    MainBox.StoredText = t;
    scenes[0].boxes[0] = MainBox;
    RenderTextBox(BG_A, MainBox);
    
    JOY_init();
    JOY_setEventHandler(&myJoyHandler);
    Camera_SetScrollMode(0,0);
    
    SPR_init();
    Player_Start();
}

void Game_Update(){
    Camera_UpdateCamera(Joy_1_State);
    Player_Update(Joy_1_State);
    if (DEBUG)
    {
        Game_DEBUG_CALL();
    }
    
    SPR_update();
}

void ChangeScene(uint8_t index){
    SPR_reset();

    switch (index)
    {
    case TITLE:
        Game_Start();
        break;
    default:
        break;
    }
}

void Game_DEBUG_CALL()
{

}