#ifndef CAMERA_H
#define CAMERA_H

#include <genesis.h>

extern uint16_t WorldX;
extern uint16_t WorldY;

extern bool TrackingPlayer;

void FollowTarget(int x, int y);
void UpdateCamera(void);

#endif