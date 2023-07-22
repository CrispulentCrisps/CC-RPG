#include "Game.h"
#include <string.h>
enum GAME_STATE {
    MAP,
    CUTSCENE,
    BATTLE,
    NON
};

enum SCENE_LIST {
    TITLE
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
};

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
    VDP_fillTileMapRect(Plane ,TILE_ATTR_FULL(PAL3,98,FALSE,FALSE,4),box.x+1,box.y+1,box.w,box.h);
    int xind = 0;
    int yind = 0;
    char tex[30];
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
    PAL_setColor(15, RGB24_TO_VDPCOLOR(0xCCCCFF));
    PAL_setColor(13, RGB24_TO_VDPCOLOR(0x000000));
    struct UIBox MainBox;
    MainBox.x = 7;
    MainBox.y = 5;
    MainBox.w = 24;
    MainBox.h = 16;
    const char* t = "Holy fucking shit it's the megadrive";
    MainBox.StoredText = t;
    RenderTextBox(BG_A, MainBox);
}

void Game_Update(){
    UpdateCamera();
}
