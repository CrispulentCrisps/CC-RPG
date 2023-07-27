#include "UI.h"

void CreateTextBox(u8 Plane, struct UIBox box)
{

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
    VDP_fillTileMapRect(Plane,TILE_ATTR_FULL(PAL3,98,FALSE,FALSE,4),box.x+1,box.y+1,box.w,box.h);
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

void ClearTextBox(u8 Plane)
{
    VDP_fillTileMapRect(Plane,TILE_ATTR_FULL(PAL3,98,FALSE,FALSE,0),0,0,40,40);
}
