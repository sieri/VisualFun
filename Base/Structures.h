//
// Created by sieri on 04/11/2021.
//

#ifndef VISUALFUN_STRUCTURES_H
#define VISUALFUN_STRUCTURES_H

#include <array>


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




#endif //VISUALFUN_STRUCTURES_H
