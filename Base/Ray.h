//
// Created by sieri on 13/11/2021.
//

#ifndef VISUALFUN_RAY_H
#define VISUALFUN_RAY_H

class Ray
{
public:
    Ray(const Vec3& origin, const Vec3& direction, int pixelX, int pixelY);
    Vec3 origin;
    Vec3 direction;
    [[nodiscard]] int getPixelX() const;
    [[nodiscard]] int getPixelY() const;

private:
    int pixelX;

private:
    int pixelY;
};

#include <array>
#include "Vec3.h"

#endif //VISUALFUN_RAY_H
