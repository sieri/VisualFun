//
// Created by sieri on 04/11/2021.
//

#ifndef VISUALFUN_CAMERA_H
#define VISUALFUN_CAMERA_H

#include "../Base/Face.h"
#include "../Base/Vec3.h"
#include "../Base/Matrix.h"

class Camera {
public:
    Camera(Vec3 position, double fov);
    Camera();
    [[nodiscard]] double getFov() const;
    [[nodiscard]] Vec3 getPosition() const;

private:
    Vec3 position;
    double fov;
    Matrix cameraToWorld;
public:
    const Matrix getCameraToWorld() const;
};


#endif //VISUALFUN_CAMERA_H
