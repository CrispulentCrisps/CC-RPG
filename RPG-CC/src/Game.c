#include "Game.h"

enum GAME_STATE {
    MAP,
    CUTSCENE,
    BATTLE,
    NON
};

enum SCENE {
    TITLE
};

struct UIBox{
    int x;
    int y;
    int w;
    int h;
    char StoredText[128];
    char DisplayText[128];
};

void Game_Start(){
    //This assumes we start at the title
    VDP_loadTileSet(TITLESET.tileset,0,CPU);
    PAL_setPalette(PAL1,TITLESET.palette->data, CPU);
    VDP_loadTileSet(UISET.tileset,1,CPU);
    PAL_setPalette(PAL3,UISET.palette->data, CPU);
    VDP_fillTileMapRect(BG_B,TILE_ATTR_FULL(PAL1,0,FALSE,FALSE,0),0,0,64,64);
    struct UIBox MainBox;
    MainBox.x = 8;
    MainBox.y = 8;
    VDP_fillTileMapRect(BG_A,TILE_ATTR_FULL(PAL3,64,FALSE,FALSE,0),0,0,64,64);
}
