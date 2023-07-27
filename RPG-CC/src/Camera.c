#include "Camera.h"

u16 WorldX = 0;
u16 WorldY = 0;

bool Cam_TrackingPlayer = TRUE;
bool Cam_DirectControl = FALSE;

u8 Cam_ChosenPlanes = BG_B;

void Camera_FollowTarget(int x, int y)
{

}

void Camera_SetScrollMode(u8 x,u8 y)
{
    VDP_setScrollingMode(x,y);
}

void Camera_UpdateCamera(u16 state)
{
    VDP_setHorizontalScroll(Cam_ChosenPlanes, WorldX);
    VDP_setVerticalScroll(Cam_ChosenPlanes, WorldY);
    
    if (state == BUTTON_START)
    {
        Cam_TrackingPlayer = !Cam_TrackingPlayer;
        Cam_DirectControl = !Cam_DirectControl;
    }

    if (Cam_DirectControl)
    {
        if (state & BUTTON_RIGHT)
        {
            WorldX -= 2;
        }
        else if (state & BUTTON_LEFT)
        {
            WorldX += 2;
        }

        if (state & BUTTON_DOWN)
        {
            WorldY += 2;
        }
        else if (state & BUTTON_UP)
        {
            WorldY -= 2;
        }
    }
}
