#ifndef CAMERA_H
#define CAMERA_H

#include <genesis.h>
#include <resource.h>

extern u16 WorldX;
extern u16 WorldY;

extern bool Cam_TrackingPlayer;
extern bool Cam_DirectControl;

extern u8 Cam_ChosenPlanes;

void Camera_FollowTarget(int x, int y);
void Camera_UpdateCamera(u16 state);
void Camera_SetScrollMode(u8 x,u8 y);

#endif