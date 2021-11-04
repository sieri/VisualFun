//
// Created by sieri on 04/11/2021.
//
#include "Structures.h"
#include <cmath>

Face::Face(Vertex a, Vertex b, Vertex c) {
    vertices = {a,b,c};
    update();
}

Vec3 Face::get_normal() {
    return Vec3({a,b,c});
}

Vec3 Face::get_normalised_normal() {
    Vec3 normal = get_normal();
    return normal.divide(normal.norm());
}

bool Face::intersect_with(Ray r) {
    return false; //TODO: Implement
}

double Face::intersectLength(Ray r) {
    return 0; //TODO: Implement
}

void Face::update() {
    Vertex A = vertices[0];
    Vertex B = vertices[1];
    Vertex C = vertices[2];

    a = (B.y-A.y)*(C.z-A.z)-(C.y-A.y)*(B.z-A.z);
    b = (B.z-A.z)*(C.x-A.x)-(C.z-A.z)*(B.x-A.x);
    c = (B.x-A.x)*(C.y-A.y)-(C.x-A.x)*(B.y-A.y);
    d = -(a*A.x+b*A.y+c*A.z);
}

Vec3::Vec3(const std::array<double, 3>& values):values(values){

}

double Vec3::norm() {
    return sqrt(values[0] * values[0]+ values[1] * values[1] +values[2]*values[2]);
}

Vec3 Vec3::divide(double divider) {
    Vec3 result;
    for (int i = 0; i < 3; ++i) {
        result.values[i] = this->values[i]/divider;
    }
    return result;
}

Vec3::Vec3() : values({0,0,0}){

}
