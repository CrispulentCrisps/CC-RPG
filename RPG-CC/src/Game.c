#include "Game.h"

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
    char* StoredText;
    char* DisplayText;
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
    VDP_fillTileMapRect(Plane+1 ,TILE_ATTR_FULL(PAL3,99,FALSE,FALSE,4),box.x,box.y+1,box.w+1,box.h);
    int xind = 0;
    int yind = 0;
    for (char i = 0; i < sizeof(box.StoredText); i++)
    {
        VDP_drawText(box.StoredText[i], box.x+xind+2, box.y+yind+2);
        xind++;
        if (xind >= box.w-4)
        {
            xind = 0;
            yind++;
        }    
    }
}

void Game_Start(){
    //This assumes we start at the title
    VDP_setTextPlane(BG_A);
    VDP_loadTileSet(UISET.tileset,1,CPU);
    PAL_setPalette(PAL3,UISET.palette->data, CPU);
    VDP_loadTileSet(TITLESET.tileset,7,CPU);
    PAL_setPalette(PAL1,TITLESET.palette->data, CPU);
    VDP_fillTileMapRect(BG_B,TILE_ATTR_FULL(PAL1,0,FALSE,FALSE,7),0,0,64,64);
    struct UIBox MainBox;
    MainBox.x = 7;
    MainBox.y = 5;
    MainBox.w = 24;
    MainBox.h = 16;
    const char* t = "Hello guys it is crisps. Did you know that this text box can actually work???? crazy right!?";
    MainBox.StoredText = t;
    RenderTextBox(BG_A, MainBox);
}

void Game_Update(){

}
