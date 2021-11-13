//
// Created by sieri on 13/11/2021.
//

#ifndef VISUALFUN_VEC3_H
#define VISUALFUN_VEC3_H

class Vec3
{
public:
    Vec3();
    explicit Vec3(const std::array<double, 3>& values);
    std::array<double, 3> values;
    double norm();
    Vec3 operator+(const Vec3& vec);
    Vec3 operator-(const Vec3& vec);
    double dot(const Vec3& vec);
    Vec3 divide(double divider);
    Vec3 rotateX(double theta);
    Vec3 rotateY(double theta);
    Vec3 rotateZ(double theta);
    [[nodiscard]] double x() const;
    [[nodiscard]] double y() const;
    [[nodiscard]] double z() const;

    Vec3 rotate(double alpha, double beta, double theta);
};

#include <array>

#endif //VISUALFUN_VEC3_H
