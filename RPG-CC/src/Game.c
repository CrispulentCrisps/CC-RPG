#include "Game.h"

u8 SceneIndex = 0;
u32 Frame = 0;

u16 Joy_1_State = 0;
u16 Joy_2_State = 0;

struct Scene scenes[2];

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

void RenderTextBox(u8 Plane, struct UIBox box){
    //Top and bottom bars
    VDP_fillTileMapRect(Plane,TILE_ATTR_FULL(PAL3,99,FALSE,FALSE,2),box.x+1,box.y,box.w,1);
    VDP_fillTileMapRect(Plane,TILE_ATTR_FULL(PAL3,99,TRUE,TRUE,2),box.x+1,box.y+box.h+1,box.w,1);

    //Side bars
    VDP_fillTileMapRect(Plane,TILE_ATTR_FULL(PAL3,99,TRUE,FALSE,3),box.x,box.y+1,1,box.h);
    VDP_fillTileMapRect(Plane,TILE_ATTR_FULL(PAL3,99,FALSE,TRUE,3),box.x+box.w+1,box.y+1,1,box.h);

    //Corner Pieces
    VDP_setTileMapXY(Plane, TILE_ATTR_FULL(PAL3,99,FALSE,FALSE,1), box.x, box.y);
    VDP_setTileMapXY(Plane, TILE_ATTR_FULL(PAL3,99,FALSE,TRUE,1), box.x+box.w+1, box.y);
    VDP_setTileMapXY(Plane, TILE_ATTR_FULL(PAL3,99,TRUE,TRUE,1), box.x+box.w+1, box.y+box.h+1);
    VDP_setTileMapXY(Plane, TILE_ATTR_FULL(PAL3,99,TRUE,FALSE,1), box.x, box.y+box.h+1);

    //Inside Text
    VDP_fillTileMapRect(Plane+1,TILE_ATTR_FULL(PAL3,98,FALSE,FALSE,4),box.x+1,box.y+1,box.w,box.h);
    int xind = 0;
    int yind = 0;
    char tex[128];
    for (char i = 0; box.StoredText[i]; i++)
    {
        tex[xind] = box.StoredText[i];
        xind++;
        if (xind >= box.w-4) {
            while (xind > 0 && tex[xind-1] != ' ') {
                xind--;
                i--;
            }
            tex[xind] = 0;
            VDP_drawText(tex, box.x + 2, box.y + 2 + yind);
            xind = 0;
            yind++;
        }
    }
    if (xind > 0) {
        tex[xind] = 0;
        VDP_drawText(tex, box.x + 2, box.y + 2 + yind);
    }
}

void Game_Start(){ 
    //This assumes we start at the title
    VDP_loadTileSet(UISET.tileset,1,CPU);
    PAL_setPalette(PAL3,UISET.palette->data, CPU);
    VDP_loadTileSet(TITLESET.tileset,7,CPU);
    PAL_setPalette(PAL1,TITLESET.palette->data, CPU);
    VDP_fillTileMapRect(BG_B,TILE_ATTR_FULL(PAL1,0,FALSE,FALSE,7),0,0,64,64);
    
    VDP_setTextPlane(BG_A);
    VDP_setTextPriority(1);
    
    struct UIBox MainBox;
    MainBox.x = 3;
    MainBox.y = 5;
    MainBox.w = 32;
    MainBox.h = 12;
    const char* t = "Hello Geometric Entities! :D";
    MainBox.StoredText = t;
    RenderTextBox(BG_A, MainBox);
    scenes[0].boxes[0] = MainBox;
    
   JOY_init();
   JOY_setEventHandler( &myJoyHandler );
   Cam_DirectControl = TRUE;
   Camera_SetScrollMode(0,0);
    
    SPR_init();
    Player_Start();
}

void Game_Update(){
    Camera_UpdateCamera(Joy_1_State);
    Player_Update(Joy_1_State);
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
