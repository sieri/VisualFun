//
// Created by sieri on 04/11/2021.
//

#include "Camera.h"

Camera::Camera(): position({0.0,0.0,0.0}),fov(90.0)
{
}

Camera::Camera(Vertex position, double fov) : position(position), fov(fov)
{
}
