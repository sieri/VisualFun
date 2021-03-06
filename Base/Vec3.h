//
// Created by sieri on 13/11/2021.
//

#ifndef VISUALFUN_VEC3_H
#define VISUALFUN_VEC3_H

#include <iostream>
#include <array>

class Vec3
{
public:
    Vec3();
    explicit Vec3(const std::array<double, 3>& values);

    double norm() const;
    Vec3 normalize() const;
    Vec3 operator+(const Vec3& vec) const;
    Vec3 operator-(const Vec3& vec) const;
    Vec3 operator*(const Vec3& vec) const;
    double dot(const Vec3& vec) const;
    Vec3 divide(double divider) const;
    Vec3 rotateX(double theta) const;
    Vec3 rotateY(double theta) const;
    Vec3 rotateZ(double theta) const;
    [[nodiscard]] double x() const;
    [[nodiscard]] double y() const;
    [[nodiscard]] double z() const;

    Vec3 rotate(double alpha, double beta, double theta) const;

    friend std::ostream& operator<<(std::ostream& os, Vec3 const & tc) {
        return os << "Vec:" << tc.x() << " : " << tc.y() << " : " <<tc.z() << std::endl;
    }

    const std::array<double, 3> &getValues() const;

private:
    std::array<double, 3> values;


};

#include <array>

#endif //VISUALFUN_VEC3_H
