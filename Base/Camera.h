//
// Created by sieri on 04/11/2021.
//

#ifndef VISUALFUN_CAMERA_H
#define VISUALFUN_CAMERA_H

#include "Face.h"
#include "Vec3.h"

class Camera {
public:
    Camera(Vec3 position, double fov);
    Camera();
    [[nodiscard]] double getFov() const;
    [[nodiscard]] Vec3 getPosition() const;
private:
    Vec3 position;

    double fov;
};


#endif //VISUALFUN_CAMERA_H
