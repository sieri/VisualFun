//
// Created by sieri on 04/11/2021.
//

#include <cmath>
#include "Camera.h"

Camera::Camera(): position({0.0,0.0,0.0}),fov(M_PI/2)
{
}

Camera::Camera(Vec3 position, double fov) : position(position), fov(fov)
{
}

double Camera::getFov() const {
    return fov;
}

Vec3 Camera::getPosition() const {
    return position;
}
