//
// Created by sieri on 13/11/2021.
//

#include <iostream>
#include "../Utils/BasicGeometry.h"
#include <yaml.h>
#include <cmath>
#include "Face.h"
#include "Ray.h"

Ray::Ray(const Vec3 &origin, const Vec3 &direction, int pixelX, int pixelY): origin(origin), direction(direction), pixelX(pixelX), pixelY(pixelY) {

}

int Ray::getPixelX() const {
    return pixelX;
}

int Ray::getPixelY() const {
    return pixelY;
}