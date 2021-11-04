//
// Created by sieri on 04/11/2021.
//

#ifndef VISUALFUN_CAMERA_H
#define VISUALFUN_CAMERA_H

#include "Structures.h"

class Camera {
public:
    Camera(Vertex position, double fov);
    Camera();
private:
    Vertex position;

    double fov;
};


#endif //VISUALFUN_CAMERA_H
