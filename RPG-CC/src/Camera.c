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
        if (!Cam_TrackingPlayer)
        {
                if (state == BUTTON_RIGHT)
                {
                    WorldX -= 3;
                }
                else if (state == BUTTON_LEFT)
                {
                    WorldX += 3;
                }

               if (state == BUTTON_DOWN)
                {
                    WorldY += 3;
                }
                else if (state == BUTTON_UP)
                {
                    WorldY -= 3;
                }
            else
            {
                if (state == BUTTON_RIGHT + BUTTON_DOWN)
                {
                    WorldX -= 3;
                    WorldY += 3;
                }
                else if (state == BUTTON_RIGHT + BUTTON_UP)
                {
                    WorldX -= 3;
                    WorldY -= 3;
                }
                else if (state == BUTTON_LEFT + BUTTON_DOWN)
                {
                    WorldX += 3;
                    WorldY += 3;
                }        
                else if (state == BUTTON_LEFT + BUTTON_UP)
                {
                    WorldX += 3;
                    WorldY -= 3;
                }
            }
        }
    }
}