//
// Created by sieri on 04/11/2021.
//

#ifndef VISUALFUN_STRUCTURES_H
#define VISUALFUN_STRUCTURES_H

#include <array>

struct Vertex
{
    double x;
    double y;
    double z;
    //potentially quaternion for rotation
};

using Edge = std::array<Vertex, 2>;

class Vec3
{
public:
    Vec3();
    explicit Vec3(const std::array<double, 3>& values);
    std::array<double, 3> values;
    double norm();
    Vec3 divide(double divider);

};

struct Ray
{
    Vertex origin{};
    Vec3 direction;
};

class Face
{
public:
    Face(Vertex a, Vertex b, Vertex c);
    Vec3 get_normal();
    Vec3 get_normalised_normal();
    bool intersect_with(Ray r);
    double intersectLength(Ray r);

private:
    void update();

    // std::array<Edge, 3> edges; //todo make sure it^s needed
    std::array<Vertex, 3> vertices;
    double det;
    double a;
    double b;
    double c;
    double d;
};




#endif //VISUALFUN_STRUCTURES_H
