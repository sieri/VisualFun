//
// Created by sieri on 04/11/2021.
//

#ifndef VISUALFUN_FACE_H
#define VISUALFUN_FACE_H

#include <array>
#include "Vec3.h"
#include "Ray.h"


class Face
{
public:
    Face(Vec3 a, Vec3 b, Vec3 c);
    Face(Vec3 a, Vec3 b, Vec3 c, int color);
    [[nodiscard]] Vec3 get_normal() const;

    bool intersect_with(const Ray &r);
    [[nodiscard]] double intersect_length(const Ray &r) const;
    [[nodiscard]] double intersect_angle(const Ray &r) const;
private:
    void update();

    std::array<Vec3, 3> vertices;
    double det;
    double a;
    double b;
    double c;
    double d;
    double area;
    int color;

public:
    [[nodiscard]] int getColor() const;

    double get_distance_from_camera(Vec3 position) const;

    [[nodiscard]] Vec3 get_center() const;
};




#endif //VISUALFUN_FACE_H
