#ifndef CAMERA_H
#define CAMERA_H

#include <genesis.h>
#include <resource.h>

extern u16 WorldX;
extern u16 WorldY;

extern bool Cam_TrackingPlayer;
extern bool Cam_DirectControl;

void FollowTarget(int x, int y);
void UpdateCamera(u16 state);

#endif