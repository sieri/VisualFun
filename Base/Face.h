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
    Vec3 get_normal();
    Vec3 get_normalised_normal();
    bool intersect_with(const Ray &r);
    [[nodiscard]] double intersect_length(const Ray &r) const;

private:
    void update();

    // std::array<Edge, 3> edges; //todo make sure it^s needed
    std::array<Vec3, 3> vertices;
    double det;
    double a;
    double b;
    double c;
    double d;

    double area;
};




#endif //VISUALFUN_FACE_H
