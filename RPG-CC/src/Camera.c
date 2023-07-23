#include "Camera.h"

void FollowTarget(int x, int y){

}
void UpdateCamera(u16 state){
    if (Cam_TrackingPlayer)
    {
        if (state == BUTTON_RIGHT && WorldX < 1024)
        {
            WorldX++;
        }
        else if (state == BUTTON_LEFT && WorldX > 0)
        {
            WorldX--;
        }
        
        if (state == BUTTON_DOWN && WorldY < 1024)
        {
            WorldY++;
        }
        else if (state == BUTTON_UP && WorldY > 0)
        {
            WorldY--;
        }
        
    }else
    {

    }
    
}