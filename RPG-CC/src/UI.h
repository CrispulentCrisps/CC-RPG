#ifndef UI_H
#define UI_H

#include <genesis.h>
#include <resource.h>

struct UIBox{
    int x;
    int y;
    int w;
    int h;
    const char* StoredText;
    const char* DisplayText;
};

void CreateTextBox(u8 Plane, struct UIBox box);
void RenderTextBox(u8 Plane, struct UIBox box);
void ClearTextBox(u8 Plane);
#endif