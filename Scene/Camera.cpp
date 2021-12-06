//
// Created by sieri on 04/11/2021.
//

#include <math.h>
#include "Camera.h"
#include "../Base/Vec3.h"

Camera::Camera(): position({0.0,0.0,0.0}),fov(M_PI/2),cameraToWorld({{1.0,0.0,0.0}, {0.0,1.0,0.0} ,{0.0,0.0,1.0}})
{
}

Camera::Camera(Vec3 position, double fov) : position(position), fov(fov),cameraToWorld({{1.0,0.0,0.0}, {0.0,1.0,0.0} ,{0.0,0.0,1.0}})
{
}

double Camera::getFov() const {
    return fov;
}

Vec3 Camera::getPosition() const {
    return position;
}

const Matrix Camera::getCameraToWorld() const {
    return cameraToWorld;
}
